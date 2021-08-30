#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 2592 c++ O] 대표값 
// 문제: 
// 접근: 
// 시간복잡도: 
// 풀이: 
// 평균은 직접 구함
// 최빈값은 갯수 벡터에 카운트
#define MAX 1001
int n, sum = 0;
vector<int> cnt(MAX);

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 10; i++) {
		cin >> n;
		sum += n;
		cnt[n] += 1;
	}
	cout << sum / 10 << '\n';
	cout << max_element(cnt.begin(), cnt.end()) - cnt.begin() << '\n';
	return 0;
}
