class Solution {
public:
    int findTheWinner(int n, int k) {
       vector<int> v;
       for (int i=1;i<=n;i++) {
        v.push_back(i);
       }
       return josephus(v,k-1,0);
    }

    int josephus(vector<int> v, int k, int index) {
        if (v.size()==1) {
            return v[0];
        }
        index=(index+k)%v.size();
        v.erase(v.begin()+index);
        return josephus(v,k,index);
    }
};