#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 11170 c++ O] 0의 개수
// 문제: 
// 접근: 숫자에서 0 갯수 구하기 -> 완탐 -> 문자열로 변환 후 탐색
// 시간복잡도: 최대 O(20*1000000*7) = 1억4천 
// 풀이: 
// n~m 까지 반복
// 문자열로 변환-> 문자열에서 0 탐색
// 0 갯수 출력
int t,n,m;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> t;
	while (t--) {
		cin >> n >> m;
		int cnt = 0;
		for (int i = n; i <= m; i++) { 
			string num = to_string(i); // 각 숫자 문자열로
			for (int j = 0; j < num.size();j++) { // 문자열에서 0탐색
				if (num[j] == '0') { cnt++; }
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
