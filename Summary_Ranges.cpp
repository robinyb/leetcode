class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {
            vector<string> ret;
            int index(0);
            while (index < nums.size()) {
                int start(nums[index]), stop(start);
                while (++index < nums.size()) {
                    if (nums[index] != stop + 1) break;
                    stop = nums[index];
                }
                string ranges(to_string(start));
                if (start != stop) ranges += "->" + to_string(stop);
                ret.push_back(ranges);
            }
            return ret;
        }
};
