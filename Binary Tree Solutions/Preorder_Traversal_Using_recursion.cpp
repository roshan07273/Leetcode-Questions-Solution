void PreOrder(Node* node , vector<int>&preorder){
    if(node == NULL) return;
    preorder.push_back(node->data);
    PreOrder(node->left , preorder);
    PreOrder(node->right , preorder);
}
vector <int> preorder(Node* root)
{
  vector<int>preorder;
  PreOrder(root , preorder);
  return preorder;
  
}
