class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int cloSum=nums[0]+nums[1]+nums[2];
        for (int i=0;i<nums.size();i++) {
            int l=i+1;
            int r=nums.size()-1;
            while (l<r) {
                int curr=nums[i]+nums[l]+nums[r];
                if (abs(target-curr)<abs(target-cloSum)) {
                    cloSum=curr;
                }
                if (curr==target) {
                    return curr;
                }
                else if(curr<target) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }
        return cloSum;
    }
};