class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int c = 1, n = s.size();
        int ans = 0;
        for (auto i : s)
            if (i == '1')
                ans++;
        vector<int> chunks;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1])
                c++;
            else {
                chunks.push_back(c);
                c = 1;
            }
        }
        chunks.push_back(c);
        n = chunks.size();
        // for(auto i:chunks)cout<<i<<" ";
        int extra = 0;
        int i = ((s[0] == '0') ? 1 : 2);
        for (; i < n - 1; i += 2) {
            extra = max(extra, chunks[i - 1] + chunks[i + 1]);
        }
        return ans + extra;
    }
};