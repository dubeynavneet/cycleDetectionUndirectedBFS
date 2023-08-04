class Solution{
public:
bool detectCycle(vector<int> adj[],int visited[],int src,int parent){
        visited[src]=true;
        for(auto adjacencyNode:adj[src]){
            if(!visited[adjacencyNode]){
                visited[adjacencyNode]=true;
                if(detectCycle(adj,visited,adjacencyNode,src)==true){
                    return true;
                }
            }else{
                if(parent!=adjacencyNode){
                    return true;
                }
            }
        }
        return false;
}
bool isCycle(int V, vector<int> adj[]) {
        int visited[V]={0};
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detectCycle(adj,visited,i,-1)) return true;
            }
        }
        return false;
}
};
