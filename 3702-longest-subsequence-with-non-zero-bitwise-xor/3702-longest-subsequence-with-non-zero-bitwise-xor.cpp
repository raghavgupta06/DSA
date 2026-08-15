class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        bool check=false;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            ans=ans^nums[i];
            if(nums[i]>0){
                check=true;
            }
        }
       if(!check){
           return 0;
       }
        else if(ans==0){
            return nums.size()-1;
        }
        return nums.size();
    }
};