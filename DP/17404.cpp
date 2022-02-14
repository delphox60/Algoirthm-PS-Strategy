#include <iostream>

using namespace std;

const int R = 0;
const int G = 1;
const int B = 2;
int table[3][1002];
int cost[3][1002];
int minval = 1000000;
int n;

int get_min_cost(int c1)
{
    int c2 = (c1 + 1) % 3;
    int c3 = (c1 + 2) % 3;

    cost[c1][0] = table[c1][0];

    cost[c2][1] = cost[c1][0] + table[c2][1];
    cost[c3][1] = cost[c1][0] + table[c3][1];

    cost[c1][2] = min(cost[c2][1], cost[c3][1]) + table[c1][2];
    cost[c2][2] = cost[c3][1] + table[c2][2];
    cost[c3][2] = cost[c2][1] + table[c3][2];

    for (int i = 3; i < n; i++)
    {
        cost[c1][i] = min(cost[c2][i - 1], cost[c3][i - 1]) + table[c1][i];
        cost[c2][i] = min(cost[c1][i - 1], cost[c3][i - 1]) + table[c2][i];
        cost[c3][i] = min(cost[c2][i - 1], cost[c1][i - 1]) + table[c3][i];
    }

    return min(cost[c2][n - 1], cost[c3][n - 1]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> table[R][i];
        cin >> table[G][i];
        cin >> table[B][i];
    }
    for (int i = 0; i <= 2; i++)
        minval = min(get_min_cost(i), minval);

    cout << minval << '\n';
}