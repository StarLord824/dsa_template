// #include<iostream>
#include<bits/stdc++.h>

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

inline int power(int x, int y){
    int res = 1;
    while(y){
        if(y & 1) res *= x;
        y >>= 1;
        x *= x;
    }
    return res;
}

inline int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

inline int lcm(int a, int b){
    return a*b/gcd(a, b);
}

inline int32_t printArray(int arr[], int n){
    for(int i=0; i<n; i++ ) 
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

inline int32_t printVector(vector<int> &v){
    for(auto &x : v) 
        cout << x << " ";
    cout << endl;
    return 0;
}

signed solve(){
    int n, m;
    cin >> n >> m;
    cout << "a: " << n << ", b: " << m << endl;
    return 0;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    clock_t start = clock();

    int t=1; // Number of test cases
    cin >> t;
    while(t--) {
        solve();
    }

    cerr << "Time taken: " << (double)(clock()-start)/CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}