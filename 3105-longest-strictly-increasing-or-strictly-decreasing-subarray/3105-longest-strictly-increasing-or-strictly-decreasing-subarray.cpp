class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int count1=0;
        int res=0;
        int count2=0;
        int res2=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                res++;
            }
            else
            {
                res=0;
            }
            count1=max(res,count1);
            if(nums[i]>nums[i+1])
            {
                res2++;
            }
            else
            {
                res2=0;
            }
            count2=max(res2,count2);
        }
        
        return max(count1,count2)+1;
    }
};