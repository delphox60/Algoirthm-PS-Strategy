#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> p(205, -1);

int find(int a)
{
    if (p[a] < 0)
        return a;
    return p[a] = find(p[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    p[a] = b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            bool linked;
            cin >> linked;
            if (linked)
                merge(i, j);
        }

    int s;
    cin >> s;

    for (int i = 1; i < m; i++)
    {
        int d;
        cin >> d;
        if (find(s) != find(d))
        {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
}
