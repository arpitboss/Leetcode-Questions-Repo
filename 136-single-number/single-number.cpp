class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR=0;
        for (auto i:nums) {
            XOR^=i;
        }
        return XOR;
    }
};