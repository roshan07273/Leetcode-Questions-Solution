class Solution {
  public:
    int maxPathSum(Node* node , int &maxi){
        if(node == NULL) return 0 ;
        int left = max(0 , maxPathSum(node->left  , maxi));
        int right = max(0 , maxPathSum(node->right , maxi));
        
        maxi = max(maxi , left + right + node->data);
        
        return max(left , right) + node->data;
    }
    int findMaxSum(Node* root)
    {
        int maxi = INT_MIN;
        maxPathSum(root , maxi);
        return maxi;
        
    }
};
