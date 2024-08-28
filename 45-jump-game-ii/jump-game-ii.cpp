class Solution {
public:
    int jump(vector<int>& nums) {
        int res=0;
        int l=0, r=0;
        int farthestPoint;
        while (r<nums.size()-1) {
            farthestPoint=0;
            for (int i=l;i<r+1;i++) {
                farthestPoint=max(farthestPoint,i+nums[i]);
            }
            l=r+1;
            r=farthestPoint;
            res++;
        }
        return res;
    }
};