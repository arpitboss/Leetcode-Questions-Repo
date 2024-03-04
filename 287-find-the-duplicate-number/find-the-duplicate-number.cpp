class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for (auto i:nums) {
            int index=abs(i);
            if (nums[index]<0) {
                return index;
            }
            nums[index]=-nums[index];
        }
        return n;
    }
};