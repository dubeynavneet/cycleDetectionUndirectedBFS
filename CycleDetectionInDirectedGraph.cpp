class Solution {
    private:
        bool dfsCheck(int node ,vector<int> adj[],int vis[],int visPath[]){
            vis[node]=1;
            visPath[node]=1;
            for(int it : adj[node]){
                if(!vis[it]){
                    if(dfsCheck(it,adj,vis,visPath)==true){ return true; }
                }else{
                    if(visPath[it]){
                        return true;
                    }
                }
            }
            visPath[node]=0;
            return false;
        }
    public:
    // Function to detect cycle in a directed graph.
        bool isCyclic(int V, vector<int> adj[]) {
            int vis[V];
            int visPath[V];
            for(int i=0;i<V;i++){
                vis[i]=0;
                visPath[i]=0;
            }
            for(int i=0;i<V;i++){
                if(!vis[i]){
                    if(dfsCheck(i,adj,vis,visPath)==true){ return true; }
                }
            }
            return false;
        }
};
