#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 10974 c++ VO] 모든 순열 
// 접근1:  n중 반복문으로 완전탐색 -> 비효율적
// 접근 2:dfs로 완전탐색 -> 비효율적
// 접근3: next_permutation 함수 이용
// 시간복잡도: O(n*n!) : 다음 순열 탖는데 n, 모든 순열 경우n!
// 풀이: next_permutation
// 개념: next_permutation(v.begin(), v.end()) 오름차순 정렬된 것 다음 수열 탐색
int n;
vector<int> a;

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 1; i <= n; i++) {
		a.push_back(i);
	}
	// 다음순열 탐색
	do {
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}cout << '\n';
	} while (next_permutation(a.begin(), a.end()));
	return 0;
}
