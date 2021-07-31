#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 2609 c++ VOO] 최대공약수와 최소공배수
// 문제: 두 수의 최대공약수,최소공배수 출력
// 접근: 최대공약수=유클리드호제법, 최소공배수= (각 수/최대공약수)*최대공약수
// 풀이: 
int n1, n2;

// 최대공약수 유클리드 호제법
int gcd(int a, int b) {
	while (b > 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n1 >> n2;
	int g = gcd(n1, n2);
	int l = (n1 / g) * (n2 / g) * g;

	cout << g << '\n';
	cout << l << '\n';
	return 0;
}
