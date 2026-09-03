class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        bool check =false;
        for(int i=1;i<nums1.size();i++){
            if((nums1[i]-nums1[i-1])%2==1){
                check = true;
                break;
            }
        }
        if(!check){
            return true;
        }
        
        if(nums1[0]%2==0){
            return false;
        }
        return true;
    }
};