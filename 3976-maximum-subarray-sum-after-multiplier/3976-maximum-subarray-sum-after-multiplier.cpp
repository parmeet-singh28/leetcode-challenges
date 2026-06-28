#define ll long long
class Solution {
public:
    ll solveTab(vector<int>& nums, int n, int tp, ll k){
        vector<vector<ll>> dp(n+1, vector<ll>(4, LONG_MIN));

        dp[n][1] = 0;
        dp[n][2] = 0;
        dp[n][3] = 0;
        dp[n][0] = LONG_MIN;

        for(int i=n-1; i>=0; i--){
            for(int state=3; state>=0; state--){
                ll val = 0;
                if(tp==0) val = (ll)nums[i]*k;
                else{
                    if(nums[i]>0) val = floor((double)nums[i]/(double)k);
                    else val = val = ceil((double)nums[i]/(double)k);
                }
                ll ans = 0;
                if(state==0) ans += max({val+dp[i+1][2], dp[i+1][0], nums[i]+dp[i+1][1]});
                else if(state==1) ans += max({val+dp[i+1][2], nums[i]+dp[i+1][1], dp[n][state]});
                else if(state==2) ans += max({val+dp[i+1][2], nums[i]+dp[i+1][3], dp[n][state]});
                else ans += max({nums[i]+dp[i+1][3], dp[n][state]});
                dp[i][state] = ans;
            }
        }
        return dp[0][0];
    }
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll ans = solveTab(nums, n, 0, k);
        ans = max(ans, solveTab(nums, n, 1, k));
        return ans;
    }
};