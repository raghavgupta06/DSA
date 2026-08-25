class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int num=k;
        int count=1;
        while(true){
            int req=num*count;
            if(mp[req]==0){
                return req;
            }
            count++;
        }
        return -1;
    }
};