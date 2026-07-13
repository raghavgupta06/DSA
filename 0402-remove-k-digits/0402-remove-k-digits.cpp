class Solution {
public:
    string removeKdigits(string num, int k) {
       string s="";
       for(int i=0;i<num.length();i++){
           while(s.length()>0 && k>0 && s.back()>num[i]){
               s.pop_back();
               k--;
           }
           if(num[i]!='0' || s.length()>0 ){
              s.push_back(num[i]);
           }
       } 
       while(s.length()>0 && k>0){
        s.pop_back();
        k--;
       }
       if(s.empty()){
        return "0";
       }
       return s;
    }
};