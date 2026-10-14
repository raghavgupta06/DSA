class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9<sum){
            return "";
        }
        string res;
        for(int i=0;i<num;i++){
            if(sum>=9){
                res+='9';
                sum-=9;
            }
            else{
                char s='0'+sum;
                res+=s;
                sum=0;
            }
            
        }
        return res;
        
    }
};