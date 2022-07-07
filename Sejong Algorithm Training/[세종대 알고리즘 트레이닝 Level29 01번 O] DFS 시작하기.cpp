#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level29 01번 O] DFS 시작하기
문제:
접근:
풀이:
	//1.입력: 인접행렬
	//2.dfs
	//3.출력:
시간복잡도: O()=
*/
int n;
int ad[110][110];
bool visit[110];

//dfs
//1)방문 표시, 출력
//2)반복문으로 인접 노드 탐색
//방문 안했는데
//노드 있으면 
//재귀
void dfs(int node) {
	visit[node] = 1;
	cout << node << " ";

	for (int i = 0; i < n; i++) {
		int next = i;
		if (!visit[next]) {
			if (ad[node][next] == 1) {
				dfs(next);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력: 인접행렬
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ad[i][j];
		}
	}
	//2.dfs
	dfs(0);
	//3.출력:
	return 0;
}
