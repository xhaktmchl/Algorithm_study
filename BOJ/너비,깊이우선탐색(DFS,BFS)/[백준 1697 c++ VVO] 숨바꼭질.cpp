#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 1697 c++ VVO] 숨바꼭질 
// 문제: n에서 k 까지 걸리는 최소시간을 구해라
// 접근: 최소이동횟수 -> 완탐,그리디,dp,bfs-> 완탐은 시간 3^10만 = 시간초과
// 접근2: bfs -> dist배열에 이동거리 저장하며 탐색
// n이 10만이므로 20만보다 넘어가면 최소값 못나온다 -> MAX=20만
// bfs문제라는 것을 알아차리기가 어려웠음
// 시간복잡도: O(정점의 갯수+간선의 갯수) = O(n+3n)??
// 풀이: 
// 위치 입력
// bfs로 n에서 n-1,n+1,2*n 위치로 이동 가능
// 최단시간 출력
#define MAX 200001
int n, k;
bool visit[MAX];
int dist[MAX];

void bfs(int idx) {
	queue<int> q;
	q.push(idx); visit[idx] = 1; // 처음위치 방문
	dist[idx] = 0;

	while (!q.empty()) {
		idx = q.front();
		q.pop();
		// 2*x 인 경우
		if (idx * 2 <= 200000 && !visit[idx*2]) { // 범위 , 방문검사
			q.push(idx * 2); visit[idx * 2] = 1;
			dist[idx * 2] = dist[idx] + 1; // 거리저장
		}// x+1인 경우
		if (idx +1 <= 200000 && !visit[idx +1]) {
			q.push(idx + 1); visit[idx + 1] = 1;
			dist[idx + 1] = dist[idx] + 1;
		}//x-1인 경우
		if (idx - 1 >= 0 && !visit[idx -1]) {
			q.push(idx - 1); visit[idx - 1] = 1;
			dist[idx - 1] = dist[idx] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n >> k;
	//bfs 탐색
	bfs(n); 
	cout << dist[k] << '\n';
	return 0;
}
