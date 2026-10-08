class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int count=0;
       for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
               if(count>0)
               {
                  res+=s[i];
               }
               count++;
            }
            else{
                count--;
                if(count>0)
                {
                    res+=s[i];
                }
            }  
        }
        return res;
    }
};