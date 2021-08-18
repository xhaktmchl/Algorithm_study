#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>

using namespace std;
// [백준 1806 c++ O] 부분합 
// 문제: 연속된 부분합 >s 되는 구간 중 최소구간의 길이 출력
// 접근1: 경우의 수 -> 완전탐색,dp -> 완전탐색 -> 2중 반복으로 i,j 까지 구간합 모두 구하기 => 시간O(n*n)  -> 시간초과예상
// 접근2: 투포인터 -> 왼 인덱스와, 오른인덱스 따로 운영해서 구간의 합 구하기
// 1.구간의 합이 작으면 ridx 증가시켜거 합 구하기 
// 2.구간의 합이 크면 lidx 증가시켜 구간합 빼기
// 3. 구간의 합이 m이면 경우의 수 증가
// 시간복잡도: O(n+n) = O(n) = 20만
// 풀이: 
// 수열 입력
// 투포인터로 구간의 합 구하기
// 주의: 이 문제는 a가 m보다 작은 조건이 있지만 없으면 lidx,ridx가 역전되는 예외처리 해야 함
#define MAX 100001
int n, s,minN = 100005;
int a[MAX];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int lidx = 0, ridx = 0;
	int sum = 0;
	while (ridx < n) {
		if (sum + a[ridx] < s) { // 구간의 합<s
			sum += a[ridx];
			ridx++;
		}
		else if (sum + a[ridx] == s) { // 구간의 합 == s
			sum += a[ridx];
			minN = min(minN, ridx - lidx + 1); // 최소길이 갱신
			ridx++;
		}
		else if (sum + a[ridx] > s) {  // 구간의 합>s
			if (lidx == ridx) { // 왼,오 인덱스 역전되는 상황 예외처리
				sum += a[ridx];
				minN = min(minN, ridx - lidx + 1); // 최소길이 갱신
				ridx++;
				continue;
			}
			sum -= a[lidx];
			minN = min(minN, ridx - lidx + 1); // 최소길이 갱신
			lidx++;
		}
	}
	if (minN == 100005) { cout << 0 << '\n'; }
	else { cout << minN << '\n'; }
	return 0;
}
