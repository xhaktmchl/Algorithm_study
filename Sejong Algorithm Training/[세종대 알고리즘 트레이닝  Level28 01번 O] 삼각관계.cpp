#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[세종대 알고리즘 트레이닝  Level28 01번 O] 삼각관계
문제:
접근:
풀이: 인접행렬
	//1.가장 많은 화살표를 받은 노드 구하기
	//2.출려: 최대 노드의 이름
시간복잡도: O()=
*/
int ad[10][10] = {
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,0,1,0},
	{0,0,0,0,1},
	{0,0,0,0,0}
};
int sum = 0;
int maxS = 0, maxN = -1;
string name[10] = {
	"Diane","Chloe","Bob","Amy","Edger"
};

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.가장 많은 화살표를 받은 노드 구하기
	for (int i = 0; i < 5; i++) {
		sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += ad[j][i];
		}
		if (sum > maxS) {
			maxS = sum;
			maxN = i;
		}
	}
	//2.출려: 최대 노드의 이름
	cout << name[maxN];
	return 0;
}
