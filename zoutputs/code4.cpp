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

int modpow(int a, int e) {
    int r = 1 % MOD;
    a %= MOD;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int modinv(int x) { return modpow(x, MOD - 2); }

int smallComb(unsigned int N, int e) {
    if (e == 0) return 1;
    int num = 1;
    for (int i = 1; i <= e; i++) {
        int term = ((N - 1) % MOD + i) % MOD;
        num = (num * term) % MOD;
    }
    int denom = 1;
    for (int i = 1; i <= e; i++) denom = (denom * i) % MOD;
    return (num * modinv(denom)) % MOD;
}

vector<pair<int,int>> factorize(int b) {
    vector<pair<int,int>> f;
    for (int i = 2; i * i <= b; i++) {
        if (b % i == 0) {
            int cnt = 0;
            while (b % i == 0) { b /= i; cnt++; }
            f.push_back({i, cnt});
        }
    }
    if (b > 1) f.push_back({b, 1});
    return f;
}

// Generate all divisors
void genDivisors(int idx, int val, const vector<pair<int,int>>& f,
                 vector<int>& exps, vector<pair<int, vector<int>>>& out) {
    if (idx == (int)f.size()) {
        out.push_back({val, exps});
        return;
    }
    int p = f[idx].first;
    for (int e = 0; e <= f[idx].second; e++) {
        exps[idx] = e;
        genDivisors(idx + 1, val, f, exps, out);
        if (val > LLONG_MAX / p) break;
        val *= p;
    }
}

signed solve(int test)
{
    int N;
    int A, B;
    cin >> N >> A >> B;

    auto fac = factorize(B);
    vector<int> exps(fac.size(), 0);
    vector<pair<int, vector<int>>> divs;
    genDivisors(0, 1, fac, exps, divs);

    int ans = 0;
    for (auto &pr : divs) {
        int d = pr.first;
        if (d > A) continue;
        auto e_d = pr.second;

        int ways1 = 1, ways2 = 1;
        for (size_t i = 0; i < fac.size(); i++) {
            int E = fac[i].second;
            int e = e_d[i];
            ways1 = (ways1 * smallComb(N, e)) % MOD;
            ways2 = (ways2 * smallComb(N, E - e)) % MOD;
        }

        int add = (ways1 * ways2) % MOD;
        ans = (ans + add) % MOD;
    }
    cout << "Case #" << test << ": " << ans << "\n";
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin);
        freopen("final_product_chapter_2_input.txt", "r", stdin);
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