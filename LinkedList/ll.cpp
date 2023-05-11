// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class linkedList {
    // Node class
    class Node{
        public: 
            int data = 0;
            Node *next = nullptr;
            
            Node(int data){
                this->data = data;
            }
    };
    
    Node *head = nullptr;
    Node *tail = nullptr;
    int eleCount = 0; // size
    
    int size(){
        return this->eleCount;
    }
    
    bool isEmpty(){
        return this->eleCount == 0;
    }
    
    private:
    void addFirstNode(Node *node){
        if(this->head == nullptr){
            this->head = node;
            this->tail = node;
        } else{
            node->next = this->head;
            this->head = node;
        }
        this->eleCount++;
    }
    
    public:
    void addFirst(int val){
        Node *node = new Node(val);
        addFirstNode(node);
    }
    
    private:
    void addLastNode(Node *node){
        if(this->head == nullptr){
            this->head = node;
            this->tail = node;
        } else{
            this->tail->next = node;
            this->tail = node;
        }
        this->eleCount++;
    }
    
    public:
    void addLast(int val){
        Node *node = new Node(val);
        addLastNode(node);
    }
    
    
    
     
    
    
};

int main() {
    // Write C++ code here
    cout << "Hello world!";

    return 0;
}