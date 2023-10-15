/*Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};
*/

class Solution{
private:
    Node* createBST(vector<int> &a , int low , int high){
        if( low > high) return NULL;
        int mid = low + (high - low) / 2;
        Node* root = new Node(a[mid]);
        root -> left = createBST(a , low , mid - 1);
        root -> right = createBST(a , mid + 1 , high);
        
        return root;
    }
private:
    void inorder(Node* root , vector<int> &arr){
        if(root == nullptr) return;
        inorder(root -> left , arr);
        arr.push_back(root->data);
        inorder(root -> right , arr);
    }
public:
    Node* buildBalancedTree(Node* root)
    {
    	if(root == nullptr) return nullptr;
    	
    	vector<int> ans;
    	inorder(root , ans);
    	
    	int len = ans.size();
    	return createBST(ans , 0 , len - 1);
    }
};
