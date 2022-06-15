#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level13 06번 O] 좋아하는 숫자 찾기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int ar[5][10] = {
	{4,5,6,1,3,1},
	{2,1,3,6,3,6}
};

void input(int* a, int* b, int* c) {
	cin >> *a >> *b >> *c;
}

void Process(int a, int b, int c, int* cnt1, int* cnt2, int* cnt3) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			if (ar[i][j] == a) { (*cnt1) += 1; }
			if (ar[i][j] == b) { (*cnt2) += 1; }
			if (ar[i][j] == c) { (*cnt3) += 1; }
		}
	}
}

void Output(int a,int b,int c,int cnt1, int cnt2, int cnt3) {
	cout << a << "=" << (int)cnt1 << "개" << '\n';
	cout << b << "=" << (int)cnt2 << "개" << '\n';
	cout << c << "=" << (int)cnt3 << "개" << '\n';
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	int a, b, c;
	int cnt1=0, cnt2=0, cnt3=0;
	input(&a,&b,&c);
	Process(a, b, c,&cnt1,&cnt2,&cnt3);
	Output(a,b,c,cnt1, cnt2, cnt3);
	return 0;
}
