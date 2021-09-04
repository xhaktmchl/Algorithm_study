#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// [백준 13913 c++ VV] 숨바꼭질 4 
// 문제: n에서 k 까지 걸리는 최소시간, 탐색 과정을 구해라
// 접근: 최소이동횟수 -> 완탐,그리디,dp,bfs-> -> dist배열에 이동거리 저장하며 탐색
// n이 10만이므로 20만보다 넘어가면 최소값 못나온다 -> MAX=20만
// 역추적 과정: from[next] = now 저장하면 그 전의 노드를 알 수 있음 
// bfs문제라는 것을 알아차리기가 어려웠음
// 시간복잡도: O(정점의 갯수+간선의 갯수) = O(n+3n) = 40만
// 풀이: 
// 위치 입력
// bfs로 n에서 n-1,n+1,2*n 위치로 이동 가능
// 방문,거리,과정 저장하며 탐색
// 최단시간 출력
// 역추정 과정으로 탐색 과정 저장 벡터에 저장 후 올바른 순서로 출력 
#define MAX 200001
int n, k;
bool visit[MAX]; // 방문배열
int dist[MAX]; // 거리배열
int from[MAX]; // 경로배열

void bfs() {
	queue<int> q;
	q.push(n); visit[n] = 1;
	dist[n] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int nxt; // 다음 노드
		nxt = now - 1; // n-1 경우
		if (nxt >= 0 && !visit[nxt]) { // 범위, 방문검사
			q.push(nxt); visit[nxt] = 1; // 방문처리
			dist[nxt] = dist[now] + 1; // 거리저장
			from[nxt] = now; // 경로저장
		}
		nxt = now + 1; // n+1 경우
		if (nxt < MAX && !visit[nxt]) {
			q.push(nxt); visit[nxt] = 1;
			dist[nxt] = dist[now] + 1;
			from[nxt] = now;
		}
		nxt = now*2; // n*2 경우
		if (nxt < MAX && !visit[nxt]) {
			q.push(nxt); visit[nxt] = 1;
			dist[nxt] = dist[now] + 1;
			from[nxt] = now;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> k;
	bfs(); // bfs 탐색

	cout << dist[k] << '\n';
	// 경로추적 및 저장
	int idx = k;
	vector<int> a; // 경로저장 벡터
	a.push_back(k);
	while (idx != n) {
		a.push_back(from[idx]);
		idx = from[idx]; // 인덱스 전 경로롤 최신화
	}
	// 경로출력
	for (int i = a.size() - 1; i >= 0; i--) {
		cout << a[i] << " ";
	}cout << '\n';
	return 0;
}
