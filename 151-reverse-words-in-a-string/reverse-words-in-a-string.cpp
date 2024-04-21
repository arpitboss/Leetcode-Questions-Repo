class Solution {
public:
    string reverseWords(string s) {
        s.erase(s.find_last_not_of(" ") + 1);
        s.erase(0, s.find_first_not_of(" "));
        reverse(s.begin(),s.end());
        int c=0;
        bool flag=true;
        for (int i=0;i<s.size();i++) {
            if (s[i]!=' ') {
                c++;
                flag=true;
            }
            else {
                if (flag==false) {
                    s.erase(i,1);
                    i--;
                }
                else {
                    reverse(s.begin()+(i-c),s.begin()+i);
                    flag=false;
                    c=0;
                }
            }
        }
        reverse(s.begin()+(s.size()-c),s.end());
        return s;
    }
};