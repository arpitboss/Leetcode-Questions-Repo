class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for (int i=0;i<nums.size();i++) {
            int l=i+1;
            int r=nums.size()-1;
            while (l<r) {
                int sum=nums[i]+nums[l]+nums[r];
                mp[sum]=abs(target-sum);
                if (sum==target) {
                    return sum;
                }
                else if(sum<target) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }
        int res=0, mini=INT_MAX;
        for (auto x:mp) {
            if (x.second<mini) {
                mini=x.second;
                res=x.first;
            }
        }
        return res;
    }
};