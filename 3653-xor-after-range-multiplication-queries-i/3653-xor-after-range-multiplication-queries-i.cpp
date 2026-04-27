#define ll long long
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        ll mod = 1000000007;
        for(int i=0; i<m; i++){
            ll l=queries[i][0], r = queries[i][1], k = queries[i][2], v = queries[i][3];
            for(int j=l; j<=r; j+=k){
                nums[j] = (nums[j] * v)%mod;
            }
        }
        int ans = 0;
        for(auto it:nums){
            ans^=it;
        }
        return ans;
    }
};