class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for (int i=0;i<arr1.size();i++) {
            while (arr1[i]>0) {
                mp[arr1[i]]++;
                arr1[i]/=10;
            }
        }

        int res=0;
        for (int i=0;i<arr2.size();i++) {
            while (arr2[i]>0) {
                if (mp.find(arr2[i])!=mp.end()) {
                    res=max(res,arr2[i]);
                }
                arr2[i]/=10;
            }
        }
        if (res==0) {
            return 0;
        } else {
            return log10(res)+1;
        }
    }
};