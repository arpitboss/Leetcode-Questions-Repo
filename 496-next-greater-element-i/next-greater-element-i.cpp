class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        stack<int> st;

        for (int i=0;i<nums1.size();i++) {
            for (int j=nums2.size()-1;j>=0;j--) {
                if (nums1[i]==nums2[j]) {
                    while (!st.empty() && nums2[j]>=st.top()) {
                        st.pop();
                    }

                    ans[i] = st.empty() ? -1 : st.top();
                    break;
                }
                else {
                    while (!st.empty() && nums2[j]>=st.top()) {
                        st.pop();
                    }

                    st.push(nums2[j]);
                }
            }
            st = stack<int>();
        }
        return ans;
    }
};