#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[세종대 알고리즘 트레이닝  Level28 06번 O] 문자열 노드 DFS
문제:
접근:
풀이: dfs, 인접행렬
	//1.입력
	//2.인접행렬 dfs(노드)
	//1)인접 노드 탐색
	//방문검사, 노드 있으면
	//방문처리, 출력
	//dfs
	//방문처리 취소
시간복잡도: O(n+m)=
*/
char ar[10];
int ad[10][10];
bool visit[10];

//2.인접행렬 dfs(노드)
	//1)인접 노드 탐색
	//방문검사, 노드 있으면 
	//방문처리, 출력
	//dfs
	//방문처리 취소
void dfs(int node) {
	for (int i = 0; i < 8; i++) {
		if (visit[i] == 0 && ad[node][i] == 1) {
			visit[i] = 1;
			cout << ar[i];
			dfs(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> ar;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> ad[i][j];
		}
	}
	//2.인접행렬 dfs(노드)
	//1)인접 노드 탐색
	//방문검사, 노드 있으면 
	//방문처리, 출력
	//dfs
	//방문처리 취소
	visit[0] = 1;
	cout << ar[0];
	dfs(0);
	return 0;
}
