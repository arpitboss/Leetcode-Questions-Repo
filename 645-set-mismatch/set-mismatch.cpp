class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size()-1;i++) {
            if (nums[i]==nums[i+1]) {
                v.push_back(nums[i]);
                break;
            }
        }
        int sum=0;
        for (int i=0;i<nums.size();i++) {
            sum+=nums[i];
        }
        sum-=v[0];
        int sum2=0;
        for (int i=1;i<=nums.size();i++) {
            sum2+=i;
        }
        v.push_back(sum2-sum);

        return v;
    }
};