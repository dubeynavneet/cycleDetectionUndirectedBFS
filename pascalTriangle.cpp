class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex+1,vector<int>(rowIndex+1,0));
        dp[0][0]=1;
        if(rowIndex==0)
            return dp[0];
        // dp[0][0]=1;
        dp[1][0]=1;
        // dp[1][1]=1;
        for(int i=1;i<rowIndex+1;i++){
            for(int j=0;j<=i;j++){
                if(i==j){
                    dp[i][j]=1;
                }else if(j==0){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
            }
        }
        return dp[rowIndex];
    }
};
