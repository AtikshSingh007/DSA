class Solution {
    bool valid(int x,int y, int n,int m)
    {
        return (x<n && y<m  && x>=0 && y>=0);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int >> vis(n,vector<int> (m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j])continue;
                vector <pair<int,int> > vec;
                if(grid[i][j]==0)
                vec.push_back(make_pair(i,j));
                int f=1,f2=0;
                while(vec.size())
                {
                    f2=1;
                    auto [x,y]=vec.back();
                    vec.pop_back();
                    if(vis[x][y])continue;
                    vis[x][y]=1;
                    if(x==0 || x==(n-1) || y==0 || y==(m-1) )f=0;


                    vector<int> xdir={-1,0,1,0},ydir={0,-1,0,1};
                    for(int k=0;k<4;k++)
                    {
                            int newx=x+xdir[k],newy=y+ydir[k];
                            if(valid(newx,newy,n,m) && !vis[newx][newy] && grid[newx][newy]==0)
                            vec.push_back(make_pair(newx,newy)); 
                    }
                }
                if(f&f2)ans++;


            }
        }
        return ans;
    }
};