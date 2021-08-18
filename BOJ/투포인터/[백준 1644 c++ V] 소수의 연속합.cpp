#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>

using namespace std;
// [백준 1644 c++ V] 소수의 연속합
// 문제: 연속된 소수의 국간합 ==n 이되는 경우의 수 구하기
// 접근1: 경우의 수 -> 완전탐색,dp -> 완전탐색 -> 2중 반복으로 i,j 까지 구간합 모두 구하기 => 시간O(n*n)  -> 시간초과예상
// 접근2: 연속된 구간의 합 -> 투포인터 -> 왼 인덱스와, 오른인덱스 따로 운영해서 구간의 합 구하기
// 1.구간의 합이 작으면 ridx 증가시켜거 합 구하기 
// 2.구간의 합이 크면 lidx 증가시켜 구간합 빼기
// 3. 구간의 합이 n이면 경우의 수 증가
// 시간복잡도: O(n+n) = O(n) = 20만
// 풀이: 
// 수열 입력
// 에라토스테네스체로 소수 미리 판별
// 투포인터로 소수인 구간의 합 구하기
// 주의: 이 문제는 a가 m보다 작은 조건이 있지만 없으면 lidx,ridx가 역전되는 예외처리 해야 함
#define MAX 4000002
int n;
bool a[MAX];

// 에라토스테네스체
void eratos() {
	a[1] = 1;
	for(int i = 2;i*i<=4000000; i++) {
		for (int j = i * 2; j <= 4000000; j+=i) {
			a[j] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	eratos(); // 소수 판별

	int lidx = 1, ridx = 1,ans=0; // lidx,ridx 가 곧 수
	long long  sum = 0;
	while (ridx <= n) { 
		if (a[ridx] == 1) { ridx++; continue; } // 소수 아니면 넘어감
		if (a[lidx] == 1) { lidx++; continue; } // 소수 아니면 넘어감
		if (sum + ridx < n) { // 연속된 소수 구간의 합 <n
			sum += ridx;
			ridx++;
		}
		else if (sum + ridx == n) {// 연속된 소수 구간의 합 = n
			ans++;
			sum += ridx;
			ridx++;
		}
		else if (sum + ridx > n) { // 연속된 소수 구간의 합 > n
			if (ridx == lidx) { // 인덱스 역전 예외처리
				sum += ridx;
				ridx++;
				continue;
			} // 역전 아니면 왼인덱스 가 증가
			sum -=  lidx;
			lidx++;
		}
	}
	cout << ans << '\n';
	return 0;
}
