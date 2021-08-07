#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 2805 c++ V] 나무 자르기
// 문제: 
// 접근1: 최댓값 -> 완탐/그리디/dp/이진탐색 -> 완전탐색 -> 20억 이어서 시간초과
// 접근2: 최댓값 -> 완탐/그리디/dp/이진탐색 -> 이진탐색 직접구현-> 자르는 길이 low=1, high=최대길이, 하고 
// 시간복잡도: O(log2())
// 풀이: 
// 배열 입력
// 이진탐색(자른 나무의 합이 m 이상인 경우/ 아닌 경우)
#define MAX 1000001
int n, m;
long long a[MAX];
long long low=0, high=0, mid;
long long maxN = 0;
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin>>a[i];
		high = max(high, a[i]);
	}
	// 이진탐색
	while (low <= high) {
		mid = (low + high) / 2; // 자르는 톱의 높이
		// 가져가는 나무길이 합 구하기
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > mid) { // 자를 수 있는 것만 자른다
				sum += a[i] - mid;
			}
		}
		// 나무 가져가는 경우
		if (sum >= m) {
			maxN = max(maxN, mid);
			low = mid + 1;
		}
		else { // 아닌 경우
			high = mid - 1;
		}
	}

	cout << maxN << '\n';
	return 0;
}



