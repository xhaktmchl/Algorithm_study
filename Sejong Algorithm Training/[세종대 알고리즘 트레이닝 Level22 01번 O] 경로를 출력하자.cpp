#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level22 01번 O] 경로를 출력하자
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
vector<char> v;
//1.재귀(레벨, 경로 벡터)

void re(int lv, vector<char> path,char cur) {
	// 벡터에 현재문자 추가
	path.push_back(cur);
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
	re(lv + 1, path, 'A');
	re(lv + 1, path, 'B');
	re(lv + 1, path, 'C');
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.재귀(레벨, 경로 벡터)
	// 벡터에 현재문자 추가
	//1)기저조건: 만약 lv2 면 
	//출력:현재까지의 경로
	//중단
	//2) 재귀 , 
	//A,B,C 
	re(1, v,'A');
	re(1, v, 'B');
	re(1, v, 'C');
	return 0;
}
