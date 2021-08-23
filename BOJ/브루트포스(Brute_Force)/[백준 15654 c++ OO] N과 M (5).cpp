#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 15654 c++ O] N과 M (5)
// 문제: n개의 자연수증 m개의 숫자를 이용해 수열을 구현해서 출력,중복방지,오름차순
// 접근: 완전탐색 -> 재귀 -> 전역배열로 인덱스 인자를 넘겨줌 ->   중복방지=방문배열, 오름차순=정렬 시키고 탐색
// 시간복잡도: 
// 재귀 < dfs 재귀가 더 빠름
// 풀이2: 
// 수 입력, 배열 입력 및 정렬
// 재귀로 전역배열로 수열 저장하고 수열의 인덱스 를 넘겨주며 저장 모든 수열 탐색, 중복방지 방문처리,초기화
#define MAX 10
int n, m;
int a[MAX],b[MAX];
bool visit[MAX];

void re(int idx) {
	// 종료조건 가능한 경우
	if (idx == m) { 
		for (int i = 0; i < m; i++) {
			cout << b[i] << " ";
		}cout << '\n';
		return;
	}
	// 종료조건 불가능 없음

	// 주어진 수열 탐색, 중복안됨
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = 1; b[idx] = a[i];
			re(idx + 1);
			visit[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n); // 사전순 출력위해 정렬
	re(0);
	return 0;
}
