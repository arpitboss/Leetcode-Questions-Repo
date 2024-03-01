class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int sum=0;
        for(auto i:nums){
            sum^=i;

        }
        return sum;
    }
};