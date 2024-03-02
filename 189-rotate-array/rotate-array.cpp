class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if (n==0 || (k<=0)) {
            return;
        }
        vector<int> arr(n);
        arr=nums;

        for (int i=0;i<n;i++) {
            nums[(i+k)%n] = arr[i];
        }
    }

    
};