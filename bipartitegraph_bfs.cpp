#include "bits/stdc++.h"
bool bfsBipartite(int start,vector<vector<int>> &edges,vector<int> color){
	color[start]=0;
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<edges[x].size();i++){
                    if (edges[x][i] == 1 && color[i]==-1) {
                      color[i] = !color[x];
                      q.push(i);
                    }
                  else if(color[i]==color[x] && edges[x][i]){
					  return false;
				  }
                }
        }
		return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	vector<int> coloring(edges.size(),-1);
	for(int i=0;i<edges.size();i++){
		 if(coloring[i]==-1){
            if (bfsBipartite(i, edges, coloring)==false) {
                return false;
            }
          }
        }
	return true;
}
