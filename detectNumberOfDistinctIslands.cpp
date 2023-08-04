class Solution {
private:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>>& grid,vector<pair<int,int>> &v,int row0,int col0){
        vis[row][col]=1;
        v.push_back(make_pair(row-row0,col-col0));
        int n=grid.size();
        int m=grid[0].size();
        // values of delrow and delcol are stored in specific order to go with same direction everytime
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && ncol<m && nrow<n && ncol>=0 && vis[nrow][ncol]!=1 && grid[nrow][ncol]!=0){
                dfs(nrow,ncol,vis,grid,v,row0,col0);
            }
        }
    }    
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // using set to not store duplicate pair
        set<vector<pair<int,int>>> st;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                vector<pair<int,int>> v;
                // last i,j are passed to ensure the base indexes
                dfs(i,j,visited,grid,v,i,j);
                st.insert(v);
                }
            }
        }
        return st.size();
    }
};
