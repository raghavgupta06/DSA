class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            if (st.empty() || st.top() < 0 || asteroids[i] > 0) {
                st.push(asteroids[i]);
                continue;
            }
            while (!st.empty() && st.top() > 0 &&
                   st.top() < abs(asteroids[i])) {
                st.pop();
            }

            if (!st.empty() && st.top() > 0 && st.top() == abs(asteroids[i])) {
                st.pop();
                continue;
            }

            if (st.empty() || st.top() < 0) {
                st.push(asteroids[i]);
            }
        }

        vector<int> temp;
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};