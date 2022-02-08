#include <iostream>
#include <vector>

using namespace std;

int n, m, k;

vector<int> p(10005, -1);
vector<int> cost(10005, -1);
vector<bool> used(10005, false);

int find(int n)
{
    if (p[n] < 0)
        return n;
    return p[n] = find(p[n]);
}

void merge(int a, int b)
{
    int min_cost = min(cost[a], cost[b]);
    a = find(a);
    b = find(b);
    min_cost = min(min_cost, min(cost[a], cost[b]));
    if (a == b)
        return;
    p[a] = b;
    p[b] = min_cost * (-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long m2p = 0;

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int s, e;
        cin >> s >> e;
        merge(s, e);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[find(i)])
        {
            m2p -= p[find(i)];
            used[find(i)] = true;
        }
    }
    if (m2p > k)
    {
        cout << m2p << '\n';
        cout << "Oh no" << '\n';
    }
    else
        cout << m2p << '\n';
}