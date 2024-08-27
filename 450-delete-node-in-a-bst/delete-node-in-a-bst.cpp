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
    int findMin(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key){
            if(!root->left and !root->right){
                delete root;
                return NULL;
            }
            if(!root->left and root->right){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if(!root->right and root->left){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if(root->left and root->right){
                int mini = findMin(root->right);
                root->val = mini;
                root->right = deleteNode(root->right,mini);
                return root;
            }
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else{
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};