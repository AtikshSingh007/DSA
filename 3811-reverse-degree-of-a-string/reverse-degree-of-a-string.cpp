class Solution {
public:
    int reverseDegree(string s) {
      int n=s.size();
      int ans=0,sum=0;
      for(int i=0;i<n;i++){
      ans+=(123-s[i])*(i+1);
      
      }
      return ans;  
    }
};