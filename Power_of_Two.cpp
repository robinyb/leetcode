class Solution {
    public:
        bool isPowerOfTwo(int n) {
            if (1 > n) return false;
            return 0 == (n & (n - 1));
        }
};
