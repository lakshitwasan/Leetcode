#include<bits/stdc++.h>
using namespace std;


vector<int> BFS(int V, vector<int> adj[])
{

    // Time complexity: 0(N) + O(2E) & Space Complexity: 0(N)

    int vis[V] = {0};
    vis[0] =1;
    queue<int> q;
    q.push(0);
    vector<int>bfs;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it: adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;
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

    vector<int> bfs = BFS(V, adj);

    cout << "BFS Traversal: ";
    for (int node : bfs)
        cout << node << " ";

    return 0;
}
