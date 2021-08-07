#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 1654 c++ V] 랜선 자르기
// 문제: 숫자 있는지 출력
// 접근1: 완전탐색 -> 50만*2^31이어서 시간초과
// 접근2: 이진탐색 직접구현-> 랜선의 길이 low=1, high=최대길이, 하고 
// 시간복잡도: O(k*log2(랜선의 길이))
// 풀이: 
// 배열 입력
// 이진탐색(자를수 있는 경우/ 자를 수 없느 경우)
#define MAX 10001
int k, n;
long long a[MAX];
long long low = 1, high=0;
// n개의 랜선 만들 수 있는지 검사
bool possible(int mid) {
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += a[i] / mid;
	}
	if (cnt >= n) { return 1; }
	else return 0;
}
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		high = max(high, a[i]);
	}
	// 이진탐색: 자를 수 있는 랜선의 길이 탐색 1~랜선 최대길이 
	long long mid = (low + high) / 2; // 검사하려는 랜선 길이
	long long ans = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		
		if (possible(mid)) { // 자를수 있으면
			ans = max(ans, mid);
			low = mid + 1;
		}
		else { // 자를 수 없으면
			high = mid - 1;
		}
	}

	cout << ans << '\n';
	return 0;
}



