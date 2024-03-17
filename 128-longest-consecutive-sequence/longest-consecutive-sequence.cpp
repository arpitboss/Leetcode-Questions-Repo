class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        for (int i=0;i<n;i++) {
            s.insert(nums[i]);
        }

        if (n==0) {
            return 0;
        } 
        if (n==1) {
            return 1;
        }

        int maxi=0;
        int i=0;
        int sum=nums[0];
        while (i<n) {
            if (s.find(nums[i]-1)==s.end()) {
                int sum=nums[i];
                int c=1;
                while (s.find(sum+1)!=s.end()) {
                    sum++;
                    c++;
                }
                maxi=max(c,maxi);
            }
            i++;
        }
        return maxi;
    }
};