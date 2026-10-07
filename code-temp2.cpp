#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define endl '\n'

signed solve(int test)
{
    int n;
    if (!(cin >> n))
        return 0;

    vector<pair<int, int>> a(n);
    int max_x = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        max_x = max(max_x, a[i].first);
    }

    int M = n + 80;
    vector<int> freq(M + 1, 0);
    int sum_large = 0;

    for (int i = 0; i < n; i++)
    {
        int x = a[i].first;
        int y = a[i].second;
        if (x <= M)
        {
            freq[x] += y;
        }
        else
        {
            sum_large += y;
        }
    }

    vector<int> suff(M + 2, 0);
    suff[M] = freq[M] + sum_large;
    for (int i = M - 1; i >= 0; i--)
    {
        suff[i] = suff[i + 1] + freq[i];
    }

    const int INF_LIMIT = 2e15;

    auto can_create = [&](int V) -> bool
    {
        if (V == 0)
            return true;

        int S = 0;
        int surplus = 0;

        for (int k = V - 1; k >= 1; k--)
        {
            int needed = 1 + S;
            int avail = freq[k];
            if (avail >= needed)
            {
                surplus += (avail - needed);
            }
            else
            {
                int deficit = needed - avail;
                S += deficit;
                if (S > INF_LIMIT)
                    return false;
            }
        }

        int needed_0 = 1 + S;
        int total_zeros = freq[0] + surplus + suff[V];
        return total_zeros >= needed_0;
    };

    int low = 0, high = M;
    int best_V = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (can_create(mid))
        {
            best_V = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    int mexoramax = max(max_x, best_V);
    cout << mexoramax << endl;
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

    int t = 1;
    if (cin >> t)
    {
        for (int tc = 1; tc <= t; ++tc)
        {
            solve(tc);
        }
    }

    return 0;
}
1