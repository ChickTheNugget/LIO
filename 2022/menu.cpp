#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define INF 1e9
#define MOD 1e9 + 7
#define MAXN 505
int n, m;


void solve()
{
    int n, price, a;
    char b; 
    bool flag = false;
    string s;
    cin >> n >> price >> s;
    vector<int> food;
    vector<int> drink;
    vector<bool> dp(price + 1, 0);
    vector<bool> dp1(price + 1, 0);
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        if (b == 'f'){
            food.push_back(a);
        }
        else{
            drink.push_back(a);
        }
    }
    sort(food.begin(), food.end());
    dp[0] = 1;
    for (auto e : food){
        for (int i = price; i >= 0; i--){
            if (i - e >= 0){
                if (dp[i - e]) dp[i] = true;
            }
        }
    }
    // for (int i = 0; i <= price; i++){
    //     cout << dp[i] << " ";
    // } cout << endl;
    if (s == "nodrink"){
        if (dp[price]){
            flag = true;
        }
    }
    else{
        sort(drink.begin(), drink.end());
        dp1[price] = 1;
        for (auto e : drink){
            for (int i = 0; i < price; i++){
                if (i + e <= price){
                    if (dp1[i + e]) dp1[i] = true;
                }
            }
        }
        // for (int i = 0; i <= price; i++){
        //     cout << dp1[i] << " ";
        // } cout << endl;
        for (int i = 1; i < price; i++){
            if (dp[i] and dp1[i]){
                flag = true;
            }
        }
    }
    if (flag) cout << "possible";
    else cout << "impossible";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();    
}