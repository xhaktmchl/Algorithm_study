#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 15657 c++ O] N과 M (8)
// 문제: n개의 자연수를 입력받아 m개의 숫자를 이용해 수열을 구현해서 출력, 사전순출력->입력배열 정렬, 중복허용->방문배열 없음, 배내림차순=현재 수부터 큰수 탐색
// 접근1: 완전탐색 -> 재귀dfs -> 재귀중간 순열 체크, 중복허용=방문배열 없음, 사전순=정렬 시키고 탐색 , 비내림차순 = 현재 인덱스 인자추가
// 접근2: 완전탐색 -> 재귀 -> 전역배열로 인덱스 인자를 넘겨줌 ->   중복허용=방문배열 없음, 사전순=정렬 시키고 탐색, 비내림차순 = 현재 인덱스 인자추가
// 시간복잡도: 
// 재귀 < dfs 재귀가 더 빠름
// 풀이1: 
// 수 입력
// dfs재귀로 인자 재귀 내에 수열배열 넘겨주며 따로 저장 모든 수열 탐색
// 풀이2: 
// 수 입력, 배열 입력 및 사전순 = 정렬
// 재귀로 전역배열로 수열 저장하고 수열의 인덱스,  넘겨주며 저장 모든 수열 탐색, 중복허용=방문배열 없음, 비내림차순 = 탐색시작 인덱스 추가
// 수열 완성되면 출력
#define MAX 10
int n, m;
int a[MAX];
int b[MAX];

void re(int idx,int start) {
	// 종료조건 ,수열완성 수열출력
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << b[i] << " ";
		}cout << '\n';
		return;
	}
	// 비내림차순 탐색, 
	for (int i = start; i < n; i++) {
		b[idx] = a[i];
		re(idx + 1, i); // 현재 집어넣은 수부터 큰수 다시 탐색
	}
}
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);

	re(0,0);
	return 0;
}
