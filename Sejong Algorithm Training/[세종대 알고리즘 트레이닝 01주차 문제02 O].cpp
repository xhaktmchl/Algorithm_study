#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 01주차 문제02 O] 
문제: 
접근1: 
시간복잡도: 
*/
int n;
int a[10][10] = { { 2,7,1,1,5 },{ 3,2,1,1,1 },{ 1,1,5,5,5} };
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] == n) { cnt++; }
		}
	}
	cout << "n의 갯수=" << cnt << '\n';
	return 0;
}
