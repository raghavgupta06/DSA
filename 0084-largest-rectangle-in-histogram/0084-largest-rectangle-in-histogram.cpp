class Solution {
public:
    vector<int>solve(vector<int>&heights, int n){
        stack<int>st;
        vector<int>res(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
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
    vector<int>solve2(vector<int>&heights, int n){
        stack<int>st;
        vector<int>res(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
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
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nsl=solve(heights,n);
        vector<int>psl=solve2(heights,n);
        int maxi=0;
        for(int i=0;i<n;i++){
            int sum=(abs(nsl[i]-psl[i])-1)*heights[i];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};