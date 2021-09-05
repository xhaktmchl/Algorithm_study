#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 2693 c++ O] N번째 큰 수
// 문제: 
// 접근: 기본 정렬
// 시간복잡도: O(퀵정렬)
// 풀이1: 배열 입력 ,정렬 ,n번째 큰수
#define MAX 10
int t;
vector<int> a(MAX);

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> t;
	while (t--) {
		for (int i = 0; i < 10; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		cout << a[a.size() - 3] << '\n';
	}
	return 0;
}
