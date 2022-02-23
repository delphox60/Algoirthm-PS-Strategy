#include <iostream>

using namespace std;

string ip;
int fail[1000000];

void set_fail()
{
    int n = ip.size();
    for (int i = 0; i < n; i++)
        fail[i] = 0;

    for (int i = 0, j = 1; j < n; j++)
    {
        while (i > 0 && ip[i] != ip[j])
            i = fail[i - 1];
        if (ip[i] == ip[j])
            fail[j] = ++i;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        cin >> ip;
        if (ip == ".")
            break;
        set_fail();
        if (ip.size() % (ip.size() - fail[ip.size() - 1]))
        {
            cout << 1 << '\n';
            continue;
        }
        cout << ip.size() / (ip.size() - fail[ip.size() - 1]) << '\n';
    }
}
