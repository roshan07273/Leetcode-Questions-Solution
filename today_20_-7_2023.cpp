class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      stack<int> st;
    for (int asteroid : asteroids) {
        bool destroyCurrent = false;
        while (!st.empty() && asteroid < 0 && st.top() > 0) {
            if (st.top() > -asteroid) {
                destroyCurrent = true;
                break;
            } else if (st.top() < -asteroid) {
                st.pop();
            } else {
                st.pop();
                destroyCurrent = true;
                break;
            }
        }
        if (!destroyCurrent) {
            st.push(asteroid);
        }
    }
    
    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; --i) {
        result[i] = st.top();
        st.pop();
    }
    
    return result;
    }
};
