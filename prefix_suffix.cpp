#include <bits/stdc++.h> 
unordered_map<string,int> umap;
void wordFilter(vector<string> &words)
{
    int s=words.size();
    for(int i=0;i<s;i++){
        string word=words[i];
        int wlen=word.size();
        for(int j=1;j<=wlen;j++){
            string pre=word.substr(0,j);
            for(int k=0;k<wlen;k++){
                string suff=word.substr(k,wlen);
                umap[pre+"|"+suff]=i+1;
            }
        }
    }
}

int find(string &prefix, string &suffix)
{
    string s=prefix+"|"+suffix;
    return umap[s]-1;
}
