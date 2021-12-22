#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
/*
[백준 1977 c++ OO] 완전제곱수
문제:
접근: 제곱수는 sqrt 보다 i*i 로 계산하는 습관을 들이자!
시간복잡도:
풀이:
*/
#define MAX 
int m, n, sum = 0,minN=10001;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> m >> n;
	for (int i = 1; i * i <= n; i++) {
		if (i * i >= m) {
			sum += i * i;
			minN = min(minN, i * i);
		}
	}

	
	if (minN == 10001) {	cout << -1 << '\n';}
	else {
		cout << sum << '\n';
		cout << minN << '\n';
	}
	return 0;
}
