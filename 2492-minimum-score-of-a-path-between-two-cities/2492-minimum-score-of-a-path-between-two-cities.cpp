class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i=0; i<m; i++){
            int u = roads[i][0], v = roads[i][1], wt = roads[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<int> dist(n+1, INT_MAX);
        // dist[1] = 0;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            // cout<<node<<endl;
            for(auto it:adj[node]){
                int n1 = it.first, wt = it.second;
                // cout<<n1<<endl;
                if(dist[n1]>min(dist[node], wt)){
                    dist[n1]=min(dist[node], wt);
                    q.push(n1);
                }
            }
        }
        // for(auto it:dist){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        return dist[n];
    }
};