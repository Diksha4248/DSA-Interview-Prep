#include <bits/stdc++.h>
using namespace std;

int main(){

    string s = "hello how are you";
    s+=" ";
    stack <string> st;


    int n = s.size();
    string str = " ";
    for(int i=0;i<n;i++){
        if(s[i] == ' '){
            st.push(str);
            str = " ";
        }

        else str+=s[i];
    }


    string result = " ";
    while(!st.empty()){
        string x = st.top();
        result+= x;
        st.pop();
    }
   
    cout<<result;
    // reverse(str.begin(),str.end());
    return 0;
}