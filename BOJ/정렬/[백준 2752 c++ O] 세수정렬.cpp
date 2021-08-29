#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 2752 c++ O] 세수정렬
// 문제: 
// 접근: 기본 정렬
// 시간복잡도: 
// 풀이: 
vector<int> a;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 3; i++) {
		int n; cin >> n;
		a.push_back(n);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < 3; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
