#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

#define ll long long
#define ld long double
#define point pair<ll, ll>
#define pdd pair<ld, ld>
#define line pair<point, point>
#define X first
#define Y second

ll ccw(point a, point b, point c)
{
    if ((b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X) == 0)
        return 0;
    return (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X) < 0 ? -1 : 1;
}
ll ccw_double(pdd a, pdd b, pdd c)
{
    if ((b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X) == 0)
        return 0;
    return (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X) < 0 ? -1 : 1;
}

bool p_in_line(point p, line l)
{
    ll x1, x2, y1, y2;
    x1 = min(l.X.X, l.Y.X);
    x2 = max(l.X.X, l.Y.X);
    y1 = min(l.X.Y, l.Y.Y);
    y2 = max(l.X.Y, l.Y.Y);

    return (p.X >= x1 && p.X <= x2 && p.Y >= y1 && p.Y <= y2) && ccw(l.X, l.Y, p) == 0;
}

bool judge_crossment(line l1, line l2)
{
    if (ccw(l1.X, l1.Y, l2.X) == 0 || ccw(l2.X, l2.Y, l1.X) == 0 || ccw(l1.X, l1.Y, l2.Y) == 0 || ccw(l2.X, l2.Y, l1.Y) == 0)
    {
        return (p_in_line(l2.X, l1) || p_in_line(l2.Y, l1) || p_in_line(l1.X, l2) || p_in_line(l1.Y, l2));
    }

    return ccw(l1.X, l1.Y, l2.X) * ccw(l1.X, l1.Y, l2.Y) < 0 && ccw(l2.X, l2.Y, l1.X) * ccw(l2.X, l2.Y, l1.Y) < 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    line l1, l2;
    cin >> l1.X.X >> l1.X.Y;
    cin >> l1.Y.X >> l1.Y.Y;
    cin >> l2.X.X >> l2.X.Y;
    cin >> l2.Y.X >> l2.Y.Y;

    if (!judge_crossment(l1, l2))
    {
        cout << 0;
        return 0;
    }
    cout << 1 << '\n';

    if (ccw(l1.X, l1.Y, l2.X) == 0 && ccw(l1.X, l1.Y, l2.Y) == 0)
    {
        pdd arr[4] = {l1.X, l1.Y, l2.X, l2.Y};
        sort(arr, arr + 4);
        cout << (arr[1].X + arr[2].X) / 2 << ' ' << (arr[1].Y + arr[2].Y) / 2 << '\n';
        return 0;
    }
    if (p_in_line(l1.X, l2))
    {
        cout << l1.X.X << ' ' << l1.X.Y << '\n';
        return 0;
    }
    if (p_in_line(l1.Y, l2))
    {
        cout << l1.Y.X << ' ' << l1.Y.Y << '\n';
        return 0;
    }
    if (p_in_line(l2.X, l1))
    {
        cout << l2.X.X << ' ' << l2.X.Y << '\n';
        return 0;
    }
    if (p_in_line(l2.Y, l1))
    {
        cout << l2.Y.X << ' ' << l2.Y.Y << '\n';
        return 0;
    }

    pdd lp;
    pdd hp;
    pdd mp;

    if (ccw(l2.X, l2.Y, l1.X) <= 0)
    {
        lp = l1.X;
        hp = l1.Y;
    }
    else
    {
        lp = l1.Y;
        hp = l1.X;
    }
    for (int i = 0; i < 200; i++)
    {
        mp = {(lp.X + hp.X) / 2, (lp.Y + hp.Y) / 2};

        if (ccw_double(l2.X, l2.Y, mp) < (ld)0)
            lp = mp;
        else
            hp = mp;
    }
    cout << fixed;
    cout.precision(17);
    cout << mp.X << ' ' << mp.Y << '\n';
}