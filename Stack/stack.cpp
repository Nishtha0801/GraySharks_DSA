#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    // create
    stack<string>st;

    st.push("Nishtha");
    st.push("goyal");
    st.push("Ashi");
    st.push("Kunal");

    cout<<st.top()<<endl;

}