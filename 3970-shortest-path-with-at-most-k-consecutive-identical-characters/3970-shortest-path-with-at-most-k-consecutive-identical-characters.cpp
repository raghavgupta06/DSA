class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            mp[u].push_back({v,w});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dis(n,vector<int>(k+1,INT_MAX));
        pq.push({0,{0,1}});
        dis[0][1]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int u=pq.top().second.first;
            int cnt=pq.top().second.second;
            pq.pop();
            if(u==n-1){
                return d;
            }
            for(auto it:mp[u]){
                int v=it.first;
                int w=it.second;
                int nexc=(labels[u]==labels[v])?(cnt+1):1;
                if(nexc<=k){
                    if(d+w<dis[v][nexc]){
                        dis[v][nexc]=d+w;
                        pq.push({d+w,{v,nexc}});
                    }
                }
            }
        }
                       return -1;
    }
};