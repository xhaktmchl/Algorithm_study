#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 13913 c++ V] 숨바꼭질 4 
// 문제: n에서 k 까지 걸리는 최소시간, 탐색 과정을 구해라
// 접근: 최소이동횟수 -> 그리디,dp,bfs-> -> dist배열에 이동거리 저장하며 탐색
// n이 10만이므로 20만보다 넘어가면 최소값 못나온다 -> MAX=20만
// 역추적 과정: from[next] = now 저장하면 그 전의 노드를 알 수 있음 
// bfs문제라는 것을 알아차리기가 어려웠음
// 시간복잡도: O(정점의 갯수+간선의 갯수) = O(n+3n)??
// 풀이: 
// 위치 입력
// bfs로 n에서 n-1,n+1,2*n 위치로 이동 가능
// 방문,거리,과정 저장하며 탐색
// 최단시간 출력
// 역추정 과정으로 탐색 과정 저장 벡터에 저장 후 올바른 순서로 출력 
#define MAX 200001
int n, k;
int graph[MAX];
int visited[MAX];
int dist[MAX];
int from[MAX];

void bfs(int node) {
	queue<int> q;
	// 큐에푸쉬, 방문처리 , 거리저장, 과정 저장
	q.push(node); visited[node] = 1; 
	dist[node] = 0;
	from[node] = node;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		//(now - 1 경우
		if (now - 1 >= 0 && now - 1 < MAX) { // 범위
			if (visited[now - 1] == 0) { // 방문검사
				q.push(now - 1); visited[now - 1]=1;
				dist[now - 1] = dist[now] + 1;
				from[now - 1] = now; //  탐색 과정 저장
			}
		}//now + 1 경우
		if (now + 1 >= 0 && now + 1 < MAX) {
			if (visited[now + 1] == 0) {
				q.push(now + 1); visited[now + 1] = 1;
				dist[now + 1] = dist[now] + 1;
				from[now + 1] = now;
			}
		} // now*2 경우
		if (now*2 >= 0 && now * 2 < MAX) {
			if (visited[now * 2] == 0) {
				q.push(now * 2); visited[now * 2] = 1;
				dist[now * 2] = dist[now] + 1;
				from[now * 2] = now;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> k;

	bfs(n);

	cout << dist[k] << '\n';

	// 역추적하며 탐색 과정 저장
	vector<int> v;
	int now = k;
	v.push_back(now);
	while (now != n) {
		now = from[k];
		v.push_back(now);
		k = now;
		if (now == n) { break; }
	}
	// 원래 탐색 순으로 출력
	for (int i = v.size()-1; i >= 0; i--)
	{
		cout << v[i] << " ";
	}
	cout << '\n';
	return 0;
}
