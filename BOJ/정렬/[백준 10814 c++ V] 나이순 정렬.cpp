#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c 문법 헤더파일
#include<vector> // 동적배열 라이브러리
#include<algorithm>
#include <string.h>
#include<string>
using namespace std; // cin,cout 편하게 사용 라이브러리 
// [백준 10814 c++ V] 나이순 정렬
// 문제: 나이,이름을 입력받고 1. 나이순, 2.등록순으로 정렬
// 접근: pair로 정보 입력받고 벡터에 저장 후 정의함수로 정렬
// 풀이: 
// 정복 젝터에 pair로 저장
// stable 정렬 // 나이가 같은 경우는 
// 출력
// 개념:
// : stable_sort() : 입력된 순서를 유지하면서 정렬하는것

int n;
vector<pair<int, string>> v;

bool mysort(pair<int, string> a, pair<int, string> b) {
	// stable 정렬이기 때문에 나이만 비교한면 됨
	return a.first < b.first; // 나이 비교
}

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	// 나이,이름 입력, 벡터저장
	cin >> n;
	for (int i = 0; i < n; i++) {
		int age; string name;
		cin >> age >> name;
		v.push_back({ age,name }); // 벡터에 페어로 저장
	}
	// 정렬 후 출력
	stable_sort(v.begin(), v.end(),mysort); // stable sort
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}
	return 0;
}
