// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<queue>
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

void BFS_01(Node* node){
    queue<Node*>que;
    
    que.push(node);
    while(que.size() != 0){
        Node* removedNode = que.front();
        que.pop();
        cout<<removedNode->data<< " ";
        
        if(removedNode->left != nullptr){
            que.push(removedNode->left);
        }
        
        if(removedNode->right != nullptr){
            que.push(removedNode->right);
        }
    }
}

void BFS_02(Node* node){
    queue<Node*>que;
    
    que.push(node);
    int level = 0;
    while(que.size() != 0){
        int size = que.size();
        cout<<"Level:"<<level<<"->";
        while(size-- > 0){
            Node* removedNode = que.front();
            que.pop();
            cout<<removedNode->data<< " ";
        
            if(removedNode->left != nullptr){
                que.push(removedNode->left);
            }
            
            if(removedNode->right != nullptr){
                que.push(removedNode->right);
            }
        }
        cout<<endl;
        level++;
    }
}

vector<int> leftView(Node* node){
    queue<Node*>que;
    que.push(node);
    vector<int>ans;
    
    while(que.size() != 0){
        int size = que.size();
        ans.push_back(que.front()->data);
        
        while(size -- > 0){
            Node* removedNode = que.front();
            que.pop();
          
        
            if(removedNode->left != nullptr){
                que.push(removedNode->left);
            }
            
            if(removedNode->right != nullptr){
                que.push(removedNode->right);
            }
        }
    }
    return ans;
}

// right view ==================
vector<int> rightView(Node* node){
    queue<Node*>que;
    que.push(node);
    vector<int>ans;
    
    while(que.size() != 0){
        int size = que.size();
        int prev = -1;
        while(size -- > 0){
            Node* removedNode = que.front();
            que.pop();
        
            if(removedNode->left != nullptr){
                que.push(removedNode->left);
            }
            
            if(removedNode->right != nullptr){
                que.push(removedNode->right);
            }
            
             prev = removedNode->data;
        }
        ans.push_back(prev);
    }
    return ans;
}

void width(Node* node, int level, vector<int>&maxMin){
    if(node == nullptr){
        return;
    }
    
    maxMin[0] = max(maxMin[0], level);
    maxMin[1] = min(maxMin[1], level);
     
    width(node->left, level-1, maxMin);
    width(node->right, level+1, maxMin);
}

int main() {
    // Write C++ code here
   vector<int>arr = {10,20,40,80, -1, -1, 90, 100, -1, -1, -1, 50, -1, -1, 30, 60, 110, 120, -1, -1, 140, -1, -1, -1, 70, -1, -1};
   
   Node *root = constructTree(arr);
   display(root);
   
    BFS_01(root);
    cout<<endl;
    BFS_02(root);
    cout<<endl;
    vector<int>maxMin(2, 0);
    width(root, 0, maxMin);
    
    cout<<"width is:"<<maxMin[0] - maxMin[1]<<endl;
    // vector<int>ans = leftView(root);
    // for(int ele : ans){
    //     cout<<ele<<" ";
    // }
    vector<int>ans = rightView(root);
    for(int ele : ans){
        cout<<ele<<" ";
    }
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
    // vector<Node*>ans;
    // cout<<rootToNodePath(root, 90, ans)<<endl;
    //  for(Node* node : ans){
    //     cout<<node->data<<" ";
    // }
   
    
    return 0;
}