class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n=nums.size();
        int c=0;
        int maxi=0;
        for (int i=0;i<n;i++) {
            if (nums[i]%2==0 && nums[i]<=threshold) {
                c=1;
                int j=i+1;
                while (j<n) {
                    if ((nums[j]-nums[j-1])%2!=0 && nums[j]<=threshold) {
                        c++;
                        j++;
                    }
                    else {
                        break;
                    }
                }
                maxi=max(maxi,c);
                i=j-1;
            } 
        }
        return maxi;
    }
};