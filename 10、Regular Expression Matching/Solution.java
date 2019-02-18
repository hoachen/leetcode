import com.sun.org.apache.xalan.internal.xsltc.compiler.Pattern;

import com.sun.corba.se.spi.orbutil.fsm.Guard.Result;

public class Solution {

    /**
     * 递归解法
     */
    public boolean isMatch(String s, String p) {
        if (p.isEmpty()) {
            return s.isEmpty();
        }
        boolean firstCharMatch = !s.isEmpty() && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.');

        if (p.length() > 1 && p.charAt(1) == '*') {
            return (isMatch(s, p.substring(2)) ||
                    (firstCharMatch && isMatch(s.substring(1), p)));
        } else {
            return firstCharMatch && isMatch(s.substring(1), p.substring(1));
        }
    }



    enum Result {
        TRUE, FALSE;
    }

    private Result[][] result; 

    /**
     * 动态规划
     */
    public boolean isMatch2(String t, String p) {
        result = new Result[t.length()+1][p.length()+1];
        return dp(0, 0, t, p);
    }

    public boolean dp(int i , int j , String text, String pattern) {
        if (result[i][j] != null) {
            return result[i][j] == Result.TRUE;
        }

        boolean r = false;
        // 最后一个了
        if (j == pattern.length()) {
            r = i == text.length();
        } else {
            boolean firstMatch = i < text.length() && (text.charAt(i) == pattern.charAt(j) || pattern.charAt(j) == '.');

            if (j + 1 < pattern.length() && pattern.charAt(j+1) == '*') {
                r = dp(i, j+2, text, pattern) || firstMatch && dp(i+1, j, text, pattern); 
            } else {
                r = firstMatch && dp(i+1, j+1, text, pattern);
            }
        }
        result[i][j] = r ? Result.TRUE : Result.FALSE;
        return r;
    }

    /**
     * 动态规划
     */

    public boolean isMatch3(String t, String p) {
        // dp[i][j] 是t[i:] p[j:]
        boolean dp[][] = new boolean[t.length()+1][p.length()+1];
        dp[t.length()][p.length()] = true;

        // 从后往前遍历，能让前面的使用上dp的结果
        for (int i=t.length(); i >= 0; i--) {
            for (int j = p.length() - 1; j >= 0; j--) {
                boolean firstMatch = (i < t.length() && (t.charAt(i) == p.charAt(j) || p.charAt(j) == '.'));
                if (j + 1 < p.length() && p.charAt(j + 1) == '*') { // 有*的存在
                    dp[i][j] = (dp[i][j+2] || firstMatch && dp[i+1][j]);
                } else {
                    dp[i][j] = firstMatch && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }


    public static void main(String[] args) {
        String s = "bbbbb";
        String p = "b*";
        Solution solution = new Solution();
        boolean result1 = solution.isMatch(s, p);
        System.out.println("s=" + s + ", p = " + p + ",result1:" + result1);

        boolean result2 = solution.isMatch2(s, p);
        System.out.println("s=" + s + ", p = " + p + ",result2:" + result2);

        boolean result3 = solution.isMatch3(s, p);
        System.out.println("s=" + s + ", p = " + p + ",result3:" + result3);
    }
}