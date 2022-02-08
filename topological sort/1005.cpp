#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k, w;
    cin >> t;
    while (t--)
    {
        int cost[1001];
        queue<int> q;
        vector<int> acc_cost(1001, 0);
        vector<int> indegree(1001, 0);
        vector<vector<int>> adj(1001);

        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> cost[i];

        while (k--)
        {
            int x, y;
            cin >> x >> y;

            adj[x].push_back(y);
            indegree[y]++;
        }

        cin >> w;

        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (true)
        {
            int cur = q.front();
            q.pop();

            acc_cost[cur] += cost[cur];

            if (cur == w)
                break;

            for (auto it = adj[cur].begin(); it != adj[cur].end(); it++)
            {
                indegree[*it]--;
                if (indegree[*it] == 0)
                    q.push(*it);

                acc_cost[*it] = max(acc_cost[*it], acc_cost[cur]);
            }
        }

        cout << acc_cost[w] << '\n';
    }
}