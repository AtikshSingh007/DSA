class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector <vector<vector<int>>> f(m,vector<vector<int> > (n,vector<int> (1024,0)));
        f[0][0][grid[0][0]]=1;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                    for(int k=0;k<1024;k++)
                    {
                        //if(i>0 && j>0)f[i][j][k];//|=f[i-1][j-1][k^grid[i][j]];
                         if(i>0)f[i][j][k]|=f[i-1][j][k^grid[i][j]];
                         if(j>0)f[i][j][k]|=f[i][j-1][k^grid[i][j]];
                    }
            }
        }
        for(int i=0;i<1024;i++)
        if(f.back().back()[i])return i;
        return -1;
    }
};