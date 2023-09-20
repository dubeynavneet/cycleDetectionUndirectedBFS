class Solution {
public:
int solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>>& dp){
    if(i==0 && j==0){
        return grid[i][j];
    }
    if(i<0 || j<0){
        return 999999;
    }
    if(dp[i][j]!=-1){ return dp[i][j]; }
    int up,left;
    up=solve(i-1,j,grid,dp);
    left=solve(i,j-1,grid,dp);
    return dp[i][j]=min(left,up)+grid[i][j];
}
    int minPathSum(vector<vector<int>>& grid) {
        int i=grid.size();
    int j=grid[0].size();
    vector<vector<int>> dp(i,vector<int>(j,-1));
    return solve(i-1,j-1,grid,dp);
    }
};
