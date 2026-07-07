class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[i]==1+dp[j]){
                        cnt[i]+=cnt[j];
                    }
                    else if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        cnt[i]=cnt[j];
                    }
                }
            }
        }
        int maxi=*max_element(dp.begin(),dp.end());
        int m=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                m+=cnt[i];
            }
        }
        return m;
    }
};