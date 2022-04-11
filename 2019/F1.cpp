#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
#define ll long long 
#define ld long double 
#define ui unsigned int 
#define ull unsigned ll
int INF = 1e9 + 7;

int peche(int n, int g, int p, int gd, int pd, int* poiss)
{
    //amount of fish, big nets, small nets
    int ans = 0;
    vector<pair<int, pair<int, int>>> dp(n + 1, {0, {0, 0}});
    for (int i = 1; i <= n; i++){
        //max of taking big net or small
        int mxbig = 0, mxsml = 0, mx = 0, chosen = 0;
        if (i >= gd){
            mx = 0;
            chosen = 0;
            mxbig = 0;
            for (int o = 1; o <= gd; o++){
                mxbig += poiss[i - o];
            }
            for (int j = 1; j <= i - gd; j++){
                if (dp[j].second.first + 1 <= g){
                    mx = max(mx, dp[j].first);
                    chosen = j;
                }
            }
            if (mxbig + mx > dp[i].first){
                dp[i].second.first = dp[chosen].second.first + 1;
            }
            dp[i].first = max(dp[i].first, mxbig + mx);
        
        }
        
        if (i >= pd){
            mx = 0;
            chosen = 0;
            mxsml = 0;
            for (int o = 1; o <= pd; o++){
                mxsml += poiss[i - o];
            }
            for (int j = 1; j <= i - pd; j++){
                if (dp[j].second.second + 1 <= p){
                    mx = max(mx, dp[j].first);
                    chosen = j;
                }
            }
            if (mxsml + mx > dp[i].first){
                dp[i].second.second = dp[chosen].second.second + 1;
            }
            dp[i].first = max(dp[i].first, mxsml + mx);
        }
        ans = max(dp[i].first, ans);
        // for (int i = 1; i <= n; i++){
        //     cout << dp[i].first << " " << dp[i].second.first << " " << dp[i].second.second << "\n";
        // }
        // cout << endl;

    }
    // for (int i = 1; i <= n; i++){
    //     cout << dp[i].first << " " << dp[i].second.first << " " << dp[i].second.second << "\n";
    // }
    cout << ans;
    return 0;
}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n = 10, g = 1, p = 2, gd = 3, pd = 2;
    //int poiss[10] = {2, 0, 5, 0, 1, 2, 3, 1, 0, 1};
    //int poiss[10] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    //int poiss[10] = {10, 0, 0, 0, 10, 0, 0, 0, 0, 10};
    int poiss[10] = {0, 0, 0, 43, 10, 0, 0, 43, 0, 10};
    peche(n, g, p, gd, pd, poiss);

}