class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        //find all gates to the queue
        for(int i = 0; i <m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,-1,1};

        //bfs
        while(!q.empty()){
            pair<int,int> p = q.front();    
            q.pop();
            int i = p.first;
            int j = p.second;

            for(int k = 0; k < 4; k++){
                int new_i = i + drow[k];
                int new_j = j + dcol[k];

              if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] == INT_MAX){
                grid[new_i][new_j] = grid[i][j] + 1;
                q.push({new_i, new_j});
              }
            }

        }
    }
};
