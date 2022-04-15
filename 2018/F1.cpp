#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[1000];
bool vis[1000];
stack<int> st;

void dfs(int node, int par)
{
    vis[node] = true;
    for (auto a : adj[node]){
        if (!vis[a] and a != par){
            dfs(a, par);
        }
    }
    st.push(node);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	set <char> characters;
	vector <string> a;
	vector <pair<char, char>> pairs;
	while (true) {
		string tmp;
		cin >> tmp;
		if (tmp == "#") break;
		a.push_back(tmp);
	}
    //set
	for (int i = 0; i < a.size(); ++i){
		for (char c : a[i]){
			characters.insert(c);
		}
	}
    //create map
    map <char, int> m;
	map <int, char> m2;
	int iter = 0;
	for (auto i : characters){
		m[i] = iter;
		m2[iter] = i;
		iter++;
	}
	// for (auto i : m) {
	// 	cout << i.first << " " << i.second << endl;
	// }
    // cout << endl;
    // for (auto i : m2) {
	// 	cout << i.first << " " << i.second << endl;
	// }
    // cout << endl;
    //create order by 2, and add to adj list
	for (int i = 0; i < a.size() - 1; ++i){
		int j = 0;
		while (a[i][j] == a[i+1][j] and j < a[i].size() and j < a[i+1].size() ){
			j++;
		}
		if (j < a[i].size() or j < a[i+1].size()){
			pairs.push_back(make_pair(a[i][j], a[i+1][j]));
			// cout << "made pair " << a[i][j] << " " << a[i+1][j] << endl;
            int ma = m.at(a[i][j]);
            int mb = m.at(a[i+1][j]);
            adj[ma].push_back(mb);
		}
	}
    //normal topological sort with dfs
    for (int i = 0; i < characters.size(); i++){
        if (!vis[i]){
            dfs(i, -1);
        }
    }
    while(!st.empty()){
        char s = m2.at(st.top());
        st.pop();
        cout << s;
    }
	return 0;
}
