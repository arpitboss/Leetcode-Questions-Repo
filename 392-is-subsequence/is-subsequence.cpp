class Solution {
public:
    bool isSubSeq(string str1, string str2, int m, int n) 
    { 
        if (m == 0) {
            return true;
        }
        if (n == 0) {
            return false;
        } 
        if (str1[m-1] == str2[n-1]) {
            return isSubSeq(str1, str2, m-1, n-1);
        }
        return isSubSeq(str1, str2, m, n-1); 
} 
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        return isSubSeq(s,t,n,m);
    }
};