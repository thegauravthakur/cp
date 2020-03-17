/*
 * Created by Gaurav on 16/03/20
 */
#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main() {
    IOS
    map<string, list<string>> graph;
    graph["gaurav"].push_back("saurav");
    graph["gaurav"].push_back("anku");
    graph["gaurav"].push_back("Avantika");
    graph["saurav"].push_back("anku");
    graph["anku"].push_back("kittu");
    graph["kittu"].push_back("gaurav");
    graph["Avantika"].push_back("kittu");
    graph["Avantika"].push_back("papa");
    graph["Avantika"].push_back("mummy");
    queue<string> q;
    map<string, pair<bool, int>> visited;
    int temp = 0;
    q.push("gaurav");
    visited["gaurav"].first = true;
    visited["gaurav"].second = temp;

    while (not q.empty()) {
        bool flag = false;
        auto top = q.front();
        for (auto &i : graph[top]) {
            if (not visited[i].first)flag = true, q.push(i), visited[i].first = true, visited[i].second = temp + 1;
        }

        cout << top << " distance ->" << visited[top].second << endl;
        q.pop();
        if (flag)temp++;
    }
    return 0;
}
