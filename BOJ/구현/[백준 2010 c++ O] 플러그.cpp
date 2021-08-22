#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring> // memset 헤더
using namespace std;
// [백준 2010 c++ O] 플러그 
// 문제:
// 접근: 
// 풀이: 
int n,sum=1;
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for(int i=0;i<n;i++){
		int num;
		cin >> num;
		sum += num;
	}
	cout << sum - n << '\n';
	return 0;
}
