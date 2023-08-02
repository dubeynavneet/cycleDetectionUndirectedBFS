class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detectCycle(vector<int> adj[],bool visited[],int V,int src){
        visited[src]=true;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjacentNode:adj[node]){
                if(!visited[adjacentNode]){
                    visited[adjacentNode]=true;
                    q.push({adjacentNode,node});
                }else if(parent!=adjacentNode){
                    return true;
                }
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool visited[V]={false};;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detectCycle(adj,visited,V,i)){ return true; }
            }
        }
        return false;
    }
};
