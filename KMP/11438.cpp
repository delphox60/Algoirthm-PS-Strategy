#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

vector<vector<long long>> p(20, vector<long long>(100001, -1));
vector<vector<long long>> adj(100001);
vector<long long> depth(100001);
vector<bool> used(100001, false);

long long n, m;

long long get_p(long long n, long long dgr)
{
    for (long long i = 19; i >= 0; i--)
    {
        if (dgr >= (1 << i))
        {
            dgr -= (1 << i);
            n = p[i][n];
            if (n < 0)
                return 1;
        }
    }
    return n;
}

long long get_lca(long long a, long long b)
{
    long long ld = min(depth[a], depth[b]);
    a = get_p(a, depth[a] - ld);
    b = get_p(b, depth[b] - ld);

    if (a == b)
        return a;

    for (long long i = 19; i >= 0; i--)
    {
        if (get_p(a, i) == get_p(b, i))
            continue;
        a = get_p(a, i);
        b = get_p(b, i);
    }

    return get_p(a, 1);
}

void set_p(long long n, long long d)
{
    used[n] = true;
    depth[n] = d;
    for (auto it = adj[n].begin(); it != adj[n].end(); it++)
    {
        if (used[*it])
            continue;
        p[0][*it] = n;
        set_p(*it, d + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    long long t = n - 1;

    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    set_p(1, 0);

    for (long long i = 1; i < 20; i++)
        for (long long j = 1; j <= n; j++)
        {
            p[i][j] = p[i - 1][p[i - 1][j]];
        }

    cin >> m;

    while (m--)
    {
        long long a, b;
        cin >> a >> b;
        cout << get_lca(a, b) << '\n';
    }
}
