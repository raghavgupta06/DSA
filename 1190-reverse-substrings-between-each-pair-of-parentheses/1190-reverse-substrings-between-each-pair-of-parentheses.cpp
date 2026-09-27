class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        string ans;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
               st.push(ans.length());
            }
            else if(s[i]==')')
            {
                int l=st.top();
                st.pop();
                reverse(begin(ans)+l,end(ans));
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
       
    }
};