#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring> // memset 헤더
using namespace std;
// [백준 5543 c++ O] 상근날드 
// 문제: 
// 접근1: 
// 시간복잡도: 
// 풀이: 
#define MAX 3
int bg[MAX];
int drink[2];
int minN = 4000;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 3; i++) {
		cin >> bg[i];
	}
	for (int i = 0; i < 2; i++) {
		cin >> drink[i];
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			minN = min(minN, bg[i] + drink[j]);
		}
	}
	cout << minN-50 << '\n';
	return 0;
}
