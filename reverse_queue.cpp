class Solution {
public:
    std::queue<int> rev(std::queue<int> q) {
        stack<int> s;
        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        return q;
    }
};
