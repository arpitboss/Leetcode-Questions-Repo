#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> freq(100001, 0);
        for (int num:arr) {
            freq[num]++;
        }
        vector<int> freqCount(arr.size()+1,0);
        for (int count:freq) {
            if (count>0) {
                freqCount[count]++;
            }
        }

        int res=0;
        int removed=0;
        int val=arr.size()/2;
        for (int i=freqCount.size()-1;i>0;i--) {
            while (freqCount[i]>0 && removed<val) {
                removed+=i;
                freqCount[i]--;   
                res++;      
            }
            if (removed>=val) {
                break;
            }
        }
        return res;
    }
};
