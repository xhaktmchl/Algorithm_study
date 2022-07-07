#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level30 02번 O] 가중치 인접행렬 DFS
문제:
접근:
풀이:
	//1.입력
//2.dfs
//2.dfs
//1)인접 노드 탐색
//방문 검사
//노드가 있으면
// 방문처리
//가중치 누적, 출력
//dfs
시간복잡도: O(klogk)=
*/
int n;
bool visit[10];
int ad[10][10] = {
	{0,0,1,0,2,0},
	{5,0,3,0,0,0},
	{0,0,0,0,0,7},
	{2,0,0,0,8,0},
	{0,0,9,0,0,1},
	{4,0,0,7,0,0}
};
int sum = 0;

//2.dfs
//1)인접 노드 탐색
//방문 검사
//노드가 있으면
// 방문처리
//가중치 누적, 출력
//dfs
void dfs(int node) {
	for (int i = 0; i < 6; i++) {
		int next = i;
		if (visit[next] == 1) { continue; }
		if (ad[node][next] != 0) {
			visit[next] = 1;
			sum += ad[node][next];
			cout << next << " " << sum << '\n';
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	cin >> n;
	//2.dfs
	visit[n] = 1;
	cout << n << " " << sum << '\n';
	dfs(n);
	return 0;
}
