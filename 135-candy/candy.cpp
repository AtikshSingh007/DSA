class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        auto a=ratings;
        vector <int> vec(n,1);
        for(int i=1;i<n;i++)
        if(a[i]>a[i-1])vec[i]=max(vec[i-1]+1,vec[i]);
        for(int i=n-2;i>=0;i--)
        if(a[i]>a[i+1])vec[i]=max(vec[i+1]+1,vec[i]);

        int sum=accumulate(vec.begin(),vec.end(),0);
        return sum;

    }
};