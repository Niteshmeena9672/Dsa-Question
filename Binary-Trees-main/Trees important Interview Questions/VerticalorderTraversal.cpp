#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data: ";
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter data for inserting in left "<<data;
    cout<<endl;
    root->left=buildTree(root->left);
    
    cout<<"Enter data for inserting in right "<<data;
    cout<<endl;
    root->right=buildTree(root->right);
    
    return root;

}









void VerticalorderTraversal(node* root){
    // Map stores {Horizontal,Level,Vector of nodes}
    map<int,map<int,vector<int>>> nodestore;
    queue<pair<int,pair<int, node*>>> q;
    vector<int> ans;

    if(root==NULL){
        return ;
    }

    q.push(make_pair(0,make_pair(0,root)));
    while(!q.empty()){
        pair<int,pair<int,node*>> topnode = q.front();
        q.pop();

        int horizontal = topnode.first;
        int level = topnode.second.first;
        node* frontnode = topnode.second.second; 


        // map is storing the data in sorted order of Horizontal
        nodestore[horizontal][level].push_back(frontnode->data);

        if(frontnode->left){
            q.push(make_pair(horizontal-1,make_pair(level+1,frontnode->left)));
        }   
        if(frontnode->right){
            q.push(make_pair(horizontal+1,make_pair(level+1,frontnode->right)));
        }      
    }

    for(auto i: nodestore){
        for(auto j: i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }

    for(int i:ans){
        cout<<i<<",";
    }
}









int main(){
    node* root = NULL;
    root = buildTree(root);
    VerticalorderTraversal(root);
    return 0;
}