class Solution {
public:
    int minOperations(string s) {
        if(s.length()==2 && s[0]>s[1]){
            return -1;
        }
        int n=s.length();
        string l=s;
        sort(l.begin(),l.end());
        if(l==s){
            return 0;
        }
        string op1=s;
        sort(op1.begin(),op1.end()-1);
        if(op1==l){
            return 1;
        }
        string op2=s;
        sort(op2.begin()+1,op2.end());
        if(op2==l){
            return 1;
        }
        char mini=*min_element(s.begin(),s.end()-1);
        char maxi=*max_element(s.begin()+1,s.end());
        if(mini<=s[n-1] || maxi>=s[0]){
            return 2;
        }
        return 3;
    }
};