class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=i+1;
        int n=nums.size();
        while (i<n && j<n) {
            if (nums[i]==nums[j]) {
                j++;
            }
            else {
                swap(nums[i+1],nums[j]);
                i++;
                j++;
            }
        }
        return i+1;
    }
};