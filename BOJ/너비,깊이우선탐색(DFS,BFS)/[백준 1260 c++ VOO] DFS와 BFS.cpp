#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 1260 c++ VOO] DFS와 BFS
// 문제: 기본 dfs,bfs 방문 노드 출력
// 접근1: 그래프-> 기본 인접리스트로 구현 , 인접 행렬은 시간복잡도(n*n) 이라 으려서 인접 그래프로 푸는것을 추천
// 풀이: 
// 인접리스트 완성
// dfs 탐색
// bfs탐색
// 시간복잡도: O(간선의 갯수)
#define MAX 1001
int n, m, v;
vector<int> graph[MAX];
int visited[MAX];

void dfs(int node) {
	// 방문처리
	visited[node] = 1; cout << node << " ";
	// 인접한 노드 탐색
	for (int i = 0; i < graph[node].size(); i++) {
		int nodeIdx = graph[node][i];
		if (visited[nodeIdx] == 0) {
			dfs(nodeIdx);
		}
	}
}

void bfs(int node) {
	
	queue<int> q;
	// 큐에 푸쉬, 방문처리
	q.push(node); visited[node] = 1;  cout << node << " ";

	while (!q.empty()) {
		int cur_node = q.front(); 
		q.pop();
		// 인접 노드들 모두 큐에 푸쉬 및 방문처리
		for (int i = 0; i < graph[cur_node].size(); i++) {
			int next_idx = graph[cur_node][i];
			if (visited[next_idx] == 0) {
				// 큐 푸쉬 방문처리
				q.push(next_idx); visited[next_idx] = 1;  cout << next_idx << " ";
			}
		}
	}
}
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	cin >> n >> m >> v;
	// 인접리스트 그래프  입력
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	// 간선 여러개 있을 때 작은 번호부터 탐색위해 인접 리스트 정렬
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	// dfs,bfs
	dfs(v);
	memset(visited, 0, sizeof(visited));
	cout << '\n';
	bfs(v);
	return 0;
}
