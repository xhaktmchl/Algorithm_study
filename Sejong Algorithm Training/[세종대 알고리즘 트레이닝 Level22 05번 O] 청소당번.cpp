#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level22 05번 O] 청소당번
문제:
접근: 
풀이: 완탐재귀
	//1.입력 n
	//2.완탐 재귀: n명중 중복허용 4일 뽑기
	//1)기저조건: 4일차면 현재까지 수열 출력
	//중단
	//2)재귀
	//반복문으로 1~n까지
	//경로에 수 추가
	//재귀
	//경로에 수 팝
시간복잡도: O()=
*/
int n;
vector<int> path;

void re(int cnt) {
	if (cnt == 4) {
		for (int i = 0; i < path.size(); i++) {
			cout << path[i];
		}cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		path.push_back(i);
		re(cnt + 1);
		path.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	//1.입력 n
	cin >> n;
	//2.완탐 재귀: n명중 중복허용 4일 뽑기
	//1)기저조건: 4일차면 현재까지 수열 출력
	//중단
	//2)재귀
	//반복문으로 1~n까지 
	//경로에 수 추가
	//재귀
	//경로에 수 팝
	re(0);
	return 0;
}
