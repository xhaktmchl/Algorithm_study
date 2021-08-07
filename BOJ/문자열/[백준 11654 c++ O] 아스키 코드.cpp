#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 11654 c++ O] 아스키 코드
// 문제:
// 접근: 문자로 입력 -> int로 출력
// 시간복잡도: O(1)
// 풀이: 
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	char ch;
	cin >> ch;
	cout << (int)ch << '\n';
	return 0;
}



