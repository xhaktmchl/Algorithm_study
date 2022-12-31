#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring> // memset

using namespace std;
/*
[백준 3085 1260 c++ VOOOVOO] DFS와 BFS
문제:
접근: 1차원 그래프-> 기본 인접리스트로 구현 , 인접 행렬은 시간복잡도(n*n) 이라 느려서 인접 그래프로 푸는것을 추천시간복잡도: O(n*n*(n*n)), n=50
시간복잡도: O(nlogm)=
풀이: 
    //1.입력
    //인접 리스트 간선: 양방향
    //노드 작은 것부터 정렬
    //2.dfs: v부터 시작(현재 노드)
    //1)방문처리, 
    //2)인접 노드 탐색
    //다음 노드
    //방문 안했으면 
    //방문처리, 
    //dfs재귀
    //3.초기화: 방문배열, 
    //4.bfs
    //1) 큐 생성, 푸쉬 및 방문처리
    //2) 큐 빌 때까지 계속 반복
    //큐 프론트
    // 큐 팝
    //현재 노드의 인접 리스트 탐색
    //방문 안했으면 
    //큐 푸쉬, 방문처리
*/
int n, m, v;
vector<int> graph[1010];
bool visit[1010];
int nn;

void dfs(int node) {
    visit[node] = 1; cout << node << " ";

    int size = graph[node].size();
    for (int i = 0; i < size; i++) {
        nn = graph[node][i];
        if (!visit[nn]) {
            visit[nn] = 1;
            dfs(nn);
        }
    }
}


void bfs(int node) {
    queue<int> q;
    q.push(node); visit[node] = 1; 
    cout << node << " ";

    while (!q.empty()) {
        node = q.front();
        q.pop();

        int size = graph[node].size();
        for (int i = 0; i < size; i++) {
            nn = graph[node][i];
            if (!visit[nn]) {
                q.push(nn); visit[nn] = 1; 
                cout << nn << " ";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    //1.입력
    //인접 리스트 간선: 양방향
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    //노드 작은 것부터 정렬
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    //2.dfs: v부터 시작(현재 노드)
    //1)방문처리, 
    //2)인접 노드 탐색
    //다음 노드
    //방문 안했으면 
    //방문처리, 
    //dfs재귀
    dfs(v);
    cout << '\n';
    //3.초기화: 방문배열, 
    memset(visit, 0, sizeof(visit));
    //4.bfs
    //1) 큐 생성, 푸쉬 및 방문처리
    //2) 큐 빌 때까지 계속 반복
    //큐 프론트
    // 큐 팝
    //현재 노드의 인접 리스트 탐색
    //방문 안했으면 
    //큐 푸쉬, 방문처리
    bfs(v);
}
