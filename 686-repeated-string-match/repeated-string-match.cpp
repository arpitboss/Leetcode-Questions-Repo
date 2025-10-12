class Solution {
private: 
    void computeLPS(vector<int> &LPS, string &b) {
        LPS[0]=0;
        int len=0;
        int m=b.length();
        
        int i=1;
        while (i<m) {
            if (b[i]==b[len]) {
                len++;
                LPS[i]=len;
                i++;
            }
            else {
                if (len!=0) {
                    len=LPS[len-1];
                }
                else {
                    LPS[i]=0;
                    i++;
                }
            }
        }
    }

private:
    int KMP(string &a, string &b) {
        int n=a.length();
        int m=b.length();

        vector<int> LPS(m,0);
        computeLPS(LPS,b);

        int i=0;
        int j=0;
        while (i<n) {
            if (a[i]==b[j]) {
                i++;
                j++;
            }
            if (j==m) {
                return i-j;
            }
            else if (i<n && a[i]!=b[j]) {
                if (j!=0) {
                    j=LPS[j-1];
                }
                else {
                    i++;
                }
            }
        }
        return -1;
    }

public:
    int repeatedStringMatch(string a, string b) {
        int n=a.length();
        int m=b.length();
        int lenToAdd=m-1;

        int j=0;
        for (int i=0;i<lenToAdd;i++) {
            char ch=a[j];
            a+=ch;
            j=(j+1)%n;
        }

        int stInd=KMP(a,b);

        int res=-1;
        if (stInd!=-1) {
            int usedLenOfa=stInd+m;
            res=usedLenOfa/n;
            if ((usedLenOfa%n)!=0) {
                res+=1;
            }
        }
        return res;
    }
};