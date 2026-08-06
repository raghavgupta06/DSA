class Solution {
public:
    int check(int n){
        int product=1;
        while(n){
            product=product*(n%10);
            n/=10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        while(true){
            int c=check(n);
            if(c%t==0){
                return n;
            }
            n++;
        }
        return n;
    }
};