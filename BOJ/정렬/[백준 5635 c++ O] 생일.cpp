#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 5635 c++ O] 생일  
// 문제:
// 접근: 벡터에 pair 형으로 저장 -> sort 로 나이순 정렬 
// 풀이: 
int n,d,m,y;
string name;
vector<pair<pair<string, int>, pair<int, int>>> a; // 이름,날짜,월,년

bool mysort(pair<pair<string, int>, pair<int, int>> b, pair<pair<string, int>, pair<int, int>> c) {
	if (b.second.second != c.second.second) { // 년 오름차순
		return b.second.second < c.second.second;
	}
	else if (b.second.first != c.second.first) { // 월 오름차순
		return b.second.first < c.second.first;
	}
	else if (b.first.second != c.first.second) { // 일 오름차순
		return b.first.second < c.first.second;
	}
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> d >> m >> y;
		a.push_back({ {name,d }, { m,y } });
	}
	sort(a.begin(), a.end(), mysort);
	cout << a[n - 1].first.first << '\n';
	cout << a[0].first.first << '\n';
	return 0;
}
