class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       long long XOR=0;
       for (int i=0;i<nums.size();i++) {
        XOR=XOR^nums[i];
       } 
       int num=XOR&~(XOR-1);
       int num1=0,num2=0;
       for (int i=0;i<nums.size();i++) {
        if ((nums[i]&num)) {
            num1^=nums[i];
        }
        else {
            num2^=nums[i];
        }
       }
       vector<int> v;
       v.push_back(num1);
       v.push_back(num2);
       return v;
    }
};