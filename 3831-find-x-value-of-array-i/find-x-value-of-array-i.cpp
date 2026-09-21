class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector <vector<long long >> dp (k,vector <long long > (n+1,0));
        if(k==1)return {1ll*n*(n+1)/2};
        if(k>1)
        for(int i=0;i<n;i++)
        dp[1][i]=1;
        for(int j=0;j<n;j++)
        {
            
            //for(int i=0;i<k;i++)
              //  dp[i][j+1]=dp[i][j];
                for(int i=0;i<k;i++)
            dp[((i%k)*(nums[j]%k))%k][j+1]+=dp[i][j];
            
        }
        // for(int i=0;i<k;i++)
        // {
        //     for(int j=0;j<=n;j++)
        //     cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        vector <long long > ans(k,0);
        for(int i=0;i<k;i++)
        {
            for(int j=1;j<=n;j++)
            ans[i]+=dp[i][j];
        }
        if(k>1)
        ans[1]-=n-1;
        return ans;
    }
};