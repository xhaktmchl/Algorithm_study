#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring> // memset 
using namespace std;
/*
[세종대 알고리즘 트레이닝 수업0623 15번 V] Graph 순회
문제:
접근:
풀이:

시간복잡도: O()=
*/

vector<int> v[110];
int n, k, s;
bool visit[110];
bool visit2[110];

//dfs 인접리스트
//2) 인접 리스트 반복무느올 탐색
//방문안했으면 
// 방문처리
// 카운트
// 재귀


void pre(int cur) {
	cout << cur << " ";
	visit[cur]=1;

	int len = v[cur].size();
	for (int i = len-1; i >=0; i--) {
		int next = v[cur][i];
		if (visit[next] == 0) {
			pre(next);
		}
	}
}


void post(int cur) {
	visit[cur] = 1;

	int len = v[cur].size();
	for (int i = len - 1; i >= 0; i--) {
		int next = v[cur][i];
		if (visit[next] == 0) {
			post(next);
		}
	}

	cout << cur << " ";
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	// 인접 리스트 정렬
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	pre(s);
	cout << '\n';
	memset(visit, 0, sizeof(visit));
	post(s);
	return 0;

}
