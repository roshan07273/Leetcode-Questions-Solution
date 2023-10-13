class Solution{
public:
    int floor(Node* root, int x) {
        int flr = -1;
        if(!root) return NULL;
        while(root){
            if(root->data == x){
                flr = root->data;
                return flr;
            }
            else if( x > root->data){
                flr = root->data;
                root = root -> right;
            }else{
                root = root-> left;
            }
        }
        return flr;
    }
};
