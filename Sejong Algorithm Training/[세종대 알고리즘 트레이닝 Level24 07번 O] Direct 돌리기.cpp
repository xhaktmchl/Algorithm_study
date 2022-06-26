#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level24 07번 O] Direct 돌리기
문제:
접근:
풀이:
	//1.입력: 좌표
	//2.출력: 위, 왼, 아래,오
시간복잡도: O()=
*/
string a[5][5] = {
	{"BHC","BBQ","KFC"},
	{"MC","7AVE","PAPA"},
	{"DHC","OBS","MOMS"}
};
int r, c;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력: 좌표
	cin >> r >> c;
	//2.출력: 위, 왼, 아래,오
	for (int i = 0; i < 4; i++) {
		int rr = r + dy[i];
		int cc = c + dx[i];
		if (rr < 0 || rr >= 3 || cc < 0 || cc >= 3) { continue; }
		
		cout << a[rr][cc];
	}
	return 0;
}
