#define ll long long
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        
        for(int i=0; i<n; i++){
            ll lcm = nums[i], gcd = nums[i], prod = 1, tp=0;
            for(int j=i; j<n; j++){
                gcd = __gcd(gcd, (ll)nums[j]);
                lcm = (lcm*(ll)nums[j])/__gcd(lcm, (ll)nums[j]);
                prod *= nums[j];
                if(prod>=1e14) break;
                tp++;
                if(prod == lcm * gcd) ans = max(ans, tp);
            }
        }
        return ans;
    }
};