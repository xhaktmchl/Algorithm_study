#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 2609 c++ VO] 최대공약수와 최소공배수
// 문제: 두 수의 최대공약수,최소공배수 출력
// 접근: 최대공약수=유클리드호제법, 최소공배수= (각 수/최대공약수)*최대공약수
// 풀이: 

// 유클리드 호제법
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
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	int a, b;
	cin >> a >> b;

	cout << gcd(a, b)<<'\n';// 최대공약수
	cout << a * b / gcd(a, b) << '\n'; // 최소공배수
	return 0;
}
