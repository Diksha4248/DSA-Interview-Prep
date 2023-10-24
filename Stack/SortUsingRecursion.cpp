#include<bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=XNAv8NrAwng


void PrintStack(stack<int> s)
{
    // If stack is empty
    if (s.empty())
        return;
 
    int x = s.top();
    s.pop();
    cout << x << ' ';
    PrintStack(s);
    s.push(x);
}

void insert_correct_position(int x, stack<int> &s){
    if(s.size()==0 or s.top()<x){
        s.push(x);
    }

    else{
        int a = s.top();
        s.pop();
        insert_correct_position(x,s);
        s.push(a);
    }
}

void sort_stack(stack <int> &s){
    if(s.size()>0){
        int x = s.top();
        s.pop();
        sort_stack(s);
        insert_correct_position(x,s);
    }
}

int main(){
    
    stack <int> st;
    st.push(69);
    st.push(75);
    st.push(40);
    st.push(88);

    PrintStack(st);

    sort_stack(st);
    cout<<"\n";
    PrintStack(st);
    return 0;
}