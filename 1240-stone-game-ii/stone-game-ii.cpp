class Solution {
    vector<int> a;
    vector<vector<long long>> memo;
    int n;
    long long calc(int i,int m)
    {
        if(i>=n)return 0;
        if(memo[i][m]!=-1) return memo[i][m];   // <-- use the memo

        long long ans=0,suma=0;
    
        for(int xa=i;xa<min(n,i+2*m);xa++)
        {
            suma+=a[xa];
            long long mn=1e18;
            int newm=max(m, xa-i+1);            // <-- off-by-one fix (+1)
            for(int xb=xa+1;xb<=min(n-1,xa+2*newm);xb++)
            {
                mn=min(calc(xb+1,max(newm,xb-xa)) , mn);
            }
            if(mn==1e18) mn=0;                  // <-- fix: no continuation left, opponent gets nothing
            ans=max(mn+suma,ans);
        }
        return memo[i][m]=ans;                  // <-- store in memo
    }

public:
    int stoneGameII(vector<int>& piles) {
        a=piles;
        n=a.size();
        memo.assign(n+1,vector<long long>(2*n+1,-1));
        return calc(0,1);
    }
};