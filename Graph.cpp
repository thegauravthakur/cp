/*
 * Created by Gaurav on 21/03/20
 */
#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

template<typename T>
class Graph {
    unordered_map<T, vector<T>> adj;

public:
    void addEdge(T u, T v, bool biDirectional = true) {
        adj[u].push_back(v);
        if (biDirectional)
            adj[v].push_back(u);
    }

    void displayAll() {
        for (auto &i : adj) {
            cout << i.first << " : ";
            for (auto &j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    void ssspFrom(T start) {
        unordered_map<T, bool> visited;
        unordered_map<T, int> distance;
        queue<T> q;
        q.push(start);
        cout << start << " -> " << distance[start] << endl;
        visited[start] = true;
        while (not q.empty()) {
            T top = q.front();
            q.pop();
            for (auto &i : adj[top]) {
                if (not visited[i]) {
                    visited[i] = true;
                    distance[i] = distance[top] + 1;
                    cout << i << " -> " << distance[i] << endl;
                    q.push(i);
                }
            }
        }

    }

    void bfs(T start) {
        unordered_map<T, bool> visited;
        queue<T> q;
        q.push(start);
        visited[start] = true;
        cout << start << ' ';
        while (not q.empty()) {
            auto front = q.front();
            q.pop();
            for (auto &i : adj[front]) {
                if (not visited[i]) {
                    cout << i << ' ';
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    void dfsIterative(T start) {
        unordered_map<T, bool> visited;
        stack<T> q;
        q.push(start);
        visited[start] = true;
        cout << start << ' ';
        while (not q.empty()) {
            auto top = q.top();
            q.pop();
            for (auto &i : adj[top]) {
                if (not visited[i]) {
                    cout << i << ' ';
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }


    void dfs(T start) {
        unordered_map<T, bool> visited;
        dfsRec(start, visited);
    }

    int connectedComponent() {
        unordered_map<T, bool> visited;
        int ans{0};
        for (auto &i : adj) {
            if (not checkAllVisited(visited)) ans++;
            dfsCon(i.first, visited);
        }
        return ans;
    }

    void topological(T node) {
        unordered_map<T, bool> visited;
        list<T> ordering;
        topologicalDfs(node, visited, ordering);
        cout << "ordering: ";
        for (auto &i : ordering) {
            cout << i << " -> ";
        }
        cout << endl;
    }

private:
    void topologicalDfs(T node, unordered_map<T, bool> &visited, list<T> &ordering) {
        visited[node] = true;
        for (auto &i : adj[node]) {
            if (not visited[i]) topologicalDfs(i, visited, ordering);
        }
        ordering.push_front(node);
    }

    void dfsRec(T start, unordered_map<T, bool> &visited) {
        cout << start << ' ';
        visited[start] = true;
        for (auto &i : adj[start]) {
            if (not visited[i])
                dfsRec(i, visited);
        }
    }

    void dfsCon(T start, unordered_map<T, bool> &visited) {
        visited[start] = true;
        for (auto &i : adj[start]) {
            if (not visited[i])
                dfsCon(i, visited);
        }
    }

    bool checkAllVisited(unordered_map<T, bool> &visited) {
        for (auto &i : adj) {
            if (not visited[i.first]) return false;

        }
        return true;
    }

};

int32_t main() {
    IOS
    Graph<string> graph;
    graph.addEdge("kamand", "telang", false);
    graph.addEdge("telang", "mandi", false);
    graph.addEdge("kamand", "bhutti", false);
    graph.addEdge("kamand", "bhalyani", false);
    graph.addEdge("bhalyani", "bhutti", false);
    graph.addEdge("bhutti", "kullu", false);
    graph.addEdge("kullu", "mandi", false);
    graph.addEdge("kullu", "manali", false);
    vector<int> a;
    graph.displayAll();
    graph.bfs("bhutti");
    graph.dfsIterative("bhutti");
    graph.dfs("bhutti");
    graph.ssspFrom("manali");
    cout << "total connected componenets ->" << graph.connectedComponent() << endl;
    graph.topological("kamand");
    return 0;
}
