#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
 
using namespace std;
#define ll long long 
#define ld long double 
#define ui unsigned int 
#define ull unsigned ll
int INF = 1e9 + 7;
vector<int> dp(100005, INF);
vector<int> val[100005];
 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    int t, f;
    for (int i = 0; i < n; i++){
        cin >> t >> f;
        val[t].push_back(f);
    }
    dp[0] = 0;
    for (int i = 0; i < m; i++){
        for (auto a : val[i]){
            if (i + a <= m) dp[i + a] = min(dp[i + a], dp[i]); 
        }
        dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
    }
    // for (int i = 0; i <= m; i++){
    //     cout << dp[i] << endl;
    // }
    cout << dp[m];
 
}

