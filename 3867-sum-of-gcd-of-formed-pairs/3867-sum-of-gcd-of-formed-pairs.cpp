#define ll long long
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size(), maxi = INT_MIN;
        vector<ll> prefixGcd(n, 0);
        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = __gcd(maxi, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        ll sum = 0;
        int i=0, j=n-1;
        while(i<j){
            sum += __gcd(prefixGcd[i++], prefixGcd[j--]);
        }
        return sum;
    }
};