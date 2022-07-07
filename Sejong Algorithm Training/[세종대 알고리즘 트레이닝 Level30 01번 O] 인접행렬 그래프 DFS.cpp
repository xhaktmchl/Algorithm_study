#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level30 01번 O] 인접행렬 그래프 DFS
문제:
접근:
풀이:
	//1.입력: 노드
	//2.dfs
	//1)방문처리, 출력
	//2)인접 노드 탐색
	//다음 노드
	//방문 안했는데 노드 있으면 
	//dfs
시간복잡도: O()=
*/
int n;
bool visit[10];
int ad[10][10] = {
	{0,0,1,1,0,1},
	{0,0,0,1,1,1},
	{0,0,0,0,1,1},
	{0,0,0,0,0,0},
	{1,0,0,0,0,1},
	{0,0,0,0,0,0}
};


//2.dfs
//1)방문처리, 출력
//2)인접 노드 탐색
//다음 노드
//방문 안했는데 노드 있으면 
//dfs
void dfs(int node) {
	visit[node] = 1;
	cout << node << " ";

	for (int i = 0; i < 6; i++) {
		int next = i;
		if (visit[next] == 1)continue;
		if (ad[node][i] == 1) {
			dfs(next);
		}
	}
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력: 노드
	cin >> n;
	//2.dfs
	dfs(n);
	return 0;
}
