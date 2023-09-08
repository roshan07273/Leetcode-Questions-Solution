/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
public:
    void inorder(Node* root , vector<int> &arr){
        if(!root) return;
        inorder(root->left , arr);
        arr.push_back(root->data);
        inorder(root->right , arr);
    }
public:
    void inorder_bst(Node* root , vector<int> &arr , int &i){
        if(!root) return;
        inorder_bst(root->left , arr , i);
        root -> data = arr[i];
        i++;
        inorder_bst(root->right , arr , i);
    }
public:
    Node *binaryTreeToBST (Node *root)
    {
        vector<int>arr;
        inorder(root , arr);
        sort(arr.begin() , arr.end());
        
        int i = 0;
        inorder_bst(root , arr , i);
        
        return root;
        
    }
};
