#include <iostream>
#include <vector>

using namespace std;

vector<int> uf(1000005, -1);

int n, m;

int find(int nu)
{
    if (uf[nu] < 0)
        return nu;
    return uf[nu] = find(uf[nu]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    uf[a] = b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int cmd, a, b;
        cin >> cmd >> a >> b;

        if (cmd == 0)
            merge(a, b);

        else
        {
            if (find(a) == find(b))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
}