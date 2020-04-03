/*
 * Practice, practice, and practice
 */
#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main() {
    IOS
    int n, e;
    cin >> n >> e;
    int start{1};
    vector<pair<int, int>> g[n + 1];
    vector<int> distance(n + 1, INT_MAX);
    while (e--) {
        int u, v, d;
        cin >> u >> v >> d;
        g[u].emplace_back(v, d);
        g[v].emplace_back(u, d);
    }
    set<pair<int, int>> s;
    distance[start] = 0;
    s.insert({distance[start], start});
    while (not s.empty()) {
        auto smallest = *s.begin();
        s.erase(s.begin());
        for (auto i : g[smallest.second]) {
            int totalDistance = i.second + smallest.first;
            if (totalDistance < distance[i.first]) {
                distance[i.first] = totalDistance;
                auto f = s.find({distance[i.first], i.first});
                if (f != s.end()) s.erase(f);
                s.insert({distance[i.first], i.first});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << i << ' ' << distance[i] << endl;
    }

    return 0;
}

/*
 * 7
10
1 2 2
1 6 3
2 6 4
2 3 4
6 5 3
3 7 2
7 5 4
3 5 7
3 4 3
4 5 2
 */
