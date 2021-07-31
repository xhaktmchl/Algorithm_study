#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 17427 c++ VV] 약수의 합 2 
// 문제: n을 입력하면 n이하의 수들의 각 수의 약수들의 합의 총합을 구해라
// 접근: 약수 완전탐색 -> n이 1000000이라 시간초과 (시간복잡도 O(n*n)
// 접근: 약수 n의 제곱근 까지만 탐색 -> O(n*sqrt(n)) ->  10억 역시 시간초과
// 접근: 나오는 약수들 나열 -> 규칙-> 약수3의 갯수= n/3 , 따라서 총 합=약수*약수의 갯수
// 시간복잡도: O(n)
// 풀이: 
// 각 약수의 갯수* 약수 = 약수둘의 합 구한다.
int n;
long long sum = 0;
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += i * (n / i); //합=약수*약수의 갯수
	}
	cout << sum << '\n';
	return 0;
}
