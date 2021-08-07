#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 11656 c++ O] 접미사 배열
// 문제: 문자열을 입력받고, 모든 접미사를 사전순으로 출력
// 접근1: 접미사 배열 추출(완전탐색) -> 정렬
// 접근2: 접미사 배열 추출(substr 이용) -> 정렬 -> 개인적으로 이게 더 간편, 시간복
// 시간복잡도: O() ,
// 풀이: 
//개념: s.substr(시작인덱스, 끝 인덱스); : (]해당범위 문자열 추출, 범위벗어나면 npos반환
string s;
vector<string> a;

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		string tp;
		/*for (int j = i; j < s.size(); j++) {
			tp += s[j];
		}*/
		tp = s.substr(i, s.size());
		a.push_back(tp);
	}

	sort(a.begin(), a.end());
	for (int i = 0; i < s.size(); i++) {
		cout << a[i] << '\n';
	}
	return 0;
}


