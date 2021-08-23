#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 15652 c++ OO] N과 M (4)
// 접근: 완전탐색 -> 재귀 -> 전역배열로 인덱스 인자를 넘겨줌 ->  중복허용이라 방문배열 필요없음
// 시간복잡도: O(n^n 보다 작다) 
// 풀이1: 
// 수 입력
// 재귀로 전역배열로 수열 저장하고 수열의 인덱스 를 넘겨주며 저장 모든 수열 탐색
#define MAX 10
int n, m;
int a[MAX];

void re(int idx,int start) {
	// 종료조건 , 수열 완성
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << " ";
		}cout << '\n';
		return;
	}
	// 종료조건 불가능 없음

	// 중복허용 비내림차순 탐색
	for (int i = start; i <= n; i++) {
		a[idx] = i;
		re(idx + 1, i);
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n >> m;
	re(0,1);
	return 0;
}
