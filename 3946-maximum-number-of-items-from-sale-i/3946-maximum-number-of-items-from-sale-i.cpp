class Solution {
public:
    int n;
    int dp[1001][1501];
    int mini=INT_MAX;
    int solve(vector<int>&free,int i,int curr,vector<vector<int>>& items){
        if(i==n){
            return curr/mini;
        }
        if(dp[i][curr]!=-1){
            return dp[i][curr];
        }
        int skip=solve(free,i+1,curr,items);
        int take=0;
        if(curr>=items[i][1]){
            take=1+free[i]+solve(free,i+1,curr-items[i][1],items);
        }
        return dp[i][curr]=max(skip,take);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        memset(dp,-1,sizeof(dp));
        n=items.size();
        vector<int>free(n,0);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(items[j][0]%items[i][0]==0){
                    cnt++;
                }
            }
            free[i]=cnt;
            mini=min(mini,items[i][1]);
        }
        return solve(free,0,budget,items);
        
    }
};