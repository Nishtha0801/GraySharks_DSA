// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class linkedList {
    // Node class
    class Node{
        public: 
            int data = 0;
            Node* next = nullptr;
            
            Node(int data){
                this->data = data;
            }
    };
    
    Node* head = nullptr;
    Node* tail = nullptr;
    int eleCount = 0; // size
    
    
    
    int size(){
        return this->eleCount;
    }
    
    bool isEmpty(){
        return this->eleCount == 0;
    }
    
    public:
    string toString(){
        Node* curr = this->head;
        string ans = "";
        ans+="[";
        while(curr != nullptr){
            ans+=to_string(curr->data);
            if(curr->next != nullptr){
                ans+=",";
            }
            curr = curr->next;
        }
        ans+="]";
        return ans;
    }
    
    private:
    void addFirstNode(Node* node){
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
    void addLastNode(Node* node){
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
        Node* node = new Node(val);
        addLastNode(node);
    }
    
    private:
    Node* removeFirstNode(){
        Node* node = this->head;
        
        if(this->eleCount == 1){
            this->head= nullptr;
            this->tail = nullptr;
        } else {
            this->head = this->head->next;
            node->next = nullptr;
        }
        
        this->eleCount--;
        return node;
    }
    
    public:
    int removeFirst(){
        if(this->eleCount == 0){
            throw("nullPointer Exception:-1");
        }
        
        Node* node = removeFirstNode();
        int rv = node->data;
        delete node;
        return rv;
        
    }
    
    private:
    Node* getFirstNode(){
        return this->head;
    }
    
    public:
    int getFirst(){
        if(this->eleCount == 0){
            throw("null pointer exception");
        }
        Node* node = getFirstNode();
        return node->data;
    }
    
    private:
    Node* getLastNode(){
        return this->tail;
    }
    
    public:
    int getLast(){
        if(this->eleCount == 0){
            throw("null pointer exception");
        }
        Node* node = getLastNode();
        return node->data;
    }
    
    private:
    Node* getNodeAt(int idx){
        Node* curr = this->head;
        while(idx-- > 0){
            curr = curr->next;
        }
        return curr;
    }
    
    public:
    int getAt(int idx){
        if(idx<0 || idx>= this->eleCount){
            throw("Invalid location");
        }
        
        Node* node = getNodeAt(idx);
        return node->data;
    }
    
      // removeLastNode();
      
      private:
      Node* removeLastNode(){
          Node* node = this->tail;
          if(this->eleCount == 1){
              this->head = nullptr;
              this->tail = nullptr;
          } else {
              Node* prev = getNodeAt(this->eleCount - 2);
              
              this->tail = prev;
              prev->next = nullptr;
          }
          this->eleCount--;
          return node;
      }
      
      public:
      int removeLast(){
          if(this->eleCount == 0){
              throw("nullpointer exception");
          }
          Node* node = removeLastNode();
          int rv = node->data;
          delete node;
          return rv;
      }
      
      private:
      void addNodeAt(Node* node, int idx){
          if(idx == 0){
              addFirstNode(node);
          }
          else if( idx == this->eleCount){
              addLastNode(node);
          } else {
              Node* prev = getNodeAt(idx-1);
              Node* curr = prev->next;
              
              prev->next = node;
              node->next = curr;
               this->eleCount++;
          }
         
      }
      
    // addNodeAt();
    public: 
    void addAt(int data, int idx){
        if(idx<0 || idx>this->eleCount){
            throw("Invalid location");
        }
        
        Node* node = new Node(data);
        addNodeAt(node, idx);
    }
 
   // removeNodeAt();
   private:
   Node* removeNodeAt(int idx){
       if(idx == 0){
           return removeFirstNode();
       } else if(idx == this->eleCount -1){
           return removeLastNode();
       } else {
           Node* prev = getNodeAt(idx-1);
           Node* curr = prev->next;
           
           prev->next = curr->next;
           curr->next = nullptr;
           this->eleCount--;
           return curr;
       }
   }
   
   public:
   int removeAt(int idx){
       if(idx<0 || idx>this->eleCount){
           throw("Invalid location");
       }
       Node* node = removeNodeAt(idx);
       int rv = node->data;
       delete node;
       return rv;
   }
};

int main() {
   linkedList ll;
   for(int i=0;i<=10;i++){
       ll.addLast(i*10);
   }
   
   for(int i=10;i>=0;i--){
       ll.addFirst(i*10);
   }
   
   cout<<ll.toString()<<endl;

    return 0;
}