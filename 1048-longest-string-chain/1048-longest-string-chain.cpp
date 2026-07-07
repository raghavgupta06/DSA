class Solution {
public:
     static bool fun(string &word1, string &word2){
        return word1.length()<word2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),fun);
        int maxi=1;
        int n=words.size();
        vector<int>dp(n+1,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                string s=words[i];
                string t=words[j];
                if(s.length()-1==t.length()){
                    int l=0;
                    int k=0;
                    while(l<s.length() && k<t.length()){
                        if(s[l]==t[k]){
                            k++;
                        }
                        l++;
                    }
                    if(k==t.length()){
                        dp[i]=max(dp[i],1+dp[j]);
                        maxi=max(maxi,dp[i]);
                    }
                }
            }
        }
        return maxi;
    }
};