class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            set<int> numSet;
            for (int i(0); i < nums.size(); ++i) {
                if (false == numSet.insert(nums[i]).second) return true;
            }
            return false;
        }
};
