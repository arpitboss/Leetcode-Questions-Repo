class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pr=0, su=0;
        int res=INT_MIN;
        for (int i=0;i<nums.size();i++) {
            if (pr==0) {
                pr=1;
            }
            if (su==0) {
                su=1;
            }
            pr*=nums[i];
            su*=nums[nums.size()-i-1];
            res=max(res,max(pr,su));
        }
        return res;
    }
};