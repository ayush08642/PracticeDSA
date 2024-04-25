class Solution {
    Integer[][] memo;
    public int longestIdealString(String s, int k) {
        memo = new Integer[s.length()][130];
        return longestIdealString(s, k, 0, '#');
    }

    public static void print2D(int mat[][]) {
        for (int i = 0; i < mat.length; i++)
            for (int j = 0; j < mat[i].length; j++)
                System.out.print(mat[i][j] + " ");
    }

    public int longestIdealString(String s, int k, int si, char prevChar) {
        if (si >= s.length()) return 0;
        if (memo[si][prevChar] != null) {
            return memo[si][prevChar];
        }
        int take = 0;
        if (Math.abs(prevChar - s.charAt(si)) <= k || prevChar == '@') {
            take = 1 + longestIdealString(s, k, si + 1, s.charAt(si));
        }
        int notTake = longestIdealString(s, k, si + 1, prevChar);
        // print2D(memo);
        return memo[si][prevChar] = Math.max(take, notTake);
    }
}