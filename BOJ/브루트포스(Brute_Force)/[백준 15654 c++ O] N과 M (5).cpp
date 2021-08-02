#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 15654 c++ O] N과 M (5)
// 문제: n개의 자연수증 m개의 숫자를 이용해 수열을 구현해서 출력,중복방지,오름차순
// 접근1: 완전탐색 -> 재귀dfs -> 재귀중간 순열 체크, 중복방지=방문배열, 오름차순=정렬 시키고 탐색
// 접근2: 완전탐색 -> 재귀 -> 전역배열로 인덱스 인자를 넘겨줌 ->   중복방지=방문배열, 오름차순=정렬 시키고 탐색
// 시간복잡도: 
// 재귀 < dfs 재귀가 더 빠름
// 풀이1: 
// 수 입력
// dfs재귀로 인자 재귀 내에 수열배열 넘겨주며 따로 저장 모든 수열 탐색
// 풀이2: 
// 수 입력, 배열 입력 및 정렬
// 재귀로 전역배열로 수열 저장하고 수열의 인덱스 를 넘겨주며 저장 모든 수열 탐색, 중복방지 방문처리,초기화
#define MAX 10
int n, m;
bool visit[MAX];
int a[MAX];
int b[MAX];

// 완전탐색 재귀
void re(int idx) {
	// 종료조건, 수열 완성시
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << b[i] << " ";
		}cout << '\n';
		return;
	}
	// 배열의 1~n인덱스까지 탐색
	for (int i = 1; i <= n; i++) {
		if (visit[i]) { continue; }
		visit[i] = 1; b[idx] = a[i]; // 중복방지 방문처리, 수열 추가
		re(idx + 1);
		visit[i] = 0; // 재귀이므로 방문 초기화
	}
}

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	// 오름차순출력 -> 정렬
	sort(a+1, a + n + 1);
	re(0); // 완전탐색 재귀
	
	return 0;
}
