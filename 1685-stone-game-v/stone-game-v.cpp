class Solution {
    vector <vector<long long >>memo;
    vector <int> a;

    long long calc(int l,int r){
       // cout<<a.size()<<endl;
        if( (r-l+1)<=1)return 0;

        long long sum=0,ans=0,
        
        tot=0;
        for(int i=l;i<=r;i++)tot+=a[i];

        for(int i=l;i<r;i++)
        {
            long long left=(memo[l][i]!=-1)?memo[l][i]:calc(l,i);
            long long right=(memo[i+1][r]!=-1)?memo[i+1][r]:calc(i+1,r);
            sum+=a[i];
            if(sum<(tot-sum))
            ans=max(sum+left,ans);
            else if(sum*2==tot)
            ans=max(ans,sum+max(left, right) );
            else
            ans=max(ans,tot-sum + right);
        }
        return memo[l][r]=ans;

    }


public:
    int stoneGameV(vector<int>& stoneValue) {
    a=stoneValue;
    int n=stoneValue.size();
    memo.assign(n,vector<long long > (n,-1));

    return calc(0,n-1);   
    }
};