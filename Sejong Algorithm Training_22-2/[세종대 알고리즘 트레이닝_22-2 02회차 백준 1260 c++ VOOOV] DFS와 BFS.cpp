#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
/*
[세종대 알고리즘 트레이닝_22-2 02회차 백준 1260 c++ VOOOV] DFS와 BFS
문제:
// 접근1: 1차원 그래프-> 기본 인접리스트로 구현 , 인접 행렬은 시간복잡도(n*n) 이라 느려서 인접 그래프로 푸는것을 추천
풀이: 
	//1.입력
	//양방향 인접 리스트
	// 정렬: 인접 노드중 작은 노드부터 방문
	//2.dfs
	//3.bfs
시간복잡도: O()= 
개념:
*/
int n, m, s;
vector<int> v[1010];
bool visit[1010];

//2.dfs
//1)방문처리 , 출력
//2)인접 리스트 탐색
//방문 안했으면 dfs
void dfs(int node) {
	visit[node] = 1; 
	cout << node << " ";

	for (int i = 0; i < v[node].size(); i++) {
		int nn = v[node][i];
		if (!visit[nn]) {
			dfs(nn);
		}
	}
}

//3.bfs
//1)큐 생성
//큐 푸쉬, 방문처리
//2)큐 빌때까지 반복
//큐 프론트 추출 , 출력
//인접 노드 탐색
//방문 안했으면 
// 큐에푸쉬, 방문처리
void bfs(int node) {
	queue<int> q;
	q.push(node); visit[node] = 1;

	while (!q.empty()) {
		node = q.front(); cout << node << " ";
		q.pop();

		for (int i = 0; i < v[node].size(); i++) {
			int nn = v[node][i];
			if (!visit[nn]) {
				q.push(nn); 
				visit[nn] = 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	//양방향 인접 리스트
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	// 정렬: 인접 노드중 작은 노드부터 방문
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	//2.dfs
	dfs(s);
	//visit 초기화
	memset(visit, 0, sizeof(visit));
	cout << '\n';
	//3.bfs
	bfs(s);
	return 0;
}
