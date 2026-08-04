class Solution {
    vector <vector <int> > memo;
    vector <int> a;
    int n;

    long long mxcoins(int i,int j ,int l ,int r)
    {
        if(i>j)return 0;

        if(memo[i][j]!=-1)return memo[i][j];

        long long ans=0;
        for(int k=i;k<=j;k++)
        {
            long long calc=mxcoins(i,k-1,l,a[k]) +l*a[k]*r +  mxcoins(k+1,j,a[k],r);
            ans=max(calc,ans);
        }
        return memo[i][j]=ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        n=nums.size();
        memo.assign(n+1,vector <int> (n+1,-1));

         a=nums;
        int ans=(int)mxcoins(0,n-1,1,1);
            return ans;
    }
};