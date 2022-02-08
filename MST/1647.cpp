#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

struct rd
{
    long long s;
    long long e;
    long long cost;
    rd(long long s, long long e, long long c) : s(s), e(e), cost(c) {}
};

bool operator<(rd l, rd r)
{
    return l.cost > r.cost;
}

vector<long long> p(100005, -1);

long long find(long long idx)
{
    if (p[idx] < 0)
        return idx;
    return p[idx] = find(p[idx]);
}

void merge(long long a, long long b)
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

    long long n, m;
    cin >> n >> m;

    priority_queue<rd> q;

    for (long long i = 0; i < m; i++)
    {
        long long ss, ee, cc;
        cin >> ss >> ee >> cc;
        q.push(rd(ss, ee, cc));
    }

    long long total_cost = 0;

    for (long long i = 0; i < n - 2; i += 0)
    {
        rd cur = q.top();
        q.pop();

        if (find(cur.s) == find(cur.e))
            continue;

        total_cost += cur.cost;
        merge(cur.s, cur.e);
        i++;
    }

    cout << total_cost << '\n';
    return 0;
}