/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();
        vector<int> ret;
        stack<TreeNode*> s;
        while(root){
            s.push(root);
            root=root->left;
        }
        while(!s.empty()){
            //visit
            TreeNode* rgt=s.top()->right;
            ret.push_back(s.top()->val); 
            s.pop(); root=rgt;
            //转向
            while(root){
                s.push(root);
                root=root->left;
            }
        }
        
        return ret;
    }
};