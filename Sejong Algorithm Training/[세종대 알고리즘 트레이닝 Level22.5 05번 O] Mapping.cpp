#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level22.5 05번 O] Mapping
문제:
접근: 
풀이:
	//1.입력
	//2.출력:문자 행 숫자열 인덱스의 price값
시간복잡도: O()=
*/
int Map[5][10] = {
	{3,5,4,2,2,3},
	{1,3,3,3,4,2},
	{5,4,4,2,3,5}
};

char price[10] = "TPGKC";
char a;
int b;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> a >> b;
	//2.출력:문자 행 숫자열 인덱스의 price값 
	int idx = Map[a - 'A'][b-1];
	cout << price[idx-1];
	return 0;
}
