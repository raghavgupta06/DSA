class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long cnt=0;
        long long mod=1e9+7;
        long long temp=k;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=temp){
                temp-=nums[i];
            }
            else{
                long long rem=(nums[i]-temp-1)/k+1;
                cnt+=rem;
                temp=rem*k+temp-nums[i];
            }
        }
        cnt%=mod;
        long long res=(cnt*(cnt+1)/2)%mod;  
        return res;
    }
};