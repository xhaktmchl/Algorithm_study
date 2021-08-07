#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 1152 c++ V] 단어의 개수
// 문제: 단어의 갯수 출력
// 접근1: while로 계속 cin 하면 됨
// 시간복잡도: O() ,
// 풀이: 
int c = 0;
string s;
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	while (1) {
		if (cin >> s) {
			c++;
		}
		else break;
	}
	cout << c << '\n';
	return 0;
}


