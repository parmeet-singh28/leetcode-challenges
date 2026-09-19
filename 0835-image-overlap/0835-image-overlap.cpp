class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> vec1, vec2;
        vector<vector<int>> cnt(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img1[i][j]) vec1.push_back({i, j});
                if(img2[i][j]){
                    vec2.push_back({i, j});
                    cnt[i][j] = 1;
                }
            }
        }
        n = vec1.size();
        int m = vec2.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int aDiff=0, bDiff=0;
            for(int j=0; j<m; j++){
                aDiff = vec2[j].first-vec1[i].first;
                bDiff = vec2[j].second-vec1[i].second;
                int tp = 0;
                for(int k=0; k<n; k++){
                    int x = vec1[k].first+aDiff, y = vec1[k].second+bDiff;
                    if(x>=0 && x<img2.size() && y>=0 && y<img2.size()){
                        if(cnt[x][y]) tp++;
                    }
                }
                ans = max(ans, tp);
            }
        }
        return ans;
    }
};