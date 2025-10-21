// #include<iostream>
#include <bits/stdc++.h>

using namespace std;

// #define int ll;
#define ll long long
#define ull unsigned long long
#define int ll
#define uint unsigned long long
#define ld long double
#define MOD 1000000007
#define endl '\n'
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(), x.end()
#define inf 9223372036854775807
#define mod 1000000007
#define line cout << '\n';

typedef vector<int> vi;
// typedef long long ll;
// typedef unsigned long long ull;

inline int power(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res *= x;
        y >>= 1;
        x *= x;
    }
    return res;
}

inline int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

inline int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

inline int32_t printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

inline int32_t printVector(vector<int> &v)
{
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
    return 0;
}

signed solve(int test)
{
    // start coding here
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    clock_t start = clock();

    int t = 1; // Number of test cases
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        solve(tc);
    }

    cerr << "Time taken: " << (double)(clock() - start) / CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}