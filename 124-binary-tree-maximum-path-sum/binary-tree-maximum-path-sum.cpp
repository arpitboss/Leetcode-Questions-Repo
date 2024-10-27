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
    int solve(TreeNode* root, int& sum) {
        if (root==nullptr) {
            return 0;
        }

        int l=solve(root->left,sum);
        int r=solve(root->right,sum);
        int temp=max(root->val+max(l,r),root->val);
        int ans=max(temp,root->val+l+r);
        sum=max(sum,ans);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        solve(root,sum);
        return sum;
    }
};