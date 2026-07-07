class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        string res;
        long long sum=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!='0'){
                res+=s[i];
                sum+=(s[i]-'0');
            }
        }
        if (res.empty()) return 0;
        long long num=stoll(res);
        num=num*sum;
        return num;
    }
};