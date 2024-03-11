class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for (int i=0;i<nums.size();i++) {
            mp[nums[i]]=i;
        } 
        for (int i=0;i<nums.size();i++) {
            int y=target-nums[i];
            if (mp.find(y)!=mp.end() && mp[y]!=i) {
                return {i,mp[y]};
            }
        }
        return {};
    }
};