#include <bits/stdc++.h> 
unordered_map<string,vector<int>> umap;
void receiveMessage(string user, int time) {
	umap[user].push_back(time);
}

vector<int> getMessageCount(int l, int r, string user, int k) {
	vector<int> answer;
	for(int i=l;i<=r;i=i+k){
		int res=0;
		for(int j=i;j<i+k && j<=r ;j++){
			for(auto it:umap[user]){
				if(it==j){
					res++;
				}
			}
		}
		answer.push_back(res);
	}
	return answer;
}

