#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 15661 c++ O] 링크와 스타트
// 문제:스타트와 링크 문제에서 팀 인원이 서로 다른다는 조건만 추가됨
// 접근: n 명 중 팀 정하기 -> 완전탐색 재귀 / dfs -> 재귀선택
// 팀 배정하는 경우의 수 1~n까지 a,b 팀 되는 경우 2가지 =O(2^n)=2^20 시간통과
// 재귀 -> 인자(추가할 사람 번호, a,b팀 배열)
// 종료조건 ,사람 분배가 끝났으면 인원 최소 1명 이상인지 검사 -> 가중치 차이 구하기,최소값 저장
// 시간복잡도: O(2^n)
// 풀이: 
// 가중치 입력
// 재귀시작
// 재귀1. a팀에 들어가는 경우
// 재귀2. b팀에 들어가는 경우
// 종료조건, 1.사람 분배가 끝났으면 인원 최소 1명 이상인지 검사 -> 가중치 차이 구하기,최소값 저장
// 최소값 출력
#define MAX 21
int n;
int s[MAX][MAX];
int minN = 40001;
// 재귀
void re(int idx, vector<int> a, vector<int> b) {
	// 종료조건 n명의 사람들이 팀이 결정되면
	if (idx == n) {
		// 인원수 맞으면
		if (a.size() >= 1 || b.size() >= 1) {
			int suma = 0, sumb = 0;
			// a팀 가중치 구하
			for (int i = 0; i < a.size(); i++) {
				for (int j = i; j < a.size(); j++) {
					suma += s[a[i]][a[j]] + s[a[j]][a[i]];
				}
			}
			// b팀 가중치 구하
			for (int i = 0; i < b.size(); i++) {
				for (int j = i; j < b.size(); j++) {
					sumb += s[b[i]][b[j]] + s[b[j]][b[i]];
				}
			}
			minN = min(minN, abs(suma - sumb));
		}
		return; // 성공한 경우, 불가능한 경우 다 중단
	}
	
	// 재귀1.a팀인 경우
	a.push_back(idx);
	re(idx + 1, a, b);
	a.pop_back();
	// 재귀2. b팀인 경우
	b.push_back(idx);
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
