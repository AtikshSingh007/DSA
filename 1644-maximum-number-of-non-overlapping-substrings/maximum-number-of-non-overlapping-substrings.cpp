class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> l(26, -1), r(26, -1);

        for(int i = 0; i < n; i++) {
            if (l[s[i] - 'a'] == -1) l[s[i] - 'a'] = i;
            r[s[i] - 'a'] = i;
        }

        vector<vector<int>> range;
        
        for(int i = 0; i < 26; i++) {
            if(l[i] == -1) continue;
            
            int left = l[i];
            int right = r[i];
            bool valid = true;
            
            for(int j = left; j <= right; j++) {
                if (l[s[j] - 'a'] < left) {
                    valid = false;
                    break;
                }
                right = max(right, r[s[j] - 'a']);
            }
            
            if(valid) {
                range.push_back({left, right});
            }
        }

        sort(range.begin(), range.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        vector<string> ans;
        int last_end = -1;
        
        for(int i = 0; i < range.size(); i++) {
            if (range[i][0] > last_end) {
                ans.push_back(s.substr(range[i][0], range[i][1] - range[i][0] + 1));
                last_end = range[i][1];
            }
        }

        return ans;
    }
};