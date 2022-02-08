#include <iostream>
#include <utility>

using namespace std;

#define pii pair<long long, long long>
#define X first
#define Y second

long long ccw(pii a, pii b, pii c)
{
    return (b.X - a.X) * (c.Y - a.Y) - (c.X - a.X) * (b.Y - a.Y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pii a, b, c, d;
    cin >> a.X >> a.Y;
    cin >> b.X >> b.Y;
    cin >> c.X >> c.Y;
    cin >> d.X >> d.Y;
    if (ccw(a, b, c) * ccw(a, b, d) < 0 && ccw(c, d, a) * ccw(c, d, b) < 0)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}