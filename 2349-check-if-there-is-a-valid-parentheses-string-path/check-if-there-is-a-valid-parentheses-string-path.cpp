class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector < vector <vector<int>> > dp(n,vector<vector<int>>(m,vector<int>(max(n,m)+1,0)));
        if(grid[0][0]=='(')dp[0][0][1]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<=max(m,n);k++)
                {
                    if(grid[i][j]=='(')
                    {
                        if(k==0)continue;
                         if(i>0 )
                            dp[i][j][k]=dp[i][j][k]||dp[i-1][j][k-1];
                        if(j>0)
                            dp[i][j][k]=dp[i][j][k]||dp[i][j-1][k-1];
                    }
                    else
                    {
                        if(k==(max(n,m)))continue ;
                        if(i>0)
                        dp[i][j][k]=dp[i][j][k]||dp[i-1][j][k+1];
                        if(j>0)
                        dp[i][j][k]=dp[i][j][k]||dp[i][j-1][k+1];
                    }

                }

            }
        }
        return dp[n-1][m-1][0];
    }
};