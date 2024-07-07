class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int area=0;
        stack<int> st;
        for (int i=0;i<n;i++) {
            while (!st.empty() && heights[st.top()]>=heights[i]) {
                int top=st.top();
                st.pop();
                int currArea=heights[top]*(st.empty() ? i : (i-st.top()-1));
                area=max(area,currArea);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int top=st.top();
            st.pop();
            int currArea=heights[top]*(st.empty() ? n : (n-st.top()-1));
            area=max(area,currArea);
        }

        return area;
    }
};