#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level13.5 01번 O] 구조체 복습 - 평균구하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
typedef struct Profile {
	char name[10];
	int age;
	int weight;
}P;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	P p1, p2;

	cin >> p1.name >> p1.age >> p1.weight >> p2.name >> p2.age >> p2.weight;

	cout << p1.name << " & " << p2.name << '\n';
	cout << "평균" << (p1.age + p2.age) / 2 << "세" << '\n';
	cout << "평균" << (p1.weight + p2.weight) / 2 << "KG";
	return 0;
}
