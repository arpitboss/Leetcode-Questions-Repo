class Solution {
public:
    static bool comp(const string &a, const string &b) {
        return a+b>b+a;
    }

    string largestNumber(vector<int>& nums) {
        string res;
        vector<string> tmp;
        for (auto n:nums) { 
            string s=to_string(n);
            tmp.push_back(s);
        }
        sort(tmp.begin(),tmp.end(),comp);

        for (auto x:tmp) {
            res+=x;
        }

        if (res[0]=='0' && res.length()>1) {
            return "0";
        }
        return res;
    }
};