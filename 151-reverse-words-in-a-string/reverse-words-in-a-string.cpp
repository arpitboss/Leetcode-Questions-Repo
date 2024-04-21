class Solution {
public:
    string reverseWords(string s) {
        s.erase(s.find_last_not_of(" ") + 1);
        s.erase(0, s.find_first_not_of(" "));
        vector<string> v;
        string a="";
        bool flag=false;
        for (int i=0;i<s.size();i++) {
            if (s[i]==' ') {
                if (flag==false) {
                    v.push_back(a);
                    a="";
                    flag=true;
                }
            }
            else {
                a+=s[i];
                flag=false;
            }
        }
        v.push_back(a);
        
        string res="";
        for (int i=v.size()-1;i>=0;i--) {
            res+=v[i];
            if (i>0)
            res+=" ";
        }
        return res;
    }
};