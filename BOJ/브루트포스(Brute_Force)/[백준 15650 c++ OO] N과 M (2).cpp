#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 15650 c++ OO] N과 M (2) 
// 접근: 오름차순 중복없는 순열 탐색 -> 완탐재귀
// 시간복잡도: O(n^m) = 8^8 = 1600만
// 풀이1: 
#define MAX 10
int n, m;
int a[MAX];

void re(int idx, int start) {
	// 종료조건, 가능한 경우
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << " ";
		}cout << '\n';
		return;
	}
	// 불가능한 경우, 없음
	
	// start부터 뒤의 수 오름차순 탐색
	for (int i = start; i <= n; i++) {
		a[idx] = i;
		re(idx + 1, i + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n >> m;
	re(0, 1);
	return 0;
}
