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

private:
    void dfsRec(T start, unordered_map<T, bool> &visited) {
        cout << start << ' ';
        visited[start] = true;
        for (auto &i : adj[start]) {
            if (not visited[i])
                dfsRec(i, visited);
        }
    }

};
