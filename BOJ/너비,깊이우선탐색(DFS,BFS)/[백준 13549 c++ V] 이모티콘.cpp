#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 13549 c++ V] 이모티콘
// 문제: 화면에 s개의 이모티콘이 되기까지 최소시간을 구해라
// 접근: 최소시간 -> 그리디,dp,bfs-> -> 0,1초 걸리는 2가지 경우 -> bfs
// 0,1 초 걸리느 것이 달라서 원래 큐 1개로는 순서가 불가능 -> 데크 / 큐2개 이용 -> 큐2개 이용 선택
// 현재 큐, 다음큐 두개를 생성해 0초 걸리는건 현재큐에 계속 넣어주고, 1초 걸리는 것은 다음 큐에 넣어서 0,1초 걸리는 것 해결
// 시간복잡도: O() 
// 풀이: 
// bfs
// 현재 큐, 다음 큐 생성
// 큐에푸쉬 방문처리
// 1.n*2 인경우 0초 걸림
// 2.n-1 하는 경우 1초 걸림
// 3.n+1 경우 1초걸림 각각 탐색
// 0초 걸리는 큐를 모두 탐색하면 현재큐를 다음큐로 최신화, 다음큐 빈큐로 최신화
//개념:
//: next_q = queue<int>(); //빈 큐를 넣어서 큐를 초기화
#define MAX 200000
int n, k;
int visited[MAX];
int dist[MAX];

void bfs(int start) {
	queue<int> q; // 0초 걸리는 현재 큐
	queue<int> next_q; // 1초 걸리는 큐
	// 큐에푸쉬 방문처리
	q.push(start); visited[start] = 1;
	dist[start] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		// n*2 인경우 0초 걸림
		if (now * 2 >= 0 && now * 2 < MAX) {
			if (visited[now*2] == 0) {
				q.push(now * 2); visited[now * 2] = 1;
				dist[now * 2] = dist[now];
			}
		}
		// n-1 하는 경우 1초 걸림
		if (now - 1 >= 0 && now-1< MAX) {
			if (visited[now - 1] == 0) {
				next_q.push(now - 1); visited[now - 1] = 1;
				dist[now - 1] = dist[now] + 1;
			}
		}// n+1 경우 1초걸림
		if (now + 1 >= 0 && now + 1 < MAX) {
			if (visited[now + 1] == 0) {
				next_q.push(now + 1); visited[now + 1] = 1;
				dist[now + 1] = dist[now] + 1;
			}
		}
		// 현재 큐 다 처리했으면
		if (q.empty()) {
			q = next_q;
			next_q = queue<int>(); //빈 큐를 넣어서 큐를 초기화
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
	return 0;
}
