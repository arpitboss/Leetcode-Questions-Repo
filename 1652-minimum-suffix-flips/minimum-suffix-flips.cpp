class Solution {
public:
    int minFlips(string target) {
        int c=1;
        bool flag=false;
        int i=0;
        while (target[i]=='0' && i<target.size()) {
                i++;
        }
        if (i==target.size()) {
            flag=false;
        }
        else {
            flag=true;
        }
        for (;i<target.size()-1;i++) {
                if (target[i]!=target[i+1]) {
                    c++;
                }
        }
        return flag ? c : 0;
    }
};