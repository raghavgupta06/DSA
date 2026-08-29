class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>res=nums;
        sort(res.begin(),res.end());
        unordered_map<int,int>group;
        int gp=0;
        unordered_map<int,list<int>>li;
        group[res[0]]=gp;
        li[gp].push_back(res[0]);
        for(int i=1;i<n;i++)
        {
            if(abs(res[i-1]-res[i])>limit)
            {
                gp+=1;
            }
            group[res[i]]=gp;
            li[gp].push_back(res[i]);
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            int gop=group[num];
            ans[i]=*(li[gop].begin());
            li[gop].pop_front();

        }
        return ans;

    }
};