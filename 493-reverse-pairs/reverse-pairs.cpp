class Solution {
public:
    int count;
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> A(high - low + 1);
        int i = low;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                A[k++] = nums[i++];
            }
            else {
                A[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            A[k++] = nums[i++];
        }
        while (j <= high) {
            A[k++] = nums[j++];
        }
        for (int x = low; x <= high; x++) {
            nums[x] = A[x - low];
        }
    }
    void countreverse(vector<int>& nums, int low, int mid, int high) {
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high &&
                   (long long)nums[i] > 2LL * nums[right]) {
                right++;
            }
            count += right - (mid + 1);
        }
    }
    void mergesort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;
        int mid = low + (high - low) / 2;
        mergesort(nums, low, mid);
        mergesort(nums, mid + 1, high);
        countreverse(nums, low, mid, high);
        merge(nums, low, mid, high);
    }
    int reversePairs(vector<int>& nums) {
        count = 0;
        mergesort(nums, 0, nums.size() - 1);
        return count;
    }
};