#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> // memset 헤더
#include <queue>
using namespace std;
// [백준 1476 c++ O] 날짜 계산 
// 접근: 
// 시간복잡도: 
// 풀이1: 
// e,s,m 배열 각각 만들어서 원소 반복 탐색 -> 메모리 사용 안하고 풀 수 있는 코드 있음
// 풀이2:
#define MAX 50
int E,S,M;
int e[15], s[28], m[19];
int es = 15, ss = 28, ms = 19;
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> E >> S >> M;
	
	// 완전탐색
	int time = 1;
	while (1) {
		if (e[(time-1) % es] == E && s[(time-1) % ss] == S && m[(time-1) % ms] == M) {
			cout << time << '\n';
			break;
		}
		
		time++;
	}
	
	return 0;
}
