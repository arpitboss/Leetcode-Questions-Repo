class Solution {
public:
    string reverseWords(string s) {
        int temp=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]==32) {
                temp++;
            }
            else {
                s.erase(0,temp);
                break;
            }
        }
        temp=0;
        for (int i=s.size()-1;i>=0;i--) {
            if (s[i]==32) {
                temp++;
            }
            else {
                s.erase(i+1,temp);
                break;
            }
        }
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