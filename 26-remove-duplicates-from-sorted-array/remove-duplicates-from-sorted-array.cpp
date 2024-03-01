class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = i + 1;
        int c = 1;
        int n = nums.size();
        while (i < n && j < n) {
            if (nums[i] == nums[j]) {
                j++;
            } else {
                nums[i + 1] = nums[j];
                i++;
                c++;
            }
        }
        return c;
    }
};