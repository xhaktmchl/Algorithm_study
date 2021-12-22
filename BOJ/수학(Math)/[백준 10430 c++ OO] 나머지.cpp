#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
[백준 10430 c++ OO] 나머지
문제:주어진 식을 계산
접근: 
시간복잡도:
풀이:
*/
int a, b, c;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> a >> b >> c;
	cout << (a + b) % c << '\n';
	cout << ((a%c)+(b%c))%c << '\n';
	cout << (a*b)%c << '\n';
	cout << ((a%c)*(b%c))%c << '\n';
	return 0;
}
