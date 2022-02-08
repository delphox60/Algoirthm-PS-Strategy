#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> indegree(1002, 0);
int tmp[1002];
vector<vector<int>> adj(1002);
queue<int> result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m;

    while (m--)
    {
        cin >> k;
        for (int i = 1; i <= k; i++)
            cin >> tmp[i];
        for (int i = 1; i < k; i++)
        {
            adj[tmp[i]].push_back(tmp[i + 1]);
            indegree[tmp[i + 1]]++;
        }
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        result.push(cur);

        for (auto it = adj[cur].begin(); it != adj[cur].end(); it++)
        {
            indegree[*it]--;
            if (indegree[*it] == 0)
                q.push(*it);
        }
    }
    if (result.size() < n)
    {
        cout << 0 << '\n';
        return 0;
    }
    while (!result.empty())
    {
        cout << result.front() << '\n';
        result.pop();
    }
}
