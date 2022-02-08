#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int r, c;
int x1, x2, y1, y2;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<pair<int, int>>> p(1505, vector<pair<int, int>>(1505, {-1, -1}));
vector<vector<bool>> tmp(1505, vector<bool>(1505, false));

bool isBoundary(int x, int y)
{
    if (!tmp[x][y])
        return false;
    for (int d = 0; d < 4; d++)
    {
        if (!(x + dx[d] > 0 && x + dx[d] <= r && y + dy[d] > 0 && y + dy[d] <= c))
            continue;
        if (!tmp[x + dx[d]][y + dy[d]])
            return true;
    }
    return false;
}

pair<int, int> find(int x, int y)
{
    pair<int, int> parent = p[x][y];
    if (parent.first < 0)
        return {x, y};
    return p[x][y] = find(parent.first, parent.second);
}

void merge(int x, int y, int a, int b)
{
    pair<int, int> p1 = find(x, y);
    pair<int, int> p2 = find(a, b);
    if (p1 == p2)
        return;

    p[p1.first][p1.second] = p2;
}

void link(int i, int j)
{
    for (int d = 0; d < 4; d++)
    {
        if (!(i + dx[d] > 0 && i + dx[d] <= r && j + dy[d] > 0 && j + dy[d] <= c))
            continue;
        if (tmp[i][j] && tmp[i + dx[d]][j + dy[d]])
            merge(i, j, i + dx[d], j + dy[d]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;

    x1 = -1;
    y1 = -1;

    queue<pair<int, int>> q;

    for (int i = 1; i <= r; i++)
    {
        string row;
        cin >> row;
        for (int j = 1; j <= c; j++)
        {
            char cmd = row[j - 1];
            if (cmd == 'L')
            {
                if (x1 < 0)
                {
                    x1 = i;
                    y1 = j;
                }
                else
                {
                    x2 = i;
                    y2 = j;
                }
            }
            if (cmd != 'X')
            {
                tmp[i][j] = true;
                link(i, j);
            }
        }
    }

    int cnt = 0;

    while (true)
    {
        if (find(x1, y1) == find(x2, y2))
            break;

        cnt++;

        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
            {
                if (isBoundary(i, j))
                    q.push({i, j});
            }

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            int cx = cur.first;
            int cy = cur.second;

            for (int d = 0; d < 4; d++)
            {
                if (!(cx + dx[d] > 0 && cy + dy[d] > 0 && cx + dx[d] <= r && cy + dy[d] <= c))
                    continue;
                if (!tmp[cx + dx[d]][cy + dy[d]])
                {
                    tmp[cx + dx[d]][cy + dy[d]] = true;
                    link(cx + dx[d], cy + dy[d]);
                }
            }
        }
        cout << cnt << '\n';
    }
}