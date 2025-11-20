#include<iostream>

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

Node* insert(Node* root){
    int data;
    cout<<"Enter data to insert : "<<endl;
    cin>>data;
    if(data == -1){
        return NULL;
    }
    root = new Node(data);
    cout<<"Enter data for left of "<<data<<endl;
    root -> left = insert(root->left);
    cout<<"Enter data for right of "<<data<<endl;
    root -> right = insert(root->right);
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
int main(){
    Node* root = NULL;
    root = insert(root);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
}