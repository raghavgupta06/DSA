class Solution {
public:
int dp[103][103];
int solve(vector<int>&cuts, int i ,int j){
    if(j-i-2<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int res=INT_MAX;
    for(int ind=i+1;ind<=j-1;ind++){
        int cost=(cuts[j]-cuts[i])+solve(cuts,i,ind)+solve(cuts,ind,j);
        res=min(res,cost);
    }
    return dp[i][j]=res;
}
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        return solve(cuts,0,cuts.size()-1);
    }
};