class Solution {
public:

    bool isPossible(vector<int>& nums, int mid, int k) {
        int count = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] <= mid) {
                sum += nums[i];
            }
            else {
                count++;
                sum = nums[i];
            }
        }
        return count <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(nums, mid, k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};