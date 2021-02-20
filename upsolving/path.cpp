//нужно найти кратчайший путь между двумя вершинами.
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> g[n + 1];
    //read graph
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            if(a == 1)
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int start, finish;
    cin >> start >> finish;

    //bfs
    queue<int> q;
    q.push (start);
    vector<bool> used (n + 1);
    vector<int> distance (n + 1);
    used[start] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (size_t i=1; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (!used[to]) {
                used[to] = true;
                q.push (to);
                distance[to] = distance[v] + 1;
            }
        }
    }
    cout << distance[finish];
}