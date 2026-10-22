class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int inc=0,dec=0;
        if(n==1)return 0;
        if(n==2)
        {
            if(nums[0]<nums[1])
            return 0;
            else 
            return 1;
        }
        for(int i=0;i<n;i++)
        {
            if( (nums[(i+1)%n]-nums[i])==1 )inc++;
            if( (-nums[(i+1)%n]+nums[i])==1 )dec++;
        }

        if(inc!=(n-1)&& dec!=(n-1))return -1;
        int j=-1;
        for(int i=0;i<n;i++)
        {
            if(abs(nums[(i+1)%n]-nums[i])>1)j=i;
        }int rev=0;
        
        if(dec==(n-1))rev=1;
       // cout<<j<<endl;
        int ans=(rev)?min(n-1-j,(j+1)%n ):(min(n-j+1,(j+1)%n)) ;
        return ans+rev;

    }
};