class Solution {
public:

    int solve(vector<int>& nums, int i, int prev,
              vector<vector<int>>& dp) {

        int n = nums.size();

        // Base condition
        if (i == n) {
            return 0;
        }

        // Already calculated
        if (dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }

        // TAKE
        int take = 0;

        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(nums, i + 1, i, dp);
        }

        // NOT TAKE
        int notTake = solve(nums, i + 1, prev, dp);

        return dp[i][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(nums, 0, -1, dp);
    }
};