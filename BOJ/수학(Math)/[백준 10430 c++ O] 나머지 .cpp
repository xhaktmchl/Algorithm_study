#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 10430 c++ O] 나머지 
// 문제: 주어진 식을 계산
// 접근: 
// 풀이: 
int a, b, c;
int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축

	cin >> a >> b >> c;
	cout << (a + b) % c << '\n';
	cout << ((a % c) + (b % c)) % c << '\n';
	cout << (a*b) % c  << '\n';
	cout << ((a % c) *(b % c)) % c << '\n';

	return 0;
}
