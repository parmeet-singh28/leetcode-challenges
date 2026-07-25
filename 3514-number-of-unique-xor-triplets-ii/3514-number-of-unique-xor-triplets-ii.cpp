class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_map<int, bool> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                mp[nums[i]^nums[j]] = true;
            }
        }
        unordered_set<int> st;
        for(auto it:mp){
            int num = it.first;
            for(auto jt:nums){
                st.insert(num^jt);
            }
        }
        return st.size();
    }
};