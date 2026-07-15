class Solution {
public:
    bool check(vector<int>&nums,int k, int mid){
        int cnt=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                cnt++;
                sum=nums[i];
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int i=*max_element(nums.begin(),nums.end());
        int j=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(check(nums,k,mid)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};