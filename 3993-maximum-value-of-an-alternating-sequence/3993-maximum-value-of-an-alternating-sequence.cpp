class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1){
            return s;
        }
        long long res=s;
        
         long long ans=n/2;
        res+=(long long)(ans*m);
        long long sub;
        if(n%2!=0){
            sub=n-n/2-2;
        } 
        else{
            sub=n-n/2-1;
        }
        res-=sub;
        return res;
    }
};