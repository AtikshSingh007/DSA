class Solution {
    bool valid(int x,int y,int n,int m)
    {
        return (x>=0 && y>=0 && x<n && y<m);
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
              int n=grid.size(),m=grid[0].size();
long long ans=0;
vector<vector<int>> vis(n,vector<int> (m,0));
              for(int i=0;i<n;i++)
              {
                for(int j=0;j<m;j++)
               {
                long long sum=0;
                if(vis[i][j] || grid[i][j]==0)continue;
                
                vector<pair<int,int>> vec;
                vec.push_back(make_pair(i,j));
                while(vec.size())
                {
                    auto [x,y]=vec.back();
                    vec.pop_back();
                    if(vis[x][y])continue;  
                    vis[x][y]=1;
                    if(grid[x][y]==0)
                    continue;

                    sum=(sum+grid[x][y])%k;
                    
                    vector<int> xdir={1,0,-1,0}, ydir={0,-1, 0,1};
                    for(int d=0;d<4;d++)
                    {
                        int newx=x+xdir[d],newy=y+ydir[d];
                        if(valid(newx,newy,n,m) && !vis[newx][newy])
                        vec.push_back(make_pair(newx,newy));
                    }
                }
                if(sum==0)
                    ans++;

               }
              }
              return ans;
    }
};