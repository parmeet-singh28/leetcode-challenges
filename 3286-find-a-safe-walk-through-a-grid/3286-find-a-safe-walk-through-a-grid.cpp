class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = grid[0][0];

        while(!q.empty()){
            int i = q.front().first, j = q.front().second;
            q.pop();

            for(int k=0; k<4; k++){
                int ii = i+dx[k], jj = j+dy[k];
                // if(i==2 && j==1){
                //     cout<<"ii-"<<ii<<" jj-"<<jj<<endl;
                //     // cout<<(dist[ii][jj]>dist[i][j]+grid[ii][jj])<<endl;

                // }
                if(ii>=0 && ii<n && jj>=0 && jj<m && dist[ii][jj]>dist[i][j]+grid[ii][jj]){
                    q.push({ii, jj});
                    // cout<<"everfer"<<endl;
                    dist[ii][jj] = dist[i][j]+grid[ii][jj];
                }
            }
        }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<dist[n-1][m-1]<<endl;
        if(dist[n-1][m-1]<health) return true;
        return false;
    }
};