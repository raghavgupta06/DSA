class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            char curr=s[i];
            if(st.empty())
            {
                st.push(curr);
            }
            else if(curr==')' && st.top()=='(')
            {
                st.pop();
            }
            else
            {
                st.push(curr);
            }   
        }
        return st.size();
    }
};