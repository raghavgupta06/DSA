class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,0);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int maxi=INT_MAX;
            for(int j=1;j<=3;j++){
                if(i-j>=0){
                    int mini=costs[i-1]+dp[i-j]+pow(j,2);
                    if(maxi>mini){
                        maxi=mini;
                    }
                }
                else{
                    continue;
                }
            }
            dp[i]=maxi;
            
        }
        return dp[n];
    }
};