class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size()<=1) {
            return 0;
        }
        if (nums.size()==2) {
            return abs(nums[0]-nums[1]);
        }
        
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for (int i=0;i<nums.size();i++) {
            maxi=max(nums[i],maxi);
            mini=min(mini,nums[i]);
        }

        double d=((maxi-mini)*1.0)/(nums.size()-1);
        if (d<1.0) {
            d=1.0;
        }
        vector<pair<int,int>> buc(nums.size(),{INT_MAX,INT_MIN});
        for (int i=0;i<nums.size();i++) {
            int val=(nums[i]-mini)/d;
            buc[val].first=min(buc[val].first,nums[i]);
            buc[val].second=max(buc[val].second,nums[i]);
        }
        int preMaxi=buc[0].second;
        int res=0;
        for (int i=1;i<nums.size();i++) {
            if (buc[i].first==INT_MAX) {
                continue;
            }
            res=max(res,buc[i].first-preMaxi);
            preMaxi=buc[i].second;
        }
        return res;
    }
};