class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        for (int i=0;i<n;i++) {
            nums[i]=(nums[i]==0) ? -1 : 1;
        }

        unordered_map<int,int> s;
        int preSum=0;
        int maxi=0;
        for (int i=0;i<n;i++) {
            preSum+=nums[i];
            if (preSum==0) {
                maxi=i+1;
            }
            if (s.find(preSum)!=s.end()) {
                maxi=max(maxi,i-s[preSum]);
            }
            if (s.find(preSum)==s.end()) {
                s[preSum]=i;
            }
        }
        return maxi;
    }
};