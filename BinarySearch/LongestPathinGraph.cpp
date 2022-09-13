#include <bits/stdc++.h>

using namespace std;

int DFS(vector<vector<int>> &G, int s, vector<int> &dp)
{

    int n = G[s].size();

    if (n == 0)
        return dp[s] = 0;

    if (dp[s] != -1)
        return dp[s];

    int ans = 0;

    for (int i = 0; i < G[s].size(); i++)
    {
        ans = max(ans, 1 + DFS(G, G[s][i], dp));
    }
    return dp[s] = ans;
}

int solve(vector<vector<int>> &G)
{

    int n = G.size();

    vector<int> dp(n, -1);

    vector<int> IN(n,0);

    for(int i=0;i<n;i++)
    {
        for(auto v : G[i])
        {
            IN[v]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(IN[i]==0)
            ans = max(ans, DFS(G, i, dp));
    }

    return ans;
}