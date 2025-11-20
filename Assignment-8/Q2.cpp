#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};
Node* insert_bst(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
    }
    else if(data > root->val){
        root->right = insert_bst(root->right,data);
    }
    else if(data < root->val){
        root->left = insert_bst(root->left,data);
    }
    return root;
}
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<"\t";
    inorder(root->right);
}
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->val<<"\t";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<"\t";
}
Node* min_ele(Node* root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}
Node* max_ele(Node* root){
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
}
Node* search(Node* root,int data){
    if(root == NULL){
        cout<<"Element not found !!";
        return NULL;
    }
    if(data == root->val){
        return root;
    }
    else if(data > root->val){
        return search(root->right,data);
    }
    else{
        return search(root->left,data);
    }
}
void inorder_suc_pre(Node* root, int data){
    root = search(root, data);
    if(root == NULL){
        cout << "Element not found";
        return;
    }
    cout << "inorder successor : ";
    if(root->right){
        cout << min_ele(root->right)->val << endl;
    }
    else{
        cout << "No successor";
    }
    cout << "inorder predecessor : ";
    if(root->left){
        cout << max_ele(root->left)->val << endl;
    }
    else{
        cout << "No predecessor\n";
    }
}
int main(){
    Node* root = NULL;
    vector<int> arr = {2,3,1,5,6,711,8};
    for(int i : arr){
        root = insert_bst(root,i);
    }
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<(min_ele(root))->val;
    cout<<endl;
    cout<<(max_ele(root))->val;
    cout<<endl;
    inorder_suc_pre(root,2);
}