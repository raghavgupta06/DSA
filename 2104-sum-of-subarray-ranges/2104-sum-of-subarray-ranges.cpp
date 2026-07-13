class Solution {
public:
     vector<int>solve(vector<int>&nums, int n){
        vector<int>res(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty()){
                res[i]=-1;
            }
            else{
                res[i]=st.top();
            }
            st.push(i);
        }
        return res;
     }
     vector<int>solve2(vector<int>&nums, int n){
        vector<int>res(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()){
                res[i]=n;
            }
            else{
                res[i]=st.top();
            }
            st.push(i);
        }
        return res;
     }
          vector<int>solve3(vector<int>&nums, int n){
        vector<int>res(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(st.empty()){
                res[i]=-1;
            }
            else{
                res[i]=st.top();
            }
            st.push(i);
        }
        return res;
     }
     vector<int>solve4(vector<int>&nums, int n){
        vector<int>res(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                res[i]=n;
            }
            else{
                res[i]=st.top();
            }
            st.push(i);
        }
        return res;
     }
    long long subArrayRanges(vector<int>& nums) {
         int n=nums.size();
        vector<int>nsl=solve(nums,n);
        vector<int>psl=solve2(nums,n);
        vector<int>osl=solve3(nums,n);
        vector<int>ksl=solve4(nums,n);
        long long sum=0;
        for(int i=0;i<n;i++){
            long long ok=abs(i-psl[i]);
            long long ok2=abs(nsl[i]-i);
            long long r=nums[i]*ok*ok2*1LL;
            long long maxi=abs(i-osl[i]);
            long long maxi2=abs(ksl[i]-i);
            long long l=nums[i]*maxi*maxi2*1LL;
            sum=(sum+l-r);
        }
        return sum;
    }
};