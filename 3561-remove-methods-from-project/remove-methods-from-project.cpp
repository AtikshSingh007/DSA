class Solution {
    vector<vector<int>> adj;
    vector <int> suspicious; 
    void dfs(int x)
    {
            suspicious[x]=1;
            for(auto nbr:adj[x])
            if(!suspicious[nbr])dfs(nbr);
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        suspicious.assign(n,0);
        adj.assign(n,vector<int> ());
        for(auto i:invocations)
        {
            int u=i[0],v=i[1];
            adj[u].push_back(v);
        }
        dfs(k);
        int rem=1;
        for(int i=0;i<n;i++)
        {
            if(!suspicious[i])
            {
                for(auto j:adj[i])
                if(suspicious[j])
                rem=0;
            }
        }
        vector <int> ans;
        if(rem)
        {
            for(int i=0;i<n;i++)
            if(!suspicious[i])
            ans.push_back(i);
        }
        else
        {
            for(int i=0;i<n;i++)
            ans.push_back(i);
        }
        //for(auto i:suspicious)cout<<i<<" ";
        return ans;

        
    }
};