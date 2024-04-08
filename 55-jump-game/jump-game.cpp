class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for (int i = 0; j < n && j <= i; ++j) {
            i = max(j + nums[j], i);
        }
        return j == n;
    }
};