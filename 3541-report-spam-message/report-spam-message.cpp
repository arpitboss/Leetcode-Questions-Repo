class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,int> mp;
        for (auto i:bannedWords) {
            mp[i]++;
        }

        int tmp=0;
        for (auto i:message) {
            if (mp.find(i)!=mp.end()) {
                tmp++;
            }
        }
        return (tmp>=2) ? true : false; 
    }
};