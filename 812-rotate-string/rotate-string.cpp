class Solution {
public:

    void rotateByOne(string &s, int i) {
        char temp=s[0];
        for (int i=0;i<s.size()-1;i++) {
            s[i]=s[i+1];
        }
        s[s.size()-1]=temp;
    }

    bool rotateString(string s, string goal) {
        if (s==goal) {
            return true;
        }
        int j=0;
        for (int i=0;i<s.size();i++) {
            rotateByOne(s,i);
            if (s==goal) {
                return true;
            }
        }
        return false;
    }
};