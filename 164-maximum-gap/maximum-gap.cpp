class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size()<=1) {
            return 0;
        }
        if (nums.size()==2) {
            return abs(nums[0]-nums[1]);
        }
       sort(nums.begin(),nums.end());
       int ans=INT_MIN;
       for (int i=1;i<nums.size();i++) {
          ans=max(ans,nums[i]-nums[i-1]);
       } 
       return ans;
    }
};