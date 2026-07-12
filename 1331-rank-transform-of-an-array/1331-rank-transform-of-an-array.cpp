class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map<int, list<int>> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        int cnt = 1;
        for(auto it:mp){
            for(auto jt:it.second){
                arr[jt] = cnt;
            }
            cnt++;
        }
        return arr;
    }
};