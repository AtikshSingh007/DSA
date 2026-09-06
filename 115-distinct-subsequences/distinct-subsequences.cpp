class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<unsigned long long>> dp(n,vector<unsigned long long> (m,0));

        if(s[0]==t[0])dp[0][0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i>0 )
                dp[i][j]= dp[i-1][j];
                
                if(i>0 && s[i]==t[j] )
                dp[i][j]+= (j>0) ? dp[i-1][j-1] : 1; 
            }
        }
        return dp.back().back();
    }
};