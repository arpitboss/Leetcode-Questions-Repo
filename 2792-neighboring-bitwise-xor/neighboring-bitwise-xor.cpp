class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int> original;
        for (int i=0;i<2;i++) {
            original.push_back(i);
            for (int j=0;j<n-1;j++) {
                original.push_back(original[j]^derived[j]);
            }
            if (original[0]^original[n-1]==derived[n-1]) {
                return true;
            }
        }
        return false;

            // Efficient Approach
        //return accumulate(derived.begin(), derived.end(), 0) % 2 == 0;
    }
};