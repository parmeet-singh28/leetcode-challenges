class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        string s1 = "";
        string ch = "#";
        for(int i=0; i<26; i++){
            int cnt = freq[i]/2;
            if(freq[i]%2!=0) ch = i+'a';
            while(cnt--) s1.push_back(i+'a');
        }
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        // cout<<ch<<endl;
        if(ch!="#") s1 = s1 + ch + s2;
        else s1 = s1 + s2;

        return s1;
    }
};