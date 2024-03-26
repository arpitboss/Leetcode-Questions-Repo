class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mod = pow(10, 9) + 7, count = 0;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = (dp[i - 1] * 2) % mod;
        }
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            if(nums[left] + nums[right] > target) right--;
            else {
                count += dp[right -left];
                count %= mod;
                left++;
            }
        }
        return count;
    }

    // int countSubsequence(int mins, int maxs, int index, vector<int>& nums,int target) {
    //     if (index>=nums.size()) {
    //         return 0;
    //     }
    //     int mini=min(mins,nums[index]);
    //     int maxi=max(maxs,nums[index]);
    //     int c=0;
    //     if (mini+maxi<=target) {
    //         c++;
    //     }

    //     return c+countSubsequence(mini, maxi, index+1, nums,target) + countSubsequence(mins, maxs, index+1, nums,target);
    // }
};