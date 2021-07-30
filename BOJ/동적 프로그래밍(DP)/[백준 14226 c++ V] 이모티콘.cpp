#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 14226 c++ V] 이모티콘
// 문제: 화면에 s개의 이모티콘이 되기까지 최소시간을 구해라
// 접근: 최소시간 -> 그리디,dp,bfs-> -> dp는 된다는데 s-1고려하는 것 모르겠음 
// 접근2: bfs
// 총 3가지 경우
// 1.화면 -> 클립보드 덮어쓱: (s,c) -> (s,s)
// 2. 화면 -1 -> (s,c)->(s-1,c)
// 3. 클립보드 -> 화면 붙혀넣기 : (s,c)->(s+c,c)
// 따라서 2차원으로 생각 (화면의 이모티콩, 클립보드 이모티콘)
// 시간복잡도: O() 
// 풀이: 
// s 입력
// bfs (1.2.3) 조건 탐색
// 화면에 s 개의 이모티콘 dist[s][0]~d[s][s] 중 최소시간 출력
// 주의: vs에선 답이 이상한데 백준에선 정답
#define MAX 2001
int s;
int visited[MAX][MAX];
long long dist[MAX][MAX];

void bfs(int start) {
	queue<pair<int,int>> q;
	q.push({ start,0 }); visited[start][0] = 1;
	dist[start][0] = 0;

	while (!q.empty()) {
		int s = q.front().first; //  화면의 이모티콘 갯수
		int clip = q.front().second; // 클립보드 이모티콘 개수
		q.pop();

		// 화면 -> 클립보드 덮어쓱
		if (visited[s][s] == 0) {
			q.push({ s,s }); visited[s][s] = 1;
			dist[s][s] = dist[s][clip] + 1;
		}
		// 화면 -1
		if (s - 1 >= 0 && visited[s -1][clip] == 0) {
			q.push({ s - 1,clip }); visited[s - 1][clip] = 1;
			dist[s - 1][clip] = dist[s][clip] + 1;
		}
		// 클립보드 -> 화면 붙혀넣기
		if (s + clip <= 2000  && visited[s + clip][clip] == 0) {
			q.push({ s + clip ,clip }); visited[s + clip][clip] = 1;
			dist[s + clip][clip] = dist[s][clip] + 1;
		}
		
	}
}
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> s;
	bfs(1);

	// 화면에s 개 일때 최소 시간 구하기
	long long minN;
	for (int i = 0; i <= s; i++) {
		if (visited[s][i] != 0) {
			minN = min(minN, dist[s][i]);
		}
	}
	cout << minN << '\n';
	return 0;
}
