class Solution {
    vector <int> a;
    vector <vector <int> > memo;
    int score(int l,int r)
    {
        if(r<l)return 0;

        if(memo[l][r]!=-1)return memo[l][r];

        int lscore=a[l]+min(score(l+2,r),score(l+1,r-1)),
        rscore=a[r]+min(score(l,r-2) , score(l+1,r-1) );

        return memo[l][r]= max(lscore,rscore);
    }

public:
    bool stoneGame(vector<int>& piles) {
        a=piles;
        int n=piles.size();
        memo.assign(n+1,vector <int> (n+1,-1));

        int sc=score(0,n-1);
        int tot=accumulate(piles.begin(),piles.end(),0);
        return(2*sc>tot);
    }
};