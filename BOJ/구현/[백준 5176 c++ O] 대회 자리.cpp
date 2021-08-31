#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring> // memset 헤더
using namespace std;
// [백준 5176 c++ O] 대회 자리
// 문제: 
// 접근1: 
// 시간복잡도: 
// 풀이: 
#define MAX 501
int t, n, m;
bool cnt[MAX];
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(cnt, 0, sizeof(cnt));
		int c = 0;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			if (cnt[num] == 0) {
				cnt[num] = 1;
				c++;
			}
		}
		cout << n - c << '\n';
		
	}
	return 0;
}
