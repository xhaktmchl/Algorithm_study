#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 5635 c++ OO] 생일  
// 문제:
// 접근: 벡터에 pair 형으로 저장 -> sort 로 나이순 정렬 
// 풀이: 
// 개념: 
// sort() 함수는 벡터 pair의 앞 원소부터 정렬 비교한다.
int n,d,m,y;
string name;
vector<pair<pair<int, int>, pair<int, string>>> a; // 년,월,일,이름 // 정렬이 앞 원소부터 적용되서 이렇게 순서잡음

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> d >> m >> y;
		a.push_back({ {y,m}, { d,name } });
	}
	sort(a.begin(), a.end());
	cout << a[n - 1].second.second << '\n';
	cout << a[0].second.second << '\n';
	return 0;
}
