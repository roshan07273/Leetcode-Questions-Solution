class Solution {
private:
    int efforts[105][105];
    int dx[4] = { 0 , +1 , -1  , 0 };
    int dy[4] = {+1 , 0 , 0 , -1 };
public:
    int dijkstra(vector<vector<int>>& heights){
        int r = heights.size();
        int c = heights[0].size();
        
        priority_queue<pair<int , pair<int , int >>> pq;
        
        pq.push({0 , {0 , 0 }});
        efforts[0][0] = 0;
        
        while(!pq.empty()){
            auto curr = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();
            
            int x = curr.first;
            int y = curr.second;
            
            if(cost > efforts[x][y]){
                continue;
            }
            if(x == r - 1 && y == c - 1) return cost;
            
            for(int i = 0 ; i < 4 ; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if(newx < 0 || newx >= r || newy < 0 || newy >= c)
                    continue;
                
                int maxi = max(efforts[x][y] , abs(heights[x][y] - heights[newx][newy]));
                if(maxi < efforts[newx][newy]){
                    efforts[newx][newy] = maxi;
                    pq.push({-maxi , {newx , newy }});
                }
            }
        }
        return efforts[r - 1][c - 1];
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        for(int i = 0 ; i < heights.size(); i++){
            for(int j = 0 ; j < heights[i].size() ; j++){
                efforts[i][j] = INT_MAX;
            }
        }
        return dijkstra(heights);
    }
};
