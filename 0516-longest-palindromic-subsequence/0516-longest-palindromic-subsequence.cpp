class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=1;i<=n;i++){
            for(int j=0;j+i-1<n;j++){
                int k=i+j-1;
                if(j==k){
                    dp[j][k]=1;
                }
                else if(s[j]==s[k]){
                    dp[j][k]=2+dp[j+1][k-1];
                }
                else{
                    dp[j][k]=max(dp[j+1][k],dp[j][k-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};