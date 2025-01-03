class Solution {
public:
    int distributeCandies(vector<int>& c) {
        sort(c.begin(),c.end());
        int diff=1;
        for(int i=1;i<c.size();i++){
            if(diff==c.size()/2)    return diff;
            if(c[i]>c[i-1]) diff++;
        }
        return diff;
    }
};