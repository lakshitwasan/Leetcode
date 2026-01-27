#include<bits/stdc++.h>
using namespace std;

void dfs_helper(int node, vector<int> adj[], vector<int> &ls, int vis[])
{
    vis[node] =1;
    ls.push_back(node);

    for(auto it: adj[node])
    {
        if (!vis[it])
        {
            dfs_helper(it, adj, ls, vis);
        }
    }
}

vector<int> dfs(int V, vector<int> adj[])
{

    // Time complexity: O(N) + O(2E) & Space Complexity: O(N)

    int vis[V] = {0};
    vector<int> ls;
    int start = 0;
    dfs_helper(start, adj, ls, vis);
    return ls;
}

int main()
{
    int V = 7;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[1].push_back(4);
    adj[4].push_back(1);

    adj[2].push_back(5);
    adj[5].push_back(2);

    adj[4].push_back(6);
    adj[6].push_back(4);

    vector<int> result = dfs(V, adj);

    cout << "DFS Traversal: ";
    for (int node : result)
        cout << node << " ";

    return 0;
}
