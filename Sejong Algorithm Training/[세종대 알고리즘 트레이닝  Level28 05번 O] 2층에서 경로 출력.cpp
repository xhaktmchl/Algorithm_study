#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[세종대 알고리즘 트레이닝  Level28 05번 O] 2층에서 경로 출력
문제:
접근:
풀이: dfs, 인접행렬
	//1.입력
	//2.dfs(노드,레벨)
	//1)방문처리, 경로추가
	//만약 레벨2라면
	//현재까지 경로 출력
	//2)인접노드 탐색
	//방문검사, 노드 있으면
	//dfs
	//경로 팝
시간복잡도: O(klogk)=
*/

int n;
int ad[100][100];
bool visit[100];
vector<int> path;
//2.dfs(노드,레벨)
//1)방문처리, 경로추가
//만약 레벨2라면
//현재까지 경로 출력
//2)인접노드 탐색
//방문검사, 노드 있으면
//dfs
//경로 팝
void dfs(int node, int cnt) {
	visit[node] = 1;
	path.push_back(node);

	if (cnt == 2) {
		int len = path.size();
		for (int i = 0; i < len; i++) {
			cout << path[i] << " ";
		}cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visit[i] == 0 && ad[node][i] == 1) {
			dfs(i, cnt + 1);
			path.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ad[i][j];
		}
	}
	//2.dfs(노드,레벨)
	dfs(0, 0);
	return 0;
}
