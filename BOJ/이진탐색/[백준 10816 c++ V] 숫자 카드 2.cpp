#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 10816 c++ V] 숫자 카드 2 
// 문제: 숫자 있는지 출력
// 접근1: 완전탐색 -> 50만*50만 이어서 시간초과
// 접근2: 벡터 정렬 후 lower_bound ,upper_bound 함수의 차가 그 원소의 갯수
// 시간복잡도: 
// 풀이: 
// 배열 입력
// 정렬, 타겟 숫자의 끝 - 시작 위치 구해 출력
// 개념:
//: lower_bound(a.begin(), a.end(), num); 찾는 값의 시작 주소
//  upper_bound(a.begin(), a.end(), num); 찾는 값의 마지막 주소
int n, m;
vector<int> a;
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		a.push_back(num);
	}

	sort(a.begin(), a.end()); 
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		auto lower = lower_bound(a.begin(), a.end(), num); // 시작
		auto upper = upper_bound(a.begin(), a.end(), num); // 마지막

		cout<<upper - lower<<" "; // 원소의 갯수
	}
	return 0;
}


