// WatchGuard Problem
#include <bits/stdc++.h> 
int countPath(int m,int n,vector<vector<int>> &dp){
	if(m==1 || n==1){
		return dp[m-1][n-1]=1;
	}
	if(dp[m-1][n-1]==0){
		dp[m-1][n-1]=countPath(m-1, n, dp)+countPath(m,n-1,dp);
	}
	return dp[m-1][n-1];
}
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m,vector<int>(n));
	return countPath(m,n,dp);
}
