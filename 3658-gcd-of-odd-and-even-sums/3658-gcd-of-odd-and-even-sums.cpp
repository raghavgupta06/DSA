class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int cnt1=0;
        int cnt2=0;
        for(int i=1;i<=2*n;i++){
            if(i%2==0){
                cnt1+=i;
            }
            else{
                cnt2+=i;
            }
        }
        int ans=gcd(cnt1,cnt2);
        return ans;
    }
};