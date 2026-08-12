class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> temp = nums;
        temp.insert(temp.end(), nums.begin(), nums.end());
        return temp;
            
    }
};