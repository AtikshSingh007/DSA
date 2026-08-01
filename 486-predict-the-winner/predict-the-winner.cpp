class Solution {
vector <int> a;
int mxscore(int l,int r )
    {
        if(r<l)return 0;
        int left=a[l]+min(mxscore(l+2,r),mxscore(l+1,r-1));
        int right=a[r]+min( mxscore(l,r-2), mxscore(l+1,r-1) );
        return max(left,right);

    }

public:
    bool predictTheWinner(vector<int>& nums) {
        a=nums;
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0ll);
        int mx=mxscore(0,n-1);
    return (2*mx>=sum);
    }
};