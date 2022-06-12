#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level09.5 07번 V] 구조체 만들고 여러 값 채우기 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
/*
배열에 다음과 같이 숫자를 넣는 것은불가능합니다.
int vect[5];
vect[5] = { 1, 2, 3, 4};// Runtime Error

한꺼번에 숫자를 넣는 것은 배열 만들때만가능합니다.
int vect[5] = { 1, 2, 3, 4 };// 가능
*/
typedef struct PORJECT {
	int num;
	char id;
	int vect[4];
}P;
int n;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	P z;
	cin >> n;
	
	if (n < 10) {
		z.num = 5;
		z.id = 'G';
		int tp[4] = { 1,2,3,4 };
		for (int i = 0; i < 4; i++) {
			z.vect[i] = tp[i];
		}
	}
	else if (n < 100) {
		z.num = 8;
		z.id = 'T';
		int tp[4] = { 5, 1, 2, 3 };
		for (int i = 0; i < 4; i++) {
			z.vect[i] = tp[i];
		}
	}
	else  {
		z.num = 10;
		z.id = 'Q';
		int tp[4] = { 9, 1, 6, 2 };
		for (int i = 0; i < 4; i++) {
			z.vect[i] = tp[i];
		}
	}

	cout << z.num << '\n' << z.id << '\n';
	for (int i = 0; i < 4; i++) {
		cout << z.vect[i] << " ";
	}
	return 0;
}
