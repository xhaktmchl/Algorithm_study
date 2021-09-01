#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 9076 c++ O] 점수 집계 
// 문제: 
// 접근: 
// 시간복잡도: O(t*n) = 10*5 = 50
// 풀이 :
int t;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> t;
	while (t--) {
		vector<int> a;
		for (int i = 0; i < 5; i++) {
			int num; cin >> num;
			a.push_back(num);
		}
		sort(a.begin(), a.end());
		if (a[3] - a[1] >= 4) { cout << "KIN" << '\n'; }
		else cout << a[1] + a[2] + a[3] << '\n';
	}
	return 0;
}
