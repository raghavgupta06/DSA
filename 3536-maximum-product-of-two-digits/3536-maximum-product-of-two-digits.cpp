class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        int maxi=0;
        int smaxi=0;
        for(int i=0;i<s.length();i++){
            int x=s[i]-'0';
            if(maxi<x){
                smaxi=maxi;
                maxi=x;
            }
            else if(smaxi<x){
                smaxi=x;
            }
        }
        return maxi*smaxi;
    }
};