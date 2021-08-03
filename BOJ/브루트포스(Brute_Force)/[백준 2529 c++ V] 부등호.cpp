#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 2529 c++ V] 부등호 
// 문제: 주어진 부등호를 만족시키는 수열중 최대,최소값 구하기
// 접근: 최대,최소-> 그리디,dp 모르겟음 -> 완전탐색 재귀 -> 
// 숫자달라야 = 중복방지=방문배열 사용 , 수열 이어붙히기= string형 사용
// 재귀 인자(숫자의 개수, 현재까지의 수열)
// 시간복잡도: O(9^k)= 9^9 ??
// 풀이: 
// 부등호 입력
// 완전탐색 재귀
// 각 자리에서 0~9중 선택 수열 이어붙히기, 방문배열 사용
// 종료조건, 수열 완성시 부등호 만족 검사, 최대,최소수열 저장
#define MAX 10
int k;
char cp[MAX];
bool visit[MAX];
string maxN="0000000000", minN="9999999999";

void re(int idx, string s) {
	// 종료조건, 수열 완성시 부등호 만족 검사, 최대,최소수열 저장
	if (idx == k + 1) {
		// 수열 부등호 검사 // 수열을 만드는 반복문에 부등호 검사하면 백트래킹-> 시간단축
		for (int i = 0; i < k; i++) {
			if (cp[i] == '<' && s[i] >= s[i + 1]) { return; }
			if (cp[i] == '>' && s[i] <= s[i + 1]) { return; }
		}
		maxN = max(maxN, s);
		minN = min(minN, s);
		return;
	}
	//재귀
	// 각 자리에서 0~9중 선택 수열 이어붙히기, 방문배열 사용
	for (int i = 0; i <= 9; i++) {
		if (visit[i]) { continue; }
		// 이곳에 수열을 만드는 반복문에 부등호 검사하면 백트래킹-> 시간단축
		visit[i] = 1; 
		re(idx + 1, s + to_string(i));
		visit[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> cp[i];
	}
	// 완전탐색 재귀
	string s;
	re(0, s);

	cout << maxN << '\n';
	cout << minN << '\n';
	return 0;
}
