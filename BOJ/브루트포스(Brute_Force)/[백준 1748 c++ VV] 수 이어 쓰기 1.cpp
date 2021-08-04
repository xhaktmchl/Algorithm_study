#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 1748 c++ VV] 수 이어 쓰기 1
// 문제: 이어진 수의 총 자릿수 구하기
// 접근:  문자열로 직접 수 만들어서 자릿수 구하기 -> 시간초과 
// 접근2: 수학 규칙성 찾기
// 풀이: 
// 각 자릿수 일때 길이합 구하기
// 총 자릿수 합 = 같은자리 (끝수 - 첫수+1)*자릿수
// 예) (99-10+1)*2 = 180
#define MAX 40000
string n;

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;

	long long sum = 0;
	
	long long num = 9,d=10; 
	if (stoi(n) <= 9) {
		cout << stoi(n) << '\n';
		return 0;
	}
	for (int i = 1; i <= n.size()-1; i++) {
		sum += (num* i);
		num *= d;
	}
	
	if (stoi(n) > 9) { num /= 9; }
	sum+= (stoi(n) - num + 1)* n.size();
	cout << sum << '\n';
	
	return 0;
}
