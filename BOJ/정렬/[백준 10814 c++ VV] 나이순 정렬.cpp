#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 10814 c++ VV] 나이순 정렬
// 문제: 나이,이름을 입력받고 1. 나이순, 2.등록순으로 정렬
// 접근: pair로 정보 입력받고 벡터에 저장 후 정의함수로 정렬
// 풀이: 
// 정복 젝터에 pair로 저장
// stable 정렬 // 나이가 같은 경우는 
// 출력
// 개념:
// : stable_sort() : 입력된 순서를 유지하면서 정렬하는것
int n;
vector<pair<int, string>> a;

bool mysort(pair<int, string> b, pair<int, string> c) {
	if (b.first != c.first) {
		return b.first < c.first ? 1 : 0;
	}
	
}
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; string na;
		cin >> num >> na;
		a.push_back({ num,na });
	}

	stable_sort(a.begin(), a.end(), mysort); // stable_sort 순서 보존 정렬
	for (int i = 0; i < n; i++) {
		cout << a[i].first << " " << a[i].second<<'\n';
	}
	return 0;
}
