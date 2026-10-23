class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int an=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                if(an==-1){
                    an=nums[i];
                } 
                else{
                    an=an&nums[i];
                }
            }
        }
        return max(0,an);
    }
};