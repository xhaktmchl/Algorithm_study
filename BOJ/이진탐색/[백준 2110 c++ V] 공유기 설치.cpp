#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 2110 c++ V] 공유기 설치
// 문제: 
// 접근1: 최댓값 -> 완탐/그리디/dp/이진탐색 -> 완전탐색 -> 10억*20만 이어서 시간초과
// 접근2: 최댓값 -> 완탐/그리디/dp/이진탐색 -> 이진탐색 직접구현-> 집과 집 사이의 거리를 탐색, low=1, high=최대길이,
// 시간복잡도: O(n*log2(10억))
// 풀이: 
// 배열 입력 , 정렬
// 이진탐색(집사이의 거리를 탐색), 
// 주어진 집들 사이의 거리가 주어진 조건을 만족하는 집이 c+1개 이상이면 가능
// 아니면 안됌
//최대거리 출력
#define MAX 200001
int n, c;
vector <long long > a;
long long maxN = 0;

// 집 사이의 거리가 dist를 만족하는 집의 갯수가 c개 이상인가?
bool ok(long long dist) {
	long long prev = a[0];
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] - prev >= dist) { // 전의 집과의 거리
			cnt++;
			prev = a[i];
		}
	}
	if (cnt+1 >= c) { return true; } // 공유기 c개 이상 설치가능
	else { return false; }
}

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		a.push_back(num);
	}
	sort(a.begin(), a.end()); 
	
	// 이진탐색 , 
	long long low = 1, high = a[n - 1] - a[0];// 집 사이의 최소,최대거리
	while (low <= high) {
		long long mid = (low + high) / 2;

		if (ok(mid)) { //집의 거리가 조건만족하면 
			maxN = max(maxN, mid);
			low = mid + 1;
		}
		else { high = mid - 1; } // 조건 만족 x
	}

	cout << maxN << '\n';
	return 0;
}



