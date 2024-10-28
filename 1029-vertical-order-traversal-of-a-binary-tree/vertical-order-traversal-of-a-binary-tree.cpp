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
    void solve(TreeNode* root, int x, int level, map<int, map<int,vector<int>>>& mp) {
        if (root==nullptr) {
            return;
        }

        mp[x][level].push_back(root->val);
        solve(root->left,x-1,level+1,mp);
        solve(root->right,x+1,level+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        if (root==nullptr) {
            return v;
        }

        map<int,map<int,vector<int>>> mp;
        solve(root,0,0,mp);
        for (auto i:mp) {
            vector<int> c; 
            for (auto j:i.second) {
                vector<int> values = j.second;
                sort(values.begin(), values.end()); 
                for (int k=0; k<values.size(); k++) {
                    c.push_back(values[k]);
                }
            }
            v.push_back(c);
        }
        return v;
    }
};