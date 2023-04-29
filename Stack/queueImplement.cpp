#include <iostream>


using namespace std;


class myQueue{
    int *arr;
    int f;
    int b;
    int elements;
    int totalSize;
    
    protected:
     void assignSize(int n){
         this->arr = new int[n];
         this->f = 0;
         this->b = 0;
         this -> elements = 0;
         this -> totalSize = n;
     }
     
     public:
     myQueue(){
         assignSize(10);
     }
     
     myQueue(int n){
         assignSize(n);
     }
     
     bool isEmpty(){
         return this->elements == 0;
     }
     
     int size(){
         return this->elements;
     }
     
     void push(int val){
         if(this->elements == this-> totalSize){
             return;
         }
         this->arr[this->b] = val;
         this -> b = this->b + 1;
         this->elements++;
     }
     
    int front(){
        if(this->elements == 0){
            return -1;
        }
        return this->arr[this->f];
    }
    
    int pop(){
        if(this->elements == 0){
            return -1;
        }
        int rv = this->arr[this->f];
        this->arr[this->f] = 0;
        this->f = this->f + 1;
        this->elements--;
        return rv;
    }
    
    void display(){
        // 
    }
};

void solve(){
    myQueue que;
    que.push(10);
    que.push(20);
    que.push(30);
    que.push(40);
    que.push(50);
    
    que.pop();
    que.pop();
    que.push(60);
    
    while(!que.isEmpty()){
        cout<<que.front()<<",";
        que.pop();
    }
    
}

int main() {
    solve();

    return 0;
}