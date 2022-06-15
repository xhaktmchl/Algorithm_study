#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level13.5 07번 O] 좌표를 지정하면 값 반환하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a[5][5] = {
	"DAS",
	"QWV",
	"RTY"
};

void Find(char* ch1, char* ch2,int y1,int x1,int y2,int x2) {
	*ch1 = a[y1][x1];
	*ch2 = a[y2][x2];
}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	int y1, x1, y2, x2;
	cin >> y1 >> x1 >> y2 >> x2;

	char ch1, ch2;
	Find(&ch1, &ch2,y1,x1,y2,x2);

	cout << ch1 << " " << ch2;
	return 0;
}
