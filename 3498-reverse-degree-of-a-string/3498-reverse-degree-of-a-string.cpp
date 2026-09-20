class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            sum+=(26-(s[i]-'a'))*(i+1);
        }
        return sum;
    }
};