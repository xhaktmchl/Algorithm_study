#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 2576 c++ O] 홀수   
// 문제: 
// 접근: 
// 시간복잡도: 
// 풀이: 
vector<int> a;
int sum = 0;

int main(){
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	for (int i = 0; i < 7; i++) {
		int num;
		cin >> num;
		if (num % 2 == 1) {
			a.push_back(num);
			sum += num; 
		}
	}
	// 홀수 존재
	if (!a.empty()) {
		cout << sum << '\n';
		cout << *min_element(a.begin(), a.end()) << '\n';
	} // 홀수 없음
	else cout << -1 << '\n';
	return 0;
}



