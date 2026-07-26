class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a=-1e9,b=-1e9,c=-1e9,negb=1e9,negc=1e9;
        for(auto num:nums)
        {
            if(num>=c)
            {
                swap(a,b);
                swap(b,c);
                c=num;
            }
            else if(num>=b)
            {
                swap(b,a);
                b=num;
            }
            else if(num>=a)
            a=num;

            if(num<=negc)
            {
                swap(negb,negc);
                negc=num;
            }
            else if(num<=negb)
            negb=num;

        }
        cout<<negc<<" "<<negb<<endl;
        int ans=a*b*c;
        if(negb<0 && negc<0)
        ans=max(negb*negc*c,ans);
        return ans;

    }
};