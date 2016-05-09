class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPos = findNextZeroPos(nums, 0);
        for (int index = zeroPos + 1; index < nums.size(); ++index) {
            if (nums[index] != 0) {
                int tmp = nums[index];
                nums[index] = nums[zeroPos];
                nums[zeroPos] = tmp;
                zeroPos = findNextZeroPos(nums, zeroPos + 1);
            }
        }
    }
    int findNextZeroPos(vector<int>& nums, int startPos) {
        for (int i = startPos; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                return i;
            }
        }
        return nums.size();
    }
};
