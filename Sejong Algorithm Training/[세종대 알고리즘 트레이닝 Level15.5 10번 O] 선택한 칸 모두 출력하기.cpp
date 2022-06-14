#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15.5 10번 O] 선택한 칸 모두 출력하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int col;
string a[4] = {
	"FRQWT",
	"GASYQ",
	"ASADB"
};

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> col;
	for (int i = 0; i < 3; i++) {
		cout << a[i][col];
	}
	return 0;
}
