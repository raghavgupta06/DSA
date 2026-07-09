class Solution {
public:
 vector<int>parent;
 vector<int>size;
 int findp(int u){
    if(parent[u]==u){
        return u;
    }
    return parent[u]=findp(parent[u]);
 }
 void bysize(int u, int v){
    int pu=findp(u);
    int pv=findp(v);
    if(pu==pv){
        return;
    }
    if(size[pu]<size[pv]){
        parent[pu]=pv;
        size[pu]+=size[pv];
    }
    else{
        parent[pv]=pu;
        size[pv]+=size[pu];
    }
 }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<bool>ans(queries.size(),false);
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                bysize(i,i-1);
            }
        }
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            int pu=findp(u);
            int pv=findp(v);
            if(pu==pv){
                ans[i]=true;
            }
            else{
                ans[i]=false;
            }
        }
        return ans;
    }
};