class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]-1!=nums[i-1]){
                break;
            }
            sum+=nums[i];
        }
        while(sum){
            if(mp[sum]==0){
                return sum;
            }
            sum++;
        }
        return 0;
    }
};