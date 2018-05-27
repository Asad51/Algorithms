#include<bits/stdc++.h>
using namespace std;

class Stack{
    int siz, mx_size;
    int arr[100000], index;
public:
    Stack(){
        siz = 0;
        mx_size = 100000;
        index = -1;
    }
    Stack(int n){
        siz = 0;
        mx_size = n;
        index = -1;
    }
    void push(int n){
        if(index>=mx_size){
            cout<<"Overflow.\n";
            return;
        }
        arr[++index] = n;
        siz++;
    }
    
    void pop(){
        if(index<0)
        {
            cout<<"Underflow.\n";
            return;
        }
        index--;
        siz--;
    }
    
    int top(){
        return arr[index];
    }
    
    int size(){
        return siz;
    }
    
    bool empty(){
        if(!siz)
            return true;
        return false;
    }
};

int main(){
    Stack st;
    for(int i=1; i<=10; i++){
        st.push(i);
    }
    cout<<st.size()<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}