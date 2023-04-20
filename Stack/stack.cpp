#include<iostream>
#include<string>
#include<stack>

using namespace std;

void display(stack<string>& st){
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return;
}

int main(){
    // create
    stack<string>st;

    st.push("Nishtha");
    st.push("goyal");
    st.push("Ashi");
    st.push("Kunal");

    // cout<<st.top()<<endl;

    // removes element from stack
    st.pop();

    cout<<st.top()<<endl;

    cout<<st.size()<<endl;

    if(st.empty()){ // returns true if the stack is empty
        cout<<"Stack is empty";
    } else {
        cout<<"Stack is not empty";
    }

    // elements print kase kra skte h?
    display(st);




}