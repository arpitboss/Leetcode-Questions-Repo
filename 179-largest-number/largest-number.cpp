class Solution {
public:
    static bool comp(const string& a, const string& b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        for (auto i : nums) {
            vec.push_back(to_string(i));
        }

         sort(vec.begin(), vec.end(), comp);

        if (vec[0] == "0") {
            return "0";
        }

 
        string ans = "";
        for (auto& str : vec) {
            ans += str;
        }

        return ans;
    }
};
