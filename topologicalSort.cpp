class Solution
{
    private:
        void topologicalSort(int node,int vis[],vector<int> adj[],stack<int> &s){
            vis[node]=1;
            for(auto it:adj[node]){
                if(!vis[it]){
                    topologicalSort(it,vis,adj,s); 
                }
            }
            s.push(node);
        }
	public:
	
	//Function to return list containing vertices in Topological order. 
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    stack<int> s;
	    int vis[V]={0};
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            topologicalSort(i,vis,adj,s);
	        }
	    }
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};
