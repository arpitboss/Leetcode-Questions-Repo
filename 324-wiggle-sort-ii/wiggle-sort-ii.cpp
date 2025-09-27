class Solution {
public:
    void wiggleSort(vector<int>& nums) {
       vector<int> sorted=nums;
       sort(sorted.begin(),sorted.end());
       int m=(nums.size()+1)/2;
       int e=nums.size();
       for (int i=0;i<nums.size();i++) {
           if (i%2==0) {
               m--;
               nums[i]=sorted[m];
           }
           else {
               e--;
               nums[i]=sorted[e];
           }
       }
    }
};