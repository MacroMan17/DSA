class NumArray {
    vector<int> seg;
    int n;
    void build(int index, int left, int right, vector<int>& nums) {
        if (left == right) {
            seg[index] = nums[left];
            return;
        }
        int mid = (left + right) / 2;
        build(2 * index + 1, left, mid, nums);
        build(2 * index + 2, mid + 1, right, nums);
        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
    }
    void updateTree(int index, int left, int right,
                    int pos, int val) {
        if (left == right) {
            seg[index] = val;
            return;
        }
        int mid = (left + right) / 2;
        if (pos <= mid) {
            updateTree(2 * index + 1, left, mid, pos, val);
        } else {
            updateTree(2 * index + 2, mid + 1, right, pos, val);
        }
        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
    }
    int query(int index, int left, int right, int l, int r) {
        if (right < l || left > r)
            return 0;
        if (l <= left && right <= r)
            return seg[index];
        int mid = (left + right) / 2;
        int a = query(2 * index + 1, left, mid, l, r);
        int b = query(2 * index + 2, mid + 1, right, l, r);
        return a + b;
    }   
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        if (n > 0)
            build(0, 0, n - 1, nums);
    }
    void update(int index, int val) {
        if (n > 0)
            updateTree(0, 0, n-1, index, val);
    }
    int sumRange(int left, int right) {
        if (n == 0)
            return 0;
        return query(0, 0, n-1, left, right);
    }
};
