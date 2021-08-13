#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 15658 c++ O] 연산자 끼워넣기 (2)
// 문제: 가능한 연산자의 계산 결과 중 최대,최소 구하기
// 접근: 가능한 계산결과 중 최대 최소 -> 완탐,그리디,dp -> 완탐(재귀 조합) -> 각 4가지 연산 경우 모든 재귀 -> 연산자의 갯수가 범위 안에 있으면
// 백트래킹으로 시간 줄일 수 있는데 답이 틀림
// 재귀인자(현재 계산할 인덱스, 현재까지 계산 결과)
// 시간복잡도: O(4^(n-1)) : 4^10 = 약100만 
// 접근2: 완탐 재귀(순차) ->  시간초과 (이유를 모르겠음
// 풀이1: 완탐 재귀 조합
// 수열 입력
// 완탐 재귀 (, 중복없이 다음 인덱스 탐색, 수열이 끝까지 탐색했을 때 종료)
#define MAX 21
int n;
int a[MAX];
int c[4];
int check[4];
int minN=1000000001, maxN=-1000000001;

// 재귀 조합
void re(int idx, int sum) {// 현재 계산할 인덱스,현재까지 계산 결과
	// 종료조건, n 개 까지 계산 했을 때 // 연산자의 갯수 넘지 않으면
	if (idx == n) {
		if (check[0] <= c[0] && check[1] <= c[1] && check[2] <= c[2] && check[3] <= c[3]) {
			maxN = max(maxN, sum);
			minN = min(minN, sum);
		}
		return;
	}
	// 불가능한 경우 : 없음

	// 재귀 조합: 4가지 계산 
	check[0]++; re(idx + 1, sum + a[idx]); check[0]--; // +
	check[1]++; re(idx + 1, sum - a[idx]); check[1]--; // -
	check[2]++; re(idx + 1, sum * a[idx]); check[2]--; // *
	check[3]++; re(idx + 1, sum / a[idx]); check[3]--; // /
}

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// 연산자 개수 입력
	for (int i = 0; i < 4; i++) {
		cin >> c[i];
	}
	// 완탐 재귀
	re(1, a[0]); // 첫 번째 무조건 포함.
	cout << maxN << '\n' << minN << '\n';
	return 0;
}



