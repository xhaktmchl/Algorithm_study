#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[세종대 알고리즘 트레이닝 수업0623 14번 O] 웜바이러스
문제:
접근:
풀이:

시간복잡도: O()=
*/

vector<int> v[110];
int n,num;
bool visit[110];
int cnt = 0;

//dfs 인접리스트
//2) 인접 리스트 반복무느올 탐색
//방문안했으면 
// 방문처리
// 카운트
// 재귀
void dfs(int cur) {
	
	int len = v[cur].size();
	for (int i = 0; i < len; i++) {
		int next = v[cur][i];
		if (visit[next] == 0) {
			visit[next] = 1;
			cnt++;
			dfs(next);
		}
	}
}


int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> n;

	//2.리스트 연결
	cin >> num;
	for (int i = 0; i < num; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	//3.dfs탐색
	visit[1] = 1;
	dfs(1);
	//4.갯수 출력
	cout << cnt;
	return 0;

}
