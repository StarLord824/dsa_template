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

signed solve(int test){
    cout << "Case #" << test << ": ";
    
    int n, a, b;
    cin >> n >> a >> b;

    //find prime factors of b;
    // vector<int> factors;
    // factors.push_back(1);
    // for(int i=2; i<=b; i++){
    //     while(b%i==0){
    //         factors.push_back(i);
    //         b/=i;
    //     }
    // }
    // //sort factors in ascending order
    // sort(factors.begin(), factors.end());

    vector<int> res;
    for(int i=0; i<2*n-1; i++){
        res.pb(1);
    }
    res.pb(b);

    printVector(res);

    return 0;
    // cout << (res ? "YES" : "NO") << endl;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin);
        freopen("final_product_chapter_1_input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    clock_t start = clock();

    int t=1; // Number of test cases
    cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }

    cerr << "Time taken: " << (double)(clock()-start)/CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}