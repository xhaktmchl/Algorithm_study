#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// [백준 2754 c++ O] 학점계산
// 문제:
// 접근: 
// 시간복잡도: 
// 풀이: 
// 개념: cout 소수점 고정반올림  cout<<fixed; cout.precision(i자리까지 반올림)
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	string s;
	cin >> s;
	cout << fixed;
	cout.precision(1);
	if (s == "A+") { cout << 4.3 << '\n'; }
	if (s == "A0") { cout << 4.0 << '\n'; }
	if (s == "A-") { cout << 3.7 << '\n'; }
	if (s == "B+") { cout << 3.3 << '\n'; }
	if (s == "B0") { cout << 3.0 << '\n'; }
	if (s == "B-") { cout << 2.7 << '\n'; }
	if (s == "C+") { cout << 2.3 << '\n'; }
	if (s == "C0") { cout << 2.0 << '\n'; }
	if (s == "C-") { cout << 1.7 << '\n'; }
	if (s == "D+") { cout << 1.3 << '\n'; }
	if (s == "D0") { cout << 1.0 << '\n'; }
	if (s == "D-") { cout << 0.7 << '\n'; }
	if (s == "F") { cout << 0.0 << '\n'; }
	return 0;
}
