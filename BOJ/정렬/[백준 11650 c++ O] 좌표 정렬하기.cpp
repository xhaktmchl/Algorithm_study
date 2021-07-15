#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio> // c 문법 헤더파일
#include<vector> // 동적배열 라이브러리
#include<algorithm>
#include <string.h>
#include <queue>
using namespace std; // cin,cout 편하게 사용 라이브러리 
// [백준 11650 c++ O] 좌표 정렬하기
// 문제: x,y좌표를 입력받고 x좌표 오름차순 정렬, x같으면 y오름차순 정렬후 좌표 출력
// 접근: sort에 x,y좌표 비교하는 사용자 정의함수 만들어 정렬
// 풀이: 

int n;
vector<pair<int, int>> v;

bool mysort(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) { // x 좌표 다르면 
		return a.first < b.first;
	}
	else { // x 좌표 같으면
		return a.second < b.second; //y로 비교
	}
}
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // 문제마다 오류 유무 다름
	cin.tie(NULL); cout.tie(NULL);// 입출력 시간 단축
	// 각 좌표 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end(),mysort); // 정렬
	// 출력
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}
	return 0;
}
