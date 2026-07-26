class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int>nigga=nums;
        sort(nigga.begin(), nigga.end());
        int n = nigga.size();
        if(nigga[n-1]*nigga[n-2]*nigga[n-3]>nigga[n-1]*nigga[1]*nigga[0]){
            return nigga[n-1]*nigga[n-2]*nigga[n-3];
        }
        else{
            return nigga[n-1]*nigga[1]*nigga[0];
        }
    }
};