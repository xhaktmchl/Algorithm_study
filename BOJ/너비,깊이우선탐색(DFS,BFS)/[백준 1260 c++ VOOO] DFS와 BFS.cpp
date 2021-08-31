#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 1260 c++ VOOO] DFS와 BFS
// 문제: 기본 dfs,bfs 방문 노드 출력
// 접근1: 1차원 그래프-> 기본 인접리스트로 구현 , 인접 행렬은 시간복잡도(n*n) 이라 느려서 인접 그래프로 푸는것을 추천
// 풀이: 
// 인접리스트 완성
// 작은 노드부터 탐색을위해 인접리스트 정렬
// dfs 탐색
// bfs탐색
// 시간복잡도: O(간선의 갯수*2) = 20000
#define MAX 1001
int n, m, a,b,s;
vector<int> v[MAX];
bool visit[MAX];

void dfs(int node) {
	// 방문처리
	visit[node] = 1; 
	cout << node << " ";
	// 인접한 노드 탐색
	for (int i = 0; i < v[node].size(); i++) {
		int idx = v[node][i];
		if (!visit[idx]) {
			dfs(idx);
		}
	}
}

void bfs(int node) {
	queue<int> q;
	q.push(node); visit[node] = 1;// 큐에 푸쉬, 방문처리
	cout << node << " ";

	while (!q.empty()) {
		node = q.front(); 
		q.pop();
		// 인접 노드들 모두 큐에 푸쉬 및 방문처리
		for (int i = 0; i < v[node].size(); i++) {
			int next_idx = v[node][i];
			if (!visit[next_idx]) {
				q.push(next_idx); visit[next_idx] = 1;
				cout << next_idx << " ";
			}
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	// 인접리스트 그래프  입력
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) { // 작은 노드부터 탐색을 위한 정렬
		sort(v[i].begin(), v[i].end());
	}
	// dfs,bfs
	dfs(s);
	memset(visit, 0, sizeof(visit));
	cout << '\n';
	bfs(s);
	return 0;
}
