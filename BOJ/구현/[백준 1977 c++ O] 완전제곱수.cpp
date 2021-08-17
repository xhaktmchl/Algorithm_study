#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 1977 c++ O] 완전제곱수 
// 문제: 
// 접근: 제곱수는 sqrt 보다 i*i 로 계산하는 습관을 들이자!
// 풀이: 
int n, m;
int sum = 0,minN=10001;
int main(){
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> m >> n;
	for (int i = 1; i * i <= n ; i++) {
		if (i * i >= m) { 
			minN = min(minN, i * i);
			sum += i * i;
		}
	}
	if (minN == 10001) { cout << -1 << '\n'; return 0; }
	cout << sum << '\n' << minN << '\n';
	return 0;
}
