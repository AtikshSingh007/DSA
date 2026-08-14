class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26,0);
        int l=0,ans=1,n=s.size();
        for(int r=0;r<n;r++)
        {
            freq[s[r]-'a']++;
            while(freq[s[r]-'a']>2)
            {
                freq[s[l]-'a']--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};