class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> tmp;
        int n=nums.size();
        int j=0;
        int c=0;
        for (int i=0;i<n;i++) {
            if (nums[i]<pivot) {
                nums[j]=nums[i];
                j++;
            }
            else if (nums[i]==pivot) {
                c++;
            }
            else {
                tmp.push_back(nums[i]);
            }
        }
        while (c>0) {
            nums[j]=pivot;
            j++;
            c--;
        }
        for (int i=0;i<tmp.size();i++) {
            nums[j]=tmp[i];
            j++;
        }
        return nums;
    }
};