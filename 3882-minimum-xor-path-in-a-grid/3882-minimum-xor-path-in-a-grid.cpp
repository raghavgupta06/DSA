class Solution {
public:
   
    int m,n;
    int solve(int i,int j, int val,vector<vector<int>>&grid, vector<vector<vector<int>>>& dp)
    { 
        if(i<0 || j<0|| i>=m || j>=n ){
            return 1e9;
        }
        if(i==m-1 && j==n-1){
            return val^grid[i][j];
        }
        if(dp[i][j][val]!=-1){
            return dp[i][j][val];
        }
        int ans=1e9;
        ans=min(ans,solve(i+1,j,val^grid[i][j],grid,dp));
        ans=min(ans,solve(i,j+1,val^grid[i][j],grid,dp));
        return dp[i][j][val]=ans;
    }
    int minCost(vector<vector<int>>& grid) {
    
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(1024, -1)));
        return solve(0,0,0,grid,dp);
    }
};