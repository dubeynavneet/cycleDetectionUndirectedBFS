#include <bits/stdc++.h> 
string zigZagString(string str, int n, int m) {
    // Write your code here.
    if(m==1){
        return str;
    }
    vector<string> ans(m,"");
    int i=0;
    // flag variable to iterate in range of values
    bool flag=false;
    for(char ch:str){
        ans[i]+=ch;
        if(i==0||i==m-1){
            flag=!flag;
        }
        if(flag){
            i++;
        }else{
            i--;
        }
    }
    string result;
    for(int i=0;i<m;i++){
        result+=ans[i];
    }
    return result;
}
