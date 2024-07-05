class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        map<int,int> mp;
        stack<int> st;

        for (int i=0;i<nums1.size();i++) {
            mp.insert({nums1[i],i});
        }

        for (int i=nums2.size()-1;i>=0;i--) {
            if (mp.find(nums2[i])!=mp.end()) {
                while (!st.empty() && nums2[i]>=st.top()) {
                        st.pop();
                    }

                ans[mp[nums2[i]]] = st.empty() ? -1 : st.top();
                st.push(nums2[i]);
            }
            else {
                    while (!st.empty() && nums2[i]>=st.top()) {
                        st.pop();
                    }

                    st.push(nums2[i]);
                }
        }
        return ans;
    }
};