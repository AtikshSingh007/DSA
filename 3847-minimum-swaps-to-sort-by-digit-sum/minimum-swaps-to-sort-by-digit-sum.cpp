class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> vec;
        for(int i=0;i<n;i++)
        {
            int copy=nums[i],digsum=0;
            while(copy>0)
            {
                digsum+=copy%10;
                copy/=10;
            }

            vector<int> temp={digsum,nums[i],i};
            vec.push_back(temp);
        }
        sort(vec.begin(),vec.end());
        vector<int> vis(n,0);
        int j=0,ans=0;
        for(int i=0;i<n;i++ )
        {
            if(vis[i])continue;
            j=i;int c=0;
            while(!vis[j])
            {
               // cout<<j<<endl;
                vis[j]=1;
                j=vec[j][2];
                c++;
            }
            ans+=c-1;
        }
        return ans;
    }
};