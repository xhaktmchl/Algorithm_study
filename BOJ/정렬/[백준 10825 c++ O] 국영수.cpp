#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 10825 c++ O] 국영수 
// 문제: 이름, 국,영,수 점수를 입력받아 주어진 순서대로 출력 
// 접근: 이름, 국,영,수 점수 를 구조체로 저장후 벡터로 사용자 지정 정렬
// 접근2: 이름, 국,영,수 점수 를 pair<pair<string,int>, pair<int, int>> 저장후 벡터로 사용자 지정 정렬 -> 이 방법 선택
// 시간복잡도: 
// 풀이: 
// 입력, 벡터  사용자 지정 정렬
// 출력
int n;
vector<pair<pair<string,int>, pair<int, int>>> v;

bool mysort(pair<pair<string, int>, pair<int, int>> a, pair<pair<string, int>, pair<int, int>> b) {
	if (a.first.second != b.first.second) { // 국어 점수 다르면
		return a.first.second > b.first.second ? 1 : 0;
	}
	else if (a.second.first != b.second.first) { // 국어 점수가 같으면 영어 점수가 증가
		return a.second.first < b.second.first ? 1 : 0;
	}
	else if (a.second.second != b.second.second) { //국어 점수와 영어 점수가 같으면 수학 점수가 감소
		return a.second.second > b.second.second ? 1 : 0;
	}
	else {//모든 점수가 같으면 이름이 사전 순으로 증가
		return a.first.first < b.first.first ? 1 : 0;
	}
}
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < n; i++) {
		string na; int l, e, m;
		cin >> na >> l >> e >> m;
		v.push_back({ {na,l},{e,m} });
	}

	sort(v.begin(), v.end(), mysort); // 정렬
	for (int i = 0; i < n; i++) {
		cout << v[i].first.first << '\n';
	}
	return 0;
}
