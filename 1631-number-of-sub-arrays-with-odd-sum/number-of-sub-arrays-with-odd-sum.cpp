class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1e9+7, n=arr.size(),even=1,odd=0,ans=0;
        for(int i=0;i<n;i++)
        {
            int sum=(sum+arr[i])%2;
            if(sum&1){
                ans=(ans+even)%mod;
                odd++;
            }
            else{
             ans=(ans+odd)%mod;
             even++;
            }

        }
        return ans;
        
    }
};