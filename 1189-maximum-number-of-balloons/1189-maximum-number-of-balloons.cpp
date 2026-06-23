class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        vector<int> cnt(26, 0);
        for(int i=0; i<n; i++){
            cnt[text[i]-'a']++;
        }
        int ans = min({cnt['b'-'a'], cnt['a'-'a'], cnt['l'-'a']/2, cnt['o'-'a']/2, cnt['n'-'a']});

        return ans;
    }
};