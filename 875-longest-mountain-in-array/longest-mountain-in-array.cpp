class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int res=0;
        int i=1;

        while (i<n-1) {
            if (arr[i]>arr[i-1] && arr[i]>arr[i+1]) {
                int l=i-1;
                int r=i+1;

                while (l>=0 && arr[l]<arr[l+1]) {
                    l--;
                }
                while (r<n && arr[r]<arr[r-1]) {
                    r++;
                }
                res=max(res,r-l-1);
                i=r;
            } else {
                i++;
            }
        }
        return res;
    }
};