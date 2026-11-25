class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        unordered_map<char, int> mp;
        int i = 0;
        int ans = 0;

        for (int j = 0; j < s.length(); j++) {
            if (mp.find(s[j]) != mp.end() && mp[s[j]] >= i) {
                // Move i to the right of the last occurrence of s[j]
                i = mp[s[j]] + 1;
            }
            // Update the last occurrence of s[j]
            mp[s[j]] = j;
            // Calculate the length of the current substring
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};