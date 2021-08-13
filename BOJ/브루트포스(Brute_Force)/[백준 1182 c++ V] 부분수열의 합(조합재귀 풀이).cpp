#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 1182 c++ V] 부분수열의 합
// 문제: 원하는 합이 되는 부분수열의 갯수 구하기
// 접근: 부분수열 갯수 구하기 -> 완전탐색(재귀,dfs) -> 재귀 사용
// 재귀인자(현재 수열의 인덱스, 현재까지  부분수열 합)
// 시간복잡도: O(2^n) : 2^20 < 1억 
// 풀이1: 모든 재귀 순차탐색
// 수여 입력
// 완탐 재귀 
// 주의: 공집합의 경우 예외처리, 합이 완성돼도 이후 더해져서 같은 합이 나올 수 있기 때문에 중단해주면 안됌
// 풀이2: 완탐 재귀 조합탐색
#define MAX 21
int n, s;
int a[MAX];
int ans = 0;

void re(int idx, int sum) {//현재 수열의 인덱스, 현재까지  부분수열 합
	// 종료조건, 합이 완성 됐을 때
	if (idx == n) { 
		if (sum == s) { // 뒤의 부분수열에서 또 합이 만들어 질 수 있어서 return;안됌
			ans++;
		}
		return; }
	
	re(idx + 1, sum + a[idx]);
	re(idx + 1, sum);
}
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	re(0, 0);
	if (s == 0) { ans--; }// 주의: 공집합 예외 ,
	cout << ans << '\n';
	return 0;
}



