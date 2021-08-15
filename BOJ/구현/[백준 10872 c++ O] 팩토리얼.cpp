#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 10872 c++ O] 팩토리얼  
// 문제: 
// 접근: 기본 구현
// 시간복잡도: 
// 풀이: 
int ans = 1,n;

int main(){
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	if (n == 0) { cout << 1 << '\n'; return 0; }
	for (int i = n; i >= 1; i--) {
		ans *= i;
	}
	cout << ans << '\n';
	return 0;
}



