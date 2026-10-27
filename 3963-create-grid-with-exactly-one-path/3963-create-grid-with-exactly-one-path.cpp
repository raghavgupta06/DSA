class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        for(int i=0;i<m-1;i++){
            string res=".";
            for(int i=1;i<n;i++){
                res+='#';
            }
            ans.push_back(res);
        }
        string dummy="";
        for(int i=0;i<n;i++){
            dummy+='.';
        }
        ans.push_back(dummy);
        return ans;
    }
};