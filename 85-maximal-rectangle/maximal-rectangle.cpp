class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> arr(matrix[0].size(),0);
        int res=0;
        for (int i=0;i<matrix.size();i++) {
            for (int j=0;j<matrix[0].size();j++) {
                if ((matrix[i][j]-'0')==0) {
                    arr[j]=0;
                }
                else {
                    arr[j]+=1;
                }
            }
            int n=matrix[0].size();
        
            stack<int> st;
            for (int i=0;i<n;i++) {
                while (!st.empty() && arr[st.top()]>=arr[i]) {
                    int top=st.top();
                    st.pop();
                    int curr=arr[top]*(st.empty() ? i : (i-st.top()-1));
                    res=max(res,curr);
                }
                st.push(i);
            }

            while (!st.empty()) {
                int top=st.top();
                st.pop();
                int curr=arr[top]*(st.empty() ? n : (n-st.top()-1));
                res=max(res,curr);
            }
        }

        return res;
    }
};