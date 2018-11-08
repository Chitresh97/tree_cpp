#include <iostream>
#include "TreeNode.h"
#include <vector>
#include<queue>
using namespace std;


int sumOfNodes(TreeNode<int>* root) {
  if(root==NULL)
    return 0;
  int sum=root->data;
  for(int i=0;i<root->children.size();i++){
    sum=sum+sumOfNodes(root->children.at(i));

  }
  return sum;
}

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data:"<<endl;
    cin>>rootData;
    TreeNode<int> * root= new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        int numChild;
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter no.of children of "<<front->data<<endl;
        cin>>numChild;
        for(int i=0;i<numChild;i++){
            int childData;
            cout<<"Enter "<<i+1<<" element of "<<front->data;
            cin>>childData;
            TreeNode<int>*child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }

    }
    return root;
}

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

    TreeNode<int> * root= takeInputLevelWise();
    printTree(root);

 }
