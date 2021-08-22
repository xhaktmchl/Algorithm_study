#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 2953 c++ O] 나는 요리사다
// 문제:
// 접근: 
// 풀이: 
int maxidx=0,maxN=0;
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	for (int i = 0; i < 5; i++) {
		int a, b, c, d;
		int sum = 0;
		cin >> a >> b >> c >> d;
		sum = a + b + c + d;
		if (sum > maxN) {
			maxidx = i+1;
			maxN = sum;
		}
	}
	cout << maxidx << " "<<maxN << '\n';
	return 0;
}
