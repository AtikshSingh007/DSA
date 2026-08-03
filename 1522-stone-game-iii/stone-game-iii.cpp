class Solution {
    vector <long long> memo;
    vector <int> a;
    int n;

    long long score(int i)
    {
        if(i==(n))return 0;
        long long mx=-1e18,sumj=0;
        for(int j=i;j<(i+3) && j<n;j++)
        {
            sumj+=a[j]; 
            long long mn=1e18,sumk=0;
            for(int k=j+1;k<n && k<j+4;k++)
            {
            sumk+=a[k];
            long long temp=(memo[k+1]!=-1e18)?memo[k+1]:score(k+1);
         //  long long temp=score(k+1);
            mn=min(temp,mn);
            }
            if(mn==1e18)mn=0; 
            mx=max(sumj+mn,mx);
        }
        return memo[i]=mx;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        a=stoneValue;n=stoneValue.size();
        memo.assign(n+1,-1e18);
        memo[n]=0;
        long long sum=accumulate(stoneValue.begin(),stoneValue.end(),0ll);
        long long scr=score(0);
        cout<<scr<<endl;
        if(scr*2==sum)return "Tie";
        else if(scr*2<sum)return "Bob";
        else return "Alice";
    }
};