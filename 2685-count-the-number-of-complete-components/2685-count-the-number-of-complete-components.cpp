class Solution {
public:
    void bfs(unordered_map<int, list<int>> &adj, int nd, vector<int> &viss, int &nodesCnt, int &edgesCnt, int n){
       vector<vector<int>> vis(n, vector<int>(n, 0));
       unordered_set<int> st;
       queue<int> q;
       q.push(nd);
       while(!q.empty()){
            int node = q.front();
            q.pop();
            viss[node] = 1;
            st.insert(node);
            nodesCnt++;
            // if(nd==0){
            //     cout<<node<<endl;
            // }

            for(auto nbr:adj[node]){
                if(!vis[node][nbr] && !vis[nbr][node]){
                    vis[node][nbr] = 1;
                    vis[nbr][node] = 1;
                    edgesCnt++;
                    q.push(nbr);
                }
            }
       }
       nodesCnt = st.size();
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
       unordered_map<int, list<int>> adj;
       for(auto it:edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
       }
       vector<int> viss(n, 0);
       int ans = 0;
       for(int i=0; i<n; i++){
            if(!viss[i]){
                int nodesCnt = 0, edgesCnt = 0;
                bfs(adj, i, viss, nodesCnt, edgesCnt, n);
                // cout<<i<<" "<<nodesCnt<<" "<<edgesCnt<<endl;
                if((nodesCnt*(nodesCnt-1))/2 == edgesCnt) ans++;
            }
       }
       return ans;
    }
};