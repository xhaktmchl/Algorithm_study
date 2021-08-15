#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 3460 c++ O] 이진수    
// 문제: 
// 접근: 
// 시간복잡도: 
// 풀이: 
int t, n;

int main(){
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> t;
	while (t--) {
		vector<int> a;
		cin >> n;
		if (n == 1) { a.push_back(1); } // n=1 일때 처리
		while (n > 1) { // 이진수 구하기
			a.push_back(n % 2);
			if (n / 2 == 1) { a.push_back(1); }
			n /= 2;
		}
		for (int i = 0; i < a.size(); i++) {
			if (a[i]) { cout << i << " "; }
		}cout << '\n';
	}

	return 0;
}



