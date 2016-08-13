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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s;
        TreeNode* t=root, *previsited=NULL;
        
        while( t || !s.empty() ){
            while(t) { s.push(t); t=t->left;}
            t=s.top();
            if(t->right==NULL || t->right==previsited) { ret.push_back(t->val); s.pop(); previsited=t; t=0;}
            else t=t->right;
        }
        
        return ret;
    }
};