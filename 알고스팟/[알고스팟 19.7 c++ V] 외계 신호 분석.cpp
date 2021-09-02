#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <cmath>
#include <queue>
using namespace std;
// [알고스팟 19.7 c++ V] 외계 신호 분석
// 문제:
// 접근: 연속 구간합 -> 투포인터 배열 탐색 -> 메모리 초과
// 시간복잡도: O(2n)
// 접근2: 연속 부분수열 구간합 -> 큐에 해당하는 연속 부분수열만 저장하며 탐색
// 시간복잡도: O(2n)
// 풀이: 
// 주의: 256^4 을 256*256*256*256 으로하면 산술 오버플로 -> pow함수 이용
#define MAX 10001
long long a[MAX];
int n,t,k;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> t;
	while (t--) {
		cin >> k >> n;
		
		long long prevsig = 1983; 
		long long nowsig = 0;
		long long sumsig = 0;
		queue<long long> q;
		int ans = 0;

		while (n--) {
			nowsig = prevsig % 10000 + 1; q.push(nowsig);
			sumsig += nowsig;

			while (sumsig > k) {
				sumsig -= q.front();
				q.pop();
			}
			if (sumsig == k) {
				ans++;
			}
			prevsig = (prevsig * 214013 + 2531011) % (long long)(pow(2, 32));
		}
		cout << ans << '\n';
	}
	return 0;
}
