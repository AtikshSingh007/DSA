class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        vector<array<int, 4>> a;
        a.reserve(n);
        for (int i = 0; i < n; i++) {
            a.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        }
        
        sort(a.begin(), a.end(), [](const array<int, 4>& x, const array<int, 4>& y) {
            return x[1] < y[1];
        });
        
        using DPState = pair<long long, vector<int>>;
        vector<vector<DPState>> dp(n + 1, vector<DPState>(5, {0LL, {}}));
        
        for (int i = 1; i <= n; ++i) {
            int last_idx = 0;
            int left = 1, right = i - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (a[mid - 1][1] < a[i - 1][0]) {
                    last_idx = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            for (int j = 1; j <= 4; ++j) {
                DPState skip = dp[i - 1][j];
                
                DPState pick = dp[last_idx][j - 1];
                pick.first += a[i - 1][2];
                pick.second.push_back(a[i - 1][3]);
                
                sort(pick.second.begin(), pick.second.end()); 
                
                if (pick.first > skip.first || (pick.first == skip.first && pick.second < skip.second)) {
                    dp[i][j] = pick;
                } else {
                    dp[i][j] = skip;
                }
            }
        }
        
        return dp[n][4].second;
    }
};