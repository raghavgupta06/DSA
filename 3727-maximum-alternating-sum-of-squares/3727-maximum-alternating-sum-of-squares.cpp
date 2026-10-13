class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        if(nums.size()==1){
            return (long long)nums[0]*nums[0];
        }
        sort(nums.begin(),nums.end());
        long long res=0;
        for(int i=nums.size()-1;i>=nums.size()/2;i--){
            res+=(long long)(nums[i]*nums[i]);
        }
        for(int i=nums.size()/2-1;i>=0;i--){
            res-=(long long)(nums[i]*nums[i]);
        }
        return res;
    }
};