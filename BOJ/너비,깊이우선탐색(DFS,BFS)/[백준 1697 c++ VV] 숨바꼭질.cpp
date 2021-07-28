#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 1697 c++ VV] 숨바꼭질 
// 문제: n에서 k 까지 걸리는 최소시간을 구해라
// 접근: 최소이동횟수 -> 그리디,dp,bfs-> -> dist배열에 이동거리 저장하며 탐색
// n이 10만이므로 20만보다 넘어가면 최소값 못나온다 -> MAX=20만
// bfs문제라는 것을 알아차리기가 어려웠음
// 시간복잡도: O(정점의 갯수+간선의 갯수) = O(n+3n)??
// 풀이: 
// 위치 입력
// bfs로 n에서 n-1,n+1,2*n 위치로 이동 가능
// 최단시간 출력
#define MAX 200001
int n, k;
int visited[MAX];
int dist[MAX];

void bfs(int node) {
	queue<int> q;
	q.push(node); visited[node] = 1;
	dist[node] = 0;
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		//n-1 위치
		if (now - 1 >= 0 && now - 1 < 200000) {
			if (visited[now - 1] == 0) {
				q.push(now - 1); visited[now - 1] = 1;
				dist[now - 1] = dist[now] + 1;
			}
		}
		//,n+1, 위치
		if (now + 1 >= 0 && now + 1 < 200000) {
			if (visited[now + 1] == 0) {
				q.push(now + 1);  visited[now + 1] = 1;
				dist[now + 1] = dist[now] + 1;
			}
		}
		//2*n 위치
		if (now *2 >= 0 && now *2 < 200000) {
			if (visited[now * 2] == 0) {
				q.push(now * 2); visited[now * 2] = 1;
				dist[now * 2] = dist[now] + 1;
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

	cout << dist[k];
	return 0;
}
