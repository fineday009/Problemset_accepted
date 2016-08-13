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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        vector<int> perline;
        queue<TreeNode*> _queue;
        TreeNode* last=root;
        _queue.push(root);
        
        while(!_queue.empty()){
            TreeNode* frt=_queue.front(); _queue.pop(); perline.push_back(frt->val);
            
            if(frt->left) _queue.push(frt->left);
            if(frt->right) _queue.push(frt->right);
            
            if(frt==last){
                last=_queue.back();
                res.push_back(perline);
                perline.clear();
            }
        }
        return res;
    }
};