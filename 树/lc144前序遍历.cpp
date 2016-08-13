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
    /*vector<int> ret;
    void pre(TreeNode* root){
        if(!root) return;
        ret.push_back(root->val);
        pre(root->left);
        pre(root->right);
    }*/
    
    /*vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s;
        TreeNode* t;
        while(root){
            s.push(root);
            ret.push_back(root->val);
            root=root->left;
        }
        while(!s.empty()){
            root=s.top()->right; s.pop();
            
            while(root){
                s.push(root);
                ret.push_back(root->val);
                root=root->left;
            }
        }
        
        return ret;        
    }*/
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();
        
        vector<int> ret;
        stack<TreeNode*> s; s.push(root);
        
        while(!s.empty()){
            //访问root
            TreeNode* t=s.top(); s.pop();
            ret.push_back(t->val);
            
            //依次访问左右，压栈顺序相反
            if(t->right) s.push(t->right);
            if(t->left) s.push(t->left);
        }
        return ret;
    }
};