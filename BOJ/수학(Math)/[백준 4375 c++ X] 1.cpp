#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>

using namespace std;
// [백준 4375 c++ X] 1 
// 문제:  1로만 이루어진 n의 배수를 찾는 아라
// 접근: 완전탐색 -> 수의 범위가 넘어감 1111111111111
//접근2: 11 = (1*10+1) , 111 = (11*10+1) 인 것 이용해 규칙 세우기
// 시간복잡도: O() 
// 풀이: 

long long n;

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	while (cin >> n) {
		int num = 0;
		for (int i = 1;; i++) {
			num = (num * 10 % n + 1) % n;
			
			if (num == 0) {
				cout << i << '\n';
				break;
			}
			
		}
		
	}
	return 0;
}
