#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 2908 c++ O] 상수 
// 문제:
// 접근: 문자로 입력 -> 순서 뒤집기 -> 크기비교 -> 최대값 출력
// 시간복잡도: O()
// 풀이: 
// 개념:
// :reverse(a.begin(), a.end()); ,무자열이나 벡터 역순으로 뒤집음
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string ans = max(a, b);
	cout << ans << '\n';
	return 0;
}



