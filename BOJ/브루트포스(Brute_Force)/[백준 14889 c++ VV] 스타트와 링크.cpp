#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 14889 c++ VV] 스타트와 링크
// 문제:
// 접근: n 명 중 팀 정하기 -> 완전탐색 재귀 / dfs -> 재귀선택
// 팀 배정하는 경우의 수 1~n까지 a,b 팀 되는 경우 2가지 =O(2^n)
// 재귀 -> 인자(추가할 사람 번호, a,b팀의 목록)
// 종료조건 ,사람 분배가 끝났으면 인원 잘 맞는지 검사 -> 가중치 차이 구하기,최소값 저장
// 접근2: 백트래킹 적용 가능 -> 뽑는 인원수가 n/2을 넘어가면 재귀 중단
// 시간복잡도: O(2^n)
// 풀이: 
// 가중치 입력
// 재귀시작
// 재귀1. a팀에 들어가는 경우
// 재귀2. b팀에 들어가는 경우
// 종료조건, 1.사람 분배가 끝났으면 인원 잘 맞는지 검사 -> 가중치 차이 구하기,최소값 저장
// 종료조건 2.백트래킹 적용 가능 -> 뽑는 인원수가 n/2을 넘어가면 재귀 중단
// 최소값 출력
#define MAX 21
int n;
int s[MAX][MAX];
int minN = 30000;

void re(int idx, vector<int> a, vector<int> b) {
	// 종료조건, 사람 분배가 끝났으면 인원 잘 맞는지 검사 -> 가중치 차이 구하기,최소값 저장
	if (idx == n) {
		int size = a.size();
		if (size == n / 2) {
			// 가중침 합
			int suma = 0, sumb = 0;
			for (int i = 0; i < size; i++) {
				for (int j = i + 1; j < size; j++) {
					suma += s[a[i]][a[j]] + s[a[j]][a[i]]; // a팀 가중치
					sumb += s[b[i]][b[j]] + s[b[j]][b[i]]; // b 팀 가중치
				}
			}
			minN = min(minN, abs(suma - sumb));// 가중치 차이 구하기,최소값 저장
		}
		return;
	}
	// 백트래킹: 뽑는 인원수가 n/2을 넘어가면 재귀 중단 -> 속도 빨라짐
	if (a.size() > n / 2 || b.size() > n / 2) { return; }

	// 재귀
	a.push_back(idx);// 재귀1. a팀에 들어가는 경우
	re(idx + 1,a , b);
	a.pop_back();
	b.push_back(idx);// 재귀2. b팀에 들어가는 경우
	re(idx + 1, a, b);
}
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}

	vector<int> a;
	vector<int> b;
	re(0, a, b);

	cout << minN << '\n';
	return 0;
}
