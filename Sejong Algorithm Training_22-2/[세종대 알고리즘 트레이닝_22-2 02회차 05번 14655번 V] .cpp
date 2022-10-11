#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝_22-2 02회차 05번 14655번 V] 
문제:
접근: 
풀이: 
	//1.입력
	//2.1라운드 최대
	//3.2라운드 최소
	//4.출력 : 1라 - 2라
시간복잡도: O(n)= 10000
개념:
*/
int n;
int a[10010];
int b[10010];
int sum1 = 0, sum2 = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	//2.1라운드 최대 : 모두 양수
	for (int i = 0; i < n; i++) {
		sum1 += abs(a[i]);
	}
	//3.2라운드 최소
	for (int i = 0; i < n; i++) {
		sum2 += abs(b[i]);
	}
	//4.출력 : 1라 - 2라
	cout << sum1 + sum2 << '\n';
	return 0;
}
