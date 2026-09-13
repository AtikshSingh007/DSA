class Solution {
    bool valid(int x,int y, int n)
    {
        return (x<n && y<n && x>=0 && y>=0);
    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
            int n=img2.size();
        int ans=0;
        for(int offx=-n+1; offx < n ; offx++)
        {
            for(int offy =-n+1   ;   offy <n;offy++)
            {
                int cnt=0;
                for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                {
                    //if(offx!=-1 || offy!=-1 )continue;

                
                    int x=i+offx,y=j+offy;
                    if( valid(x,y,n) && img1[x][y]==img2[i][j] && img2[i][j]==1)
                    {
                      //  cout<<i<<" "<<j<<endl;
                        cnt++;
                    }

                }

                ans=max(ans,cnt);

            }
        }
return ans;
    }
};