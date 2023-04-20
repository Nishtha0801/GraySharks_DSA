// Online C++ compiler to run C++ program online
#include<iostream>

using namespace std;

class Mystack{
    int N = 10000; //maximum cap
    int *arr;
    int sz = 0; // size of stack
    int tos = -1; // idx
    
    public:
        Mystack(){
            this->arr = new int[N];
        }
        
        //Parameterised constructor
        Mystack(int size){
            this->arr = new int[size];
            this->N = size;
        }
        
        int size(){
            return this->sz;
        }
        
        bool empty(){
            return sz == 0;
        }
        
        void push(int val){
            if(sz == N){
                return;
            }
            tos++;
            sz++;
            arr[tos] = val;
        }
        
        void pop(){
            if(sz == 0){
                return;
            }
            int rv = arr[tos];
            sz--;
            tos--;
        }
        
        int top(){
            if(sz == 0){
                return -1;
            }
            return arr[tos];
        }
};

void solve(){
    Mystack st(5);
    for(int i=1;i<=10;i++){
        st.push(10+i);
    }
    
    while(st.size() != 0){
        cout<<st.top() << " ";
        st.pop();
    }
}


int main(){
    solve();
    return 0;
}