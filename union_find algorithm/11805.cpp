#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

vector<int> p(1004, -1);

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

    int p, w, S, E;
    cin >> p >> w >> S >> E;

    priority_queue<pair<int, pair<int, int>>> q;

    for (int i = 0; i < w; i++)
    {
        int ss, ee, ww;
        cin >> ss >> ee >> ww;
        q.push({ww, {ss, ee}});
    }

    int min_width;

    while (find(S) != find(E) && !q.empty())
    {
        pair<int, pair<int, int>> cur = q.top();
        q.pop();
        min_width = cur.first;
        merge(cur.second.first, cur.second.second);
    }
    cout << min_width << '\n';
}