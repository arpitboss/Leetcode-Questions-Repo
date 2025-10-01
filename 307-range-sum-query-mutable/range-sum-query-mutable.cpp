class NumArray {
public:
    vector<int> arr;
    vector<int> preSum;
    NumArray(vector<int>& nums) {
        arr=nums;
        preSum.resize(arr.size());
        preSum[0]=arr[0];
        for (int i=1;i<arr.size();i++) {
            preSum[i]=arr[i]+preSum[i-1];
        }
    }
    
    void update(int index, int val) {
        int diff=val-arr[index];
        arr[index]=val;
        for (int i=index;i<preSum.size();i++) {
            preSum[i]+=diff;
        }
    }
    
    int sumRange(int left, int right) {
        if (left>0) {
            return preSum[right]-preSum[left-1];
        }
        else {
            return preSum[right];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */