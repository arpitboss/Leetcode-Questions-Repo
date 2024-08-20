class Solution {
public:
    void permu(string s, string op, vector<string>& v) {
        if (s.size()==0) {
            v.push_back(op);
            return;
        }
        if (isalpha(s[0])) {
            string op1=op;
            string op2=op;
            op1.push_back(tolower(s[0]));
            op2.push_back(toupper(s[0]));
            s.erase(s.begin()+0);
            permu(s,op1,v);
            permu(s,op2,v);
        }
        else {
            string op1=op;
            op1.push_back(s[0]);
            s.erase(s.begin()+0);
            permu(s,op1,v);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> v;
        string op="";
        permu(s,op,v);
        return v;
    }
};