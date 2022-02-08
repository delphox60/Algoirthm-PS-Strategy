#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> cost(501);
vector<int> pre_cost(501, 0);
vector<int> indegree(501, 0);
vector<vector<int>> adj(501);
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        while (true)
        {
            int cur;
            cin >> cur;
            if (cur < 0)
                break;
            indegree[i]++;
            adj[cur].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto it = adj[cur].begin(); it != adj[cur].end(); it++)
        {
            pre_cost[*it] = max(pre_cost[*it], pre_cost[cur] + cost[cur]);
            indegree[*it]--;
            if (indegree[*it] == 0)
                q.push(*it);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << pre_cost[i] + cost[i] << '\n';
    }
}