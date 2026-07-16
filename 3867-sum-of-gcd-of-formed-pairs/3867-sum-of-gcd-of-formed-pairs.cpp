class Solution {
public:
    int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        vector<int>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            prefix[i]=gcd(maxi,nums[i]);
        }
        sort(prefix.begin(),prefix.end());
        int i=0;
        int j=nums.size()-1;
        long long sum=0;
        while(i<j){
            long long g=gcd(prefix[i],prefix[j]);
            sum+=g;
            i++;
            j--;
        }
        return sum;
    }
};