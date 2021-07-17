#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 17427 c++ V] 약수의 합 2 
// 문제: n을 입력하면 n이하의 수들의 각 수의 약수들의 합의 총합을 구해라
// 접근: 약수 완전탐색 -> 1000000이라 시간초과
// 접근: 나오는 약수들 나열 -> 규칙-> 약수3의 갯수= n/3 , 따라서 총 합=약수*약수의 갯수
// 풀이: 
// 각 약수의 갯수* 약수 = 약수둘의 합 구한다.
int n;

int main()
{	
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축

	cin >> n;
	long long sum=0;
	for (int i = 1; i <= n; i++) {
		sum += i * (n / i); // 약수* 약수의 갯수
	}
	cout << sum;
	return 0;
}
