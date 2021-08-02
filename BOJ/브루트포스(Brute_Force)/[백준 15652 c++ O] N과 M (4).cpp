#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 15652 c++ O] N과 M (4)
// 접근1: 완전탐색 -> 재귀dfs -> 재귀중간 순열 체크, 중복허용이라 방문배열 필요없음
// 접근2: 완전탐색 -> 재귀 -> 전역배열로 인덱스 인자를 넘겨줌 ->  중복허용이라 방문배열 필요없음
// 시간복잡도: 
// 재귀 < dfs 재귀가 더 빠름
// 풀이1: 
// 수 입력
// dfs재귀로 인자 재귀 내에 수열배열 넘겨주며 따로 저장 모든 수열 탐색
// 풀이2: 
// 수 입력
// 재귀로 전역배열로 수열 저장하고 수열의 인덱스 를 넘겨주며 저장 모든 수열 탐색
#define MAX 10
int n, m;
//int visit[MAX];
int a[MAX];

// 재귀
void re(int idx,int start) { // 현재 수열 저장위치, 시작위치
	//종료조건
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << " ";
		}cout << '\n';
		return;
	}
	// i부터 n까지 탐색
	for (int i = start; i <= n; i++) { // 중복허용 = 방문처리 없음
		a[idx] = i;
		re(idx + 1, i);
	}
}


int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> m;

	re(0,1); // 0 인덱스부터 시작
	return 0;
}
