class Solution {
public:
    bool solve(vector<int> &nums, int num){
        return nums[0]<num;
    }
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        // unordered_map<int, int> odd, even;
        vector<int> odd, even;
        for(int i=0; i<n; i++){
            if(nums[i]&1) odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        if(odd.size()==0 || even.size()==0) return true;
        // odd - odd = even
        // odd - even = odd
        bool ans = true;
        // even
        for(int i=0; i<n; i++){
            if(nums[i]&1) continue;
            bool num = solve(odd, nums[i]);
            if(num==0){
                ans = false;
                break;
            }
        }
        // cout<<ans<<endl;
        if(ans==1) return 1;
        // odd
        ans = true;
        for(int i=0; i<n; i++){
            if(nums[i]%2!=0) continue;
            bool num = solve(even, nums[i]);
            if(num==0){
                ans = false;
                break;
            }
        }
        return ans;
    }
};