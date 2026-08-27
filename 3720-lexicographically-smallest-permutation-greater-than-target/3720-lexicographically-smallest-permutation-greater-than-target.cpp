
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        string a = s;
        string b = target;
        sort(a.rbegin(), a.rend());
        if (b >= a) {
            return "";
        }
        vector<int> c(26, 0);
        for (int i = 0; i < s.length(); i++) {
            c[s[i] - 'a']++;
        }
        string ans = "";
        for (int i = 0; i < target.length(); i++) {
            int co = target[i] - 'a';
            if (c[co] > 0) {
                c[co]--;
                string suffix = "";
                for (int k = 25; k >= 0; k--) {
                    suffix += string(c[k], 'a' + k);
                }
                string perm = target.substr(i + 1);
                if (suffix > perm) {
                    ans += target[i];
                    continue;
                } else {
                    c[co]++;
                }
            }
            for (int j = co + 1; j < 26; j++) {
                if (c[j] > 0) {
                    char l = 'a' + j;
                    ans += l;
                    c[j]--;
                    for (int k = 0; k < 26; k++) {
                        char ch = 'a' + k;
                        ans += string(c[k], ch);
                    }
                    return ans;
                }
            }
        }

        return "";
    }
};