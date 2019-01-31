public class Solution {

    /**
     * Dynamic Programming Solution
     */
        public String longestPalindromeByDP(String s) {
            if (s.isEmpty() || s.length() == 1) return s;
            int n = s.length();
            int[][] pArray = new int[n][n];
            int start=0, maxLen = 1;
            // 长度为1，单个字符是回文子串
            for (int i = 0 ; i < n; i++) {
                pArray[i][i] = 1;
            }
            // 长度为2 看字符是否相等，如果相等即为回文子串
            for (int i = 0; i < n - 1; i++) {
                if (s.charAt(i) == s.charAt(i + 1)) {
                    pArray[i][i + 1] = 1;
                    start = i;
                    maxLen = 2;
                }
            }
            // 便利查看长度为3以上的子串
            for (int k = 3; k <= n; k++) {
                for (int left = 0; left + k -1 < n; left++) {  // 限制条件：left最大值是 ： n - 长度 + 1
                    int right = left + k - 1; // 右端点 因为长度 k = rigth - left + 1 
                    if (pArray[left+1][right-1]  == 1 && s.charAt(left) == s.charAt(right)) {
                        pArray[left][right] = 1;
                        if (k > maxLen) {
                            start = left;
                            maxLen = k;
                        }
                    }
                }
            }
            return s.substring(start, start + maxLen);
        }


    public static void main(String args[]) {
        String test = "abcba";
        Solution solution = new Solution();
        String longSubString = solution.longestPalindromeByDP(test);
        System.out.println(longSubString);
    }
}