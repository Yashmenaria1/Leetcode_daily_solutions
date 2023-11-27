class Solution {
    public int knightDialer(int N) {
        int mod = 1000000007;

        int[][] paths = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

        int[] currentCounts = new int[]{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

        for (int i = 1; i < N; i++) {
            int[] nextCounts = new int[10];
            for (int j = 0; j < 10; j++) {
                for (int p : paths[j]) {
                    nextCounts[p] = (nextCounts[p] + currentCounts[j]) % mod;
                }
            }
            currentCounts = nextCounts;
        }

        int sum = 0;
        for (int count : currentCounts) {
            sum = (sum + count) % mod;
        }
        return sum;
    }
};
