public class Solution {

    /**
     * Dynamic Programming Solution
     */
        public String longestPalindromeDP(String s) {
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
            // 查看长度为3以上的子串
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

        // Expand Around Center solution
        public String longestPalindromeEAC(String s) {
            if (s.isEmpty() || s.length() == 1) return s;
            int start = 0, end = 0, n = s.length(); 
            for (int i = 0; i < n; i++) { // i is center point
                int l1 = aroundCenter(s, i, i);
                int l2 = aroundCenter(s, i, i + 1);
                int len = Math.max(l1, l2);
                if (len > end - start + 1) {
                    start = i - (len - 1)/ 2;
                    end = i + (len) / 2;
                }
            }
            return s.substring(start, end + 1);
        } 

        private int aroundCenter(String s, int i , int j) {
            int l = i;
            int r = j;
            while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
                l--;
                r++;
            }
            return r - l - 1;
        }
       
    public static void main(String args[]) {
        String test = "abcba";
        Solution solution = new Solution();
        String result1 = solution.longestPalindromeDP(test);
        System.out.println("Solution 1 result:" + result1);
        String result2 = solution.longestPalindromeEAC(test);
        System.out.println("Solution 2 result:" + result2);
    }
}