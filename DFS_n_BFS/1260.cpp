#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// dfs에 들어오면 '방문'한 것으로 판단
// 해당 위치에 check true 로 해준다.
void dfs(int start, vector<int> graph[], bool check[]){
    stack<int> s;
    s.push(start);
    check[start] = true;
    printf("%d ", start);

    while(!s.empty()){
        int current_node = s.top();

        s.pop();
        for(int i = 0; i < graph[current_node].size(); ++i){
            int next_node = graph[current_node][i];

            if(check[next_node] == false){
                printf("%d ", next_node);
                check[next_node] = true;

                s.push(current_node);
                s.push(next_node);
                break;
            }
        }
    }
}

void bfs(int start, vector<int> graph[], bool check[]){
    queue<int> q;

    q.push(start);
    check[start] = true;

    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        printf("%d ", tmp);
        for(int i = 0; i < graph[tmp].size(); ++i){
            // 방문하지 않았다면
            if(check[graph[tmp][i]] == false){
                // 큐에 넣어주고 방문했음을 표시
                q.push(graph[tmp][i]);
                check[graph[tmp][i]] = true;
            }
        }
    }
}

int main(){
    // n : node, m : edge, start : start node num
    int n, m, start;
    cin >> n >> m >> start;

    vector<int> graph[n + 1];

    bool check[n + 1];
    fill_n(check, n + 1, false);

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Sorting은 나중에 graph 노드에 접근했을 때 낮은 노드 번호 순서대로 접근해야하기 때문에 진행
    for(int i = 0; i < n + 1; ++i){
        sort(graph[i].begin(), graph[i].end());
    }

    // dfs
    dfs(start, graph, check);
    printf("\n");

    fill_n(check, n + 1, false);
    
    // bfs
    bfs(start, graph, check);

    return 0;
}
