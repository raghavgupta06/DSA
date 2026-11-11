class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long tc=(long long)(cost1+cost2);
        long long mini=min(need1,need2);
        long long m1=min(tc*mini,costBoth*mini);
        long long req=0;
        if(need1>need2){
            req=(long long)(need1-need2)*cost1;
        }
        else{
            req=(long long)(need2-need1)*cost2;
        }
        long long r2=abs(need1-need2)*(long long)costBoth;
        req=min(req,r2);
        return req+m1;
        
    }
};