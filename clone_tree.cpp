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
private:
    TreeNode* DFS(TreeNode* clone , int val){
        if(!clone) return NULL;
        if(clone->val == val) return clone;
        TreeNode* left = DFS(clone->left , val);
        if(left) return left;
        
        TreeNode* right = DFS(clone->right , val);
        if(right) return right;
        
        
        return NULL;
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int val = target->val;
        
        return DFS(cloned , val);
    }
};
