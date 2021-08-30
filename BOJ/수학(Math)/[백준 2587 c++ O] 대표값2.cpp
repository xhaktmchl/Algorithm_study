#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring> // memset 헤더
using namespace std;
// [백준 2587 c++ O] 대표값2
// 문제: 
// 접근1: 
// 시간복잡도: 
// 풀이: 
vector<int> a;
int sum = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 5; i++) {
		int num; cin >> num;
		a.push_back(num);
		sum += num;
	}
	sort(a.begin(), a.end());

	cout << sum / 5 << '\n';
	cout << a[2] << '\n';
	return 0;
}
