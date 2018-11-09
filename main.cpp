#include <iostream>
#include "TreeNode.h"
#include <vector>
#include<queue>
using namespace std;

int numLeafNodes(TreeNode<int>* root) {
  if(root->children.size()==0)
    return 1;
  else{
  int n=0;
  for(int i=0;i<root->children.size();i++){
    n=n + numLeafNodes(root->children[i]);
  }
    return n;
  }

}

int height(TreeNode<int>* root) {
  if(root==NULL)
    return 0;
  if(root->children.size()==0)
    return 1;

  else{
    int maxChildHeight=height(root->children[0]);
  for(int i=1;i<root->children.size();i++){
    int childheight=height(root->children[i]);
    if(childheight>maxChildHeight)
      maxChildHeight=childheight;
  }
    return 1+maxChildHeight;
  }

}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
  if(root==NULL)
    return NULL;

  int max=root->data;
  TreeNode<int>*maxChild=root;

  for(int i=0;i<root->children.size();i++){
    TreeNode<int>* temp=maxDataNode(root->children[i]);
    if(temp->data>max){
      max=temp->data;
      maxChild=temp;
    }
  }
  return maxChild;
}


int sumOfNodes(TreeNode<int>* root) {
  if(root==NULL)
    return 0;
  int sum=root->data;
  for(int i=0;i<root->children.size();i++){
    sum=sum+sumOfNodes(root->children.at(i));

  }
  return sum;
  }
void printLevelWise(TreeNode<int>*root){
    queue<TreeNode<int>*> pendingNodes;
      pendingNodes.push(root);
      while(pendingNodes.size()!=0){
          TreeNode<int>*front=pendingNodes.front();

          cout<<front->data<<":";
          for(int i=0;i<front->children.size();i++){
              cout<<front->children.at(i)->data;
              if(i!=front->children.size()-1)
                  cout<<",";
            pendingNodes.push(front->children[i]);
                  }
        cout<<endl;
        pendingNodes.pop();}

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
            cout<<"Enter "<<i+1<<" element of "<<front->data<<""<<endl;
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
    printLevelWise(root);

 }
