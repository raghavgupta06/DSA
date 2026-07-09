class Solution {
public:
     vector<int>solve(vector<int>&arr, int n){
        vector<int>res(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
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
     vector<int>solve2(vector<int>&arr, int n){
        vector<int>res(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
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
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nsl=solve(arr,n);
        vector<int>psl=solve2(arr,n);
        long long sum=0;
        long long mod=1e9+7;
        for(int i=0;i<n;i++){
            long long ok=abs(i-psl[i]);
            long long ok2=abs(nsl[i]-i);
            long long r=arr[i]*ok*ok2*1LL;
            sum=(sum+r)%mod;
        }
        return sum;
        
    }
};