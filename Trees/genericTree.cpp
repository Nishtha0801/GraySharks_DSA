// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<stack>

using namespace std;

class Node{
    public: 
        int data = 0;
        vector<Node*>childs;
        
        Node(int data){
            this->data = data;
        }
};

Node* constructTree(vector<int>&arr){
    stack<Node*>st;
    for(int i=0;i<arr.size()-1;i++){
        int ele = arr[i];
        if(ele != -1){
            st.push(new Node(ele));
        } else{
            Node* node = st.top();
            st.pop();
            st.top()->childs.push_back(node);
        }
    }
    
    return st.top(); //root
}

// displayyyyyyyyy
void display(Node* node){
    string str ="";
    str+= (to_string(node->data) + "->");
    
    for(Node* child: node->childs){
        str+=(to_string(child->data) + " ");
    }
    
    cout<<str<<endl;
    
    for(Node* child: node->childs){
        display(child);
    }
    
}

//size =========
//find================

int main() {
    // Write C++ code here
  vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    
    Node* root = constructTree(arr);
    display(root);

    return 0;
}