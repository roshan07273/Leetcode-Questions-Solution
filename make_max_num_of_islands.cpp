//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
private:
    int getSize(unordered_set<int>  &st , vector<int> &arr){
        int sz = 0;
        for(auto it : st){
            sz += arr[it];
        }
        return sz;
    }
private:
    int get(int i  , int j , vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || i == n || j < 0 || j == m) return 0;
        return grid[i][j];
    }
private:
     int dfs(int i , int j , vector<vector<int>>& grid , int node){
         int n = grid.size();
         int m = grid[0].size();
         
         if(i < 0 || i == n || j < 0 || j == m) return 0;
         if(grid[i][j] != 1) return 0;
         
         grid[i][j] = node;
         
         return 1 + dfs(i + 1 , j , grid , node) +
                    dfs(i - 1 ,  j , grid , node) +
                    dfs(i , j + 1 , grid , node) + 
                    dfs(i , j - 1 , grid , node);
         
     }
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int sz = 0;
        vector<int> arr{0 , 0};
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    arr.push_back(dfs(i , j , grid , arr.size()));
                }
            }
        }
            for(int i =  0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    if(grid[i][j] == 0){
                        unordered_set<int>numIds{
                            get(i + 1 , j , grid),
                            get(i - 1 , j , grid),
                            get(i , j + 1 , grid),
                            get(i , j - 1 , grid)
                        };
                            sz = max(sz ,1 + getSize(numIds , arr));
                        }
                    }
                }
         return sz == 0 ? m * n : sz;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends
