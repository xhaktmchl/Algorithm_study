#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c 문법 헤더파일
#include<vector> // 동적배열 라이브러리
#include<algorithm>
#include <string.h>
#include<string>
using namespace std; // cin,cout 편하게 사용 라이브러리 
// [백준 1181 c++ O] 단어 정렬 
// 문제: 단어들을 입력받고 1.길이순2.사전순으로 정렬후 출력
// 접근: string으로 받아서 사용자 함수로 정렬후 중복제거
// 풀이: 
// 단어 벡터에 입력
// 정렬 후 중복제거
// 개념:
// v.erase(unique(v.begin(), v.end()), v.end()); // 벡터 중복값 제거

int n;
vector<string> v;

bool mysort(string a, string b) {
	if (a.size() != b.size()) { return a.size() < b.size(); }
	else { return a < b; }
}

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	// 단어입력 받고 벡터에 저장
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	// 규칙대로 정렬
	sort(v.begin(), v.end(), mysort);
	v.erase(unique(v.begin(), v.end()), v.end()); // 중복값 제거
	for (int i = 0; i < v.size(); i++) { // 출력
		cout << v[i] << '\n';
	}
	return 0;
}
