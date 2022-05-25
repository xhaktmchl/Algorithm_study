#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level22 01번 OO] 경로를 출력하자_강사풀이
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
vector<char> path;
//1.재귀(레벨, 경로 벡터)

void re(int lv) {
	//1)기저조건: 만약 lv2 면 
	//출력:현재까지의 경로
	//중단
	if (lv == 2) {
		for (int i = 0; i < path.size(); i++) {
			cout << path[i];
		}cout << '\n';
		return;
	}
	//2) 재귀 , 
	//A,B,C 
	for (int i = 0; i < 3; i++) {
		char ch = 'A' + i;
		path.push_back(ch);
		re(lv + 1);
		path.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.재귀(레벨, 경로 벡터)
	//1)기저조건: 만약 lv2 면 
	//출력:현재까지의 경로
	//중단
	//2) 재귀 , 
	//A,B,C 
	re(0);
	return 0;
}
