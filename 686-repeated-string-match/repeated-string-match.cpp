class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n=a.length();
        int m=b.length();
        int min_rep=ceil((double)m/n);

        for (int i=0;i<3;i++) {
            string a_rep="";
            for (int j=0;j<min_rep+i;j++) {
                a_rep+=a;
            }

            if (a_rep.find(b)!=string::npos) {
                return min_rep+i;
            }
        }
        return -1;
    }
};