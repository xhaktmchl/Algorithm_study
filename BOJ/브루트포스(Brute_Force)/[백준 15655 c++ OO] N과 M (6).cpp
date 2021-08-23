#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 15655 c++ OO] N과 M (6)
// 문제: n개의 자연수증 m개의 숫자를 이용해 수열을 구현해서 출력,오름차순=입력배열 정렬하고 탐색
// 접근: 완전탐색 -> 재귀 -> 전역배열로 인덱스 인자를 넘겨줌 ->   중복방지는 오름차순에서 자동으로 해결, 오름차순=start인덱스로 탐색위치 조절 시키고 탐색
// 시간복잡도: O(n^m) = 8^8 =1600만 보다 작다 
// 풀이1:  
// 수 입력, 배열 입력 및 정렬
// 재귀로 전역배열로 수열 저장하고 수열의 인덱스,  넘겨주며 저장 모든 수열 탐색, 오름차순=탐색시작 인덱스 위치 인자로 넘겨줌, 
#define MAX 10
int n, m;
int a[MAX],b[MAX];

void re(int idx,int start) { // 만든 수열 인덱스, 현재 탐색시작 인덱스
	// 종료조건, 가능
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << b[i] << " ";
		}cout << '\n';
		return;
	}
	// 종료 불가능 없음

	// 배열 중 현재위치에서 ~n까지 탐색 
	for (int i = start; i < n; i++) {
		b[idx] = a[i]; // 수열대입
		re(idx + 1, i + 1);// 오름차순-> 다음 인덱스부터 탐색
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n); // 오름차순출력 -> 정렬
	re(0, 0);// 완전탐색 재귀
	return 0;
}
