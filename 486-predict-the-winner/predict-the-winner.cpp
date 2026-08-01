class Solution {
vector <int> a;
vector <vector<int>> memo; 
int mxscore(int l,int r )
    {
        if(r<l)return 0;
        if(memo[l][r]!=-1)return memo[l][r];
        int left=a[l]+min(mxscore(l+2,r),mxscore(l+1,r-1));
        int right=a[r]+min( mxscore(l,r-2), mxscore(l+1,r-1) );
        return memo[l][r]=max(left,right);

    }

public:
    bool predictTheWinner(vector<int>& nums) {
        a=nums;
        memo.assign(21,vector <int> (21,-1));
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0ll);
        int mx=mxscore(0,n-1);
    return (2*mx>=sum);
    }
};