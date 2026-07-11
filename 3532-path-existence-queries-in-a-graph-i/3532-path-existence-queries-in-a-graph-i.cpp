class Solution {
public:
    int fp(int node, vector<int> &par){
        if(par[node]==node) return node;
        return par[node] = fp(par[node], par);
    }
    void us(int u, int v, vector<int> &par, vector<int> &rank){
        u = fp(u, par);
        v = fp(v, par);

        if(rank[u]>rank[v]) par[v] = u;
        else if(rank[u]>rank[v]) par[u] = v;
        else{
            par[u] = v;
            rank[v]++;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> par(n);
        vector<bool> ans(m);
        vector<int> rank(n, 0);
        for(int i=0; i<n; i++){
            par[i] = i;
        }
        int i=0;
        while(i<n-1){
            int tp = nums[i]+maxDiff;
            int idx = upper_bound(nums.begin(), nums.end(), tp)-nums.begin();
            idx--;
            for(int k=i; k<idx; k++){
                us(k, k+1, par, rank);
            }
            if(idx==i) i++;
            else i = idx;
        }
        for(int i=0; i<m; i++){
            int u = queries[i][0], v = queries[i][1];
            if(fp(u, par)==fp(v, par)) ans[i] = true;
            else ans[i] = false;
        }
        return ans;
    }
};