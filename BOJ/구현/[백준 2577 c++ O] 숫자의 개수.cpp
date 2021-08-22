#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 2577 c++ O] 숫자의 개수 
// 문제:
// 접근: 배열에 문자의 갯수 저장 -> 탐색시간 O(1)
// 풀이: 
// 곱한 결과를 -> 문자열 변환 -> 탐색
// 문자갯수 저장
#define MAX 10
int a, b, c;
int cnt[MAX];
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> a >> b >> c;
	string ret = to_string(a * b * c);
	for (int i = 0; i < ret.size(); i++) {
		cnt[ret[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		cout << cnt[i] << '\n';
	}
	return 0;
}
