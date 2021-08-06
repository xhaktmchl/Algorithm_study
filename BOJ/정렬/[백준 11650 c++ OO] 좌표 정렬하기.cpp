#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
#include <string>
using namespace std;
// [백준 11650 c++ OO] 좌표 정렬하기
// 문제: x,y좌표를 입력받고 x좌표 오름차순 정렬, x같으면 y오름차순 정렬후 좌표 출력
// 접근: sort에 x,y좌표 비교하는 사용자 정의함수 만들어 정렬
// 시간복잡도: O(n) : 입력n, 정렬 nlogn, 
// 풀이: 
vector<pair<int, int>> a;
int n;

bool mysort(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) { // x 좌표 다르면 
		return a.first < b.first ? 1 : 0;
	}
	else { // x 좌표 같으면
		return a.second < b.second ? 1 : 0;
	}
}
int main()
{
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a.push_back({ x,y });
	}

	sort(a.begin(), a.end(), mysort); // 정렬
	for (int i = 0; i < a.size(); i++) {
		cout << a[i].first<<" " << a[i].second << '\n';
	}
	return 0;
}
