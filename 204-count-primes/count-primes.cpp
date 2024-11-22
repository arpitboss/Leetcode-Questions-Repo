class Solution {
public:
    int countPrimes(int n) {
       if (n<3) {
        return 0;
       } 
       vector<bool> visited(n+1,true);
       visited[0]=false;
       visited[1]=false;
       int res=0;
       for (int i=2;i<n;i++) {
        if (visited[i]) {
            res++;
            for (int j=2*i;j<n;j+=i) {
                visited[j]=false;
            }
        }
       }
       return res;
    }
};