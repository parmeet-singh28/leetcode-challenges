class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size(), ans = 1, i=0,  j=0;
        vector<int> freq(26, 0);
        for(int j=0; j<n; j++){
            freq[s[j]-'a']++;
            while(freq[s[j]-'a']>2){
                freq[s[i++]-'a']--;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};