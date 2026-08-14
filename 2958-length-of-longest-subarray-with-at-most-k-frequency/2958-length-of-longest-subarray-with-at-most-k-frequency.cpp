class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, i=0, j=0;
        unordered_map<int, int> freq;
        for(int j=0; j<n; j++){
            freq[nums[j]]++;
            while(freq[nums[j]]>k){
                freq[nums[i++]]--;
            }
            // cout<<j-i+1<<endl;
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};