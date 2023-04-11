class Solution{
    public:
    
    int dfsHeight(Node *root){
        if(root == NULL) return 0;
        
        int leftHeight = dfsHeight(root->left);
        if(leftHeight == -1) return -1;
        
        int rightHeight = dfsHeight(root->right);
        if(rightHeight == -1) return -1;
        
        if(abs(leftHeight - rightHeight) > 1) return -1;
        
        return  1 + max(leftHeight , rightHeight);
        
    }
    
    bool isBalanced(Node *root)
    {
        return dfsHeight(root) != -1;
        
    }
};
