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

int height(Node *node){
    if(node == nullptr){
        return -1;
    }
    int lheight = height(node->left);
    int rHeight = height(node->right);
    
    return max(lheight, rHeight)+1;
}

int height_nodes(Node *node){
    if(node == nullptr){
        return 0;
    }
    int lheight = height_nodes(node->left);
    int rHeight = height_nodes(node->right);
    
    return max(lheight, rHeight)+1;
}

void preOrder(Node *node){
    if(node == nullptr){
        return;
    }
    
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node *node){
    if(node == nullptr){
        return;
    }
    
    inOrder(node->left);
    cout<<node->data<<" ";
    inOrder(node->right);
}

//postorder =======================
void postOrder(Node *node){
    if(node == nullptr){
        return;
    }
    
    postOrder(node->left);
    postOrder(node->right);
    cout<<node->data<<" ";
}

bool find(Node *node, int data){
    if(node == nullptr){
        return false;
    }
    
    if(node->data == data){
        return true;
    }
    
    return find(node->left, data) || find(node->right, data);
}

bool nodeToRootPath(Node *node, int data, vector<Node*>&ans){
    if(node == nullptr){
        return false;
    }
    
    if(node->data == data){
        ans.push_back(node);
        return true;
    }
    
    bool res = nodeToRootPath(node->left, data, ans) || nodeToRootPath(node->right, data, ans);
    
    if(res){
        ans.push_back(node);
    }
    
    return res;
}

vector<Node*> nodeToRootPathTwo(Node *node, int data){
    if(node == nullptr){
        return {};
    }
    
    if(node->data == data){
        vector<Node*>base;
        base.push_back(node);
        return base;
    }
    
    vector<Node*> left = nodeToRootPathTwo(node->left, data);
    if(left.size() != 0){
        left.push_back(node);
        return left;
    }
    
    vector<Node*> right = nodeToRootPathTwo(node->right, data);
    if(right.size() != 0){
        right.push_back(node);
        return right;
    }
    
    return {};
}


// use backtrackingg ==============
bool rootToNodePath(Node* node, int data, vector<Node*>&ans){
    if(node == nullptr){
        return false;
    }
    if(node->data == data){
        ans.push_back(node);
        return true;
    }
    
    ans.push_back(node);
    bool res = rootToNodePath(node->left, data, ans) || rootToNodePath(node->right, data, ans);
    
    if(!res){
        ans.pop_back();
    }
    return res;
}


int main() {
    // Write C++ code here
   vector<int>arr = {10,20,40,80, -1, -1, 90, 100, -1, -1, -1, 50, -1, -1, 30, 60, 110, 120, -1, -1, 140, -1, -1, -1, 70, -1, -1};
   
   Node *root = constructTree(arr);
   display(root);
   
//   cout<<size(root)<<endl;
//   cout<<height(root)<<endl;
//   cout<<height_nodes(root)<<endl;
//     preOrder(root);
//     cout<<endl;
//     inOrder(root);
//     cout<<endl;
//     postOrder(root);
//     cout<<endl;
//     cout<<find(root, 210)<<endl;
    // vector<Node*>ans;
    // cout<<nodeToRootPath(root, 90, ans)<<endl;
    // for(Node* node : ans){
    //     cout<<node->data<<" ";
    // }
    // cout<<endl;
    // vector<Node*>res = nodeToRootPathTwo(root, 90);
    //  for(Node* node : res){
    //     cout<<node->data<<" ";
    // }
    vector<Node*>ans;
    cout<<rootToNodePath(root, 90, ans)<<endl;
     for(Node* node : ans){
        cout<<node->data<<" ";
    }
    
    return 0;
}