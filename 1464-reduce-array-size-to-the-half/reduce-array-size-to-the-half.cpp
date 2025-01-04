class Solution {
public:
    static bool comp(pair<int,int> &a, pair<int,int> &b) {
        return a.second>b.second;
    }
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freqMap;
        for (int num : arr) {
            freqMap[num]++;
        }
        vector<pair<int,int>> freq(freqMap.begin(), freqMap.end());
        sort(freq.begin(),freq.end(),comp);
        int res=0;
        int val=arr.size()/2;
        int n=arr.size();
        for (int i=0;i<freq.size();i++) {
            n-=freq[i].second;
            res++;
            if (n<=val) {
                break;
            }
        }
        return res;
    }
};