#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15.5 07번 O] 구조체 사용하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
typedef struct Product {
	char name[10];
	int size;
	int price;
}P;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	P a, b;
	cin >> a.name >> a.size >> a.price >> b.name >> b.size >> b.price;

	cout << a.name << "," << b.name << '\n';
	cout << "AverageSize=" << (a.size + b.size) / 2 << '\n';
	cout << "AveragePrice=" << (a.price + b.price) / 2 << '\n';
	return 0;
}
