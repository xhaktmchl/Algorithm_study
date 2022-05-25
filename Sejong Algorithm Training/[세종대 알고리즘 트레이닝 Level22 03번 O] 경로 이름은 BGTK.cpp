#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level22 03번 O] 경로 이름은 BGTK
문제:
접근: 
풀이: 
	//1.입력: 레벨
	//2.재귀(레벨)
	//1)만약 입력한 레벨이면
	//출력: 현재까지의 경로
	//증단
	//2)재귀:BGTK
	//경로배열에 문자추가
	//lv+1재귀
	//경로에 문자 팝
시간복잡도: O(4^4)=
*/
int lv;
vector<char> path;

//2.재귀(레벨)
//1)만약 입력한 레벨이면
//출력: 현재까지의 경로
//증단
//2)재귀:BGTK
//경로배열에 문자추가
//lv+1재귀
//경로에 문자 팝
void re(int l) {
	if (l == lv) {
		for (int i = 0; i < path.size(); i++) {
			cout << path[i];
		}cout << '\n';
		return;
	}

	path.push_back('B');
	re(l + 1);
	path.pop_back();
	path.push_back('G');
	re(l + 1);
	path.pop_back();
	path.push_back('T');
	re(l + 1);
	path.pop_back();
	path.push_back('K');
	re(l + 1);
	path.pop_back();
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력: 레벨
	cin >> lv;
	//2.재귀(레벨)
	//1)만약 입력한 레벨이면
	//출력: 현재까지의 경로
	//증단
	//2)재귀:BGTK
	//경로배열에 문자추가
	//lv+1재귀
	//경로에 문자 팝
	re(0);
	return 0;
}
