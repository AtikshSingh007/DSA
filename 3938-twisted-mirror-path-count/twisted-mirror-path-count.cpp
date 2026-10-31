class Solution {
    bool valid(int x,int y)
    {
        return (x>=0 && y>=0);
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));
        dp[0][0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)continue;
                
                int xt=i-1,yt=j,xl=i,yl=j-1;
                    int p1=0,p2=0;
                while(valid(xt,yt) && grid[xt][yt]==1)
                {
                    if(p1&1)xt--;
                    else yt--;
                    p1++;
                }
                while(valid(xl,yl) && grid[xl][yl]==1)
                {
                    if(p2&1)yl--;
                    else xl--;
                    p2++;
                }
int mod=(1e9+7);
                if(valid(xt,yt))dp[i][j]=(dp[i][j]+dp[xt][yt])%(mod);
                if(valid(xl,yl))dp[i][j]=(dp[i][j]+dp[xl][yl])%(mod);

            }
        }
        return dp.back().back();

    }
};