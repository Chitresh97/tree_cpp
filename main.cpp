#include <iostream>
#include "TreeNode.h"
#include <vector>

using namespace std;

TreeNode<int>* takeInput(){
    int rootData;
    int n;
    cout<<"Enter data:"<<endl;
    cin>>rootData;
    TreeNode<int> * root= new TreeNode<int>(rootData);
    cout<<"Enter no. of children:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        root->children.push_back(takeInput());
    }
    return root;
}

void printTree(TreeNode<int>*root){
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }

}
int main()
{

    TreeNode<int> * root= takeInput();
    printTree(root);

 }
