class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p=0, q=nums.size()-1;
        int r=0;
        while (r<=q) {
            if (nums[r]==0) {
                swap(nums[r],nums[p]);
                p++;
                r++;
            }
            else if (nums[r]==1) {
                r++;
            }
            else {
                swap(nums[r],nums[q]);
                q--;
            }
        }
    }
};