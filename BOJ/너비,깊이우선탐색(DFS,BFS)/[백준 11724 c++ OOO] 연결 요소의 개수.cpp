#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[백준 11724 c++ OOO] 연결 요소의 개수
문제:
접근1: 1차원 그래프-> dfs-> 기본 인접리스트로 구현 -> 모든 노드에 대해서 dfs탐색 시작(방문되지 않은 곳이 새로운 연결요소)
시간 복잡도: O(n+간선의 갯수) : 모든 노드 방문n, 모든 간선 방문 m
풀이: 
    //1.입력
    //2.완탐: 각 노드에서 dfs 시작
    //만약 노드를 방문하지 않았으면
    //연결 요소 카운트++
    //1)dfs
    //3.출력: 연결 요소 개수
*/
int n, m;
int n1, n2, cnt = 0;
vector<int> g[1010];
bool visit[1010];

void dfs(int node) {
    visit[node] = 1;

    int size = g[node].size();
    for (int i = 0; i < size; i++) {
        int nn = g[node][i];
        if (!visit[nn]) {
            visit[nn] = 1;
            dfs(nn);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    //1.입력
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> n1 >> n2;
        g[n1].push_back(n2);
        g[n2].push_back(n1);
    }
    //2.완탐: 각 노드에서 dfs 시작
    //만약 노드를 방문하지 않았으면
    //연결 요소 카운트++
    //1)dfs
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            cnt++;
            dfs(i);
        }
    }
    //3.출력: 연결 요소 개수
    cout << cnt << '\n';
}
