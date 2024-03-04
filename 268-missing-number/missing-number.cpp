class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> hashmap(n + 1, 0);
        for(int i=0;i<n;i++){
            hashmap[nums[i]] = 1;
        }
        for(int i=0;i<=n;i++){
            if(hashmap[i]==0)
            return i;
        }
        return -1;
    }
};