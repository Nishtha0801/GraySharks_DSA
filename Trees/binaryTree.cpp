// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    
    Node(int data){
        this->data = data;
    }
};

// contruct tree using recursion
int idx = 0;
Node *constructTree(vector<int>&arr){
    if(idx == arr.size() || arr[idx] == -1){
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    
    return node;
}

void display(Node *node){
    if(node == nullptr){
        return;
    }
    
    string ans = "";
    ans+= (node->left == nullptr ? "." : to_string(node->left->data) + " ");
    ans+="<-" + to_string(node->data) + "->";
    
    ans+=(node->right == nullptr ? "." : to_string(node->right->data) + " ");
    
    cout<<ans<<endl;
    
    display(node->left);
    display(node->right);
}

// find the size of the tree ================
int size(Node *node){
    if(node == nullptr){
        return 0;
    }
    int countleft = size(node->left);
    int countright = size(node->right);
    return  countleft + countright + 1;
    
}

int main() {
    // Write C++ code here
   vector<int>arr = {10,20,40,80, -1, -1, 90, 100, -1, -1, -1, 50, -1, -1, 30, 60, 110, 120, -1, -1, 140, -1, -1, -1, 70, -1, -1};
   
   Node *root = constructTree(arr);
   display(root);
   
   cout<<size(root);

    return 0;
}