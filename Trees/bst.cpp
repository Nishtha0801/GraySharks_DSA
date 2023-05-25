// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data = 0;
        Node* left = nullptr;
        Node* right = nullptr;
        
        Node(int data){
            this->data = data;
        }
};
        
        Node* constructTree(vector<int>&arr, int si, int ei){
            if(si>ei){
                return nullptr;
            }
            int mid = (si+ei)/2;
            
            Node* node = new Node(arr[mid]);
            node->left = constructTree(arr, si, mid-1);
            node->right = constructTree(arr, mid+1,ei);
            
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
        
        // return the maximum node (data)
        int maximum(Node* node){
            Node* curr = node;
            
            while(curr->right != nullptr){
                curr = curr->right;
            }
            return curr->data;
        }
        
        // minimum
        int minimum(Node* node){
            Node* curr = node;
            
            while(curr->left != nullptr){
                curr = curr->left;
            }
            return curr->data;
        }
        
        // find(node, data)
        bool find(Node* node, int data){
            Node* curr = node;
            while(curr != nullptr){
                if(curr->data == data){
                    return true;
                } else if(curr->data < data){
                    curr = curr->right;
                } else{
                    curr = curr->left;
                }
            }
            return false;
        }


int main() {
    // Write C++ code here
    vector<int>arr = {10,20,30,40,50,60,70,80,90,100,110,120};
    Node *root = constructTree(arr,0, arr.size()-1);
   display(root);

    return 0;
}