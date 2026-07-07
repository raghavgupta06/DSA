class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>prev(n,-1);
        int li=0;
        int maxi=1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<1+dp[j]){
                        dp[i]=1+dp[j];
                        prev[i]=j;
                    }
                    if(dp[i]>maxi){
                        maxi=dp[i];
                        li=i;
                    }
                }
            }
        }
        vector<int>ans;
        int fi=li;
        while(fi!=-1){
            ans.push_back(nums[fi]);
            fi=prev[fi];
        }
        return ans;
    }
};