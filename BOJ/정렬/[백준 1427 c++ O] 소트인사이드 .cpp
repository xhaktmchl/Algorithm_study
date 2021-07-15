#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c 문법 헤더파일
#include<vector> // 동적배열 라이브러리
#include<algorithm>
#include <string.h>
#include <queue>
using namespace std; // cin,cout 편하게 사용 라이브러리 
// [백준 1427 c++ O] 소트인사이드 
// 문제: 숫자를 입력받아 각 자리의 수 를 내림차순으로 출력
// 접근: 숫자를 string으로 입력받고 각 자리의 수를 벡터에 저장하고 정렬
// 풀이: 
// 숫자를 string으로 입력 
// 각 자리의 수를 벡터에 저장
// 내림차순 정렬 , 출력

int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	
	string n;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n.size(); i++) {
		v.push_back(n[i]-'0');
	}
	sort(v.begin(), v.end(),greater<int>());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	return 0;
}
