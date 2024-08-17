/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)   return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool isReverse=false;
        while (!q.empty()) {
            int count=q.size();
            vector<int> v;
            for (int i=0;i<count;i++) {
                TreeNode *curr=q.front();
                q.pop();
                v.push_back(curr->val);
                if (curr->left!=nullptr) {
                    q.push(curr->left);
                }
                if (curr->right!=nullptr) {
                    q.push(curr->right);
                }
            }
                if (isReverse) {
                    reverse(v.begin(),v.end());
                }
                ans.push_back(v);
                isReverse=!isReverse;
        }
        return ans;
    }
};