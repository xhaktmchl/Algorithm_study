#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// [백준 13549 c++ VO] 숨바꼭질 3
// 문제: 
// 접근1: 최소시간 ->1차원 ,완탐 -> 시간복잡도 3^n 시간초과 예상
// 접근2: 최소시간 -> 완탐,그리디,dp,bfs-> -> 0,1초 걸리는 2가지 경우 -> bfs
// 0,1 초 걸리느 것이 달라서 원래 큐 1개로는 순서가 불가능 -> 데크 / 큐2개 이용 -> 큐2개 이용 선택
// 현재 큐, 다음큐 두개를 생성해 0초 걸리는건 현재큐에 계속 넣어주고, 1초 걸리는 것은 다음 큐에 넣어서 0,1초 걸리는 것 해결
// 시간복잡도: O(정점갯수+간선갯수) = n+3n 
// 풀이1: 
// bfs
// 현재 큐, 다음 큐 생성
// 큐에푸쉬 방문처리
// 1.n*2 인경우 0초 걸림
// 2.n-1 하는 경우 1초 걸림
// 3.n+1 경우 1초걸림 각각 탐색
// 0초 걸리는 큐를 모두 탐색하면 현재큐를 다음큐로 최신화, 다음큐 빈큐로 최신화
//개념:
//: next_q = queue<int>(); //빈 큐를 넣어서 큐를 초기화
// 풀이 2:  0초 걸리는것 먼저 탐색하면 다음큐 필요 없음
// 
#define MAX 200001
int n, k;
bool visit[MAX];
int dist[MAX];

void bfs(int start) {
	queue<int> q;
	q.push(start); visit[start] = 1;
	dist[start] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		// 1.n*2 인경우 0초 걸림
		// 시간이 적게 걸리느 것이 먼저 와야 최소시간 탐색 가능
		int nxt = now * 2;
		if (nxt < MAX && !visit[nxt]) {
			q.push(nxt); visit[nxt] = 1;
			dist[nxt] = dist[now]; // *2 이동시간은 0 초
		}// 2.n-1 하는 경우 1초 걸림
		nxt = now - 1;
		if (nxt >= 0 && !visit[nxt]) {
			q.push(nxt); visit[nxt] = 1;
			dist[nxt] = dist[now] + 1;
		}// 3.n+1 경우 1초걸림 각각 탐색
		nxt = now + 1;
		if (nxt <MAX && !visit[nxt]) {
			q.push(nxt); visit[nxt] = 1;
			dist[nxt] = dist[now] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> k;
	bfs(n);

	cout << dist[k] << '\n';
	return 0;
}
