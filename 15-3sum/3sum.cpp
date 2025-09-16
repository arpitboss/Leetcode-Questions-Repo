class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i=0;i<nums.size();i++) {
            if (i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            int l=i+1;
            int r=nums.size()-1;
            while (l<r) {
                int sum=nums[l]+nums[r]+nums[i];
                if (sum==0) {
                    res.push_back({nums[l],nums[r],nums[i]});
                    l++;
                    while (nums[l]==nums[l-1] && l<r) {
                        l++;
                    }
                }
                else if (sum<0) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }

        return res;
    }
};