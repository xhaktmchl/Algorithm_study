#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level19 06번 O] 기차에서 첫사랑 찾기
문제:
접근: 
풀이:
    //1.입력
    //2.완탐: 구조체 배열에서 이름과 나이 탐색
    //둘 다 맞으면 칸 출력
시간복잡도: O()=
*/
typedef struct Train {
    int win;
    string name;
}T;

Train train[7] = {
    {15, "summer"},
    {33, "cloe"},
    {24, "summer"},
    {28, "niki"},
    {32, "jenny"},
    {20, "summer"},
    {40, "coco"}
};

string tarName;
int tarWin;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
    //1.입력
    cin >> tarName >> tarWin;
    //2.완탐: 구조체 배열에서 이름과 나이 탐색
    //둘 다 맞으면 칸 출력, 중단
    for (int i = 0; i < 7; i++) {
        if (train[i].name == tarName && train[i].win == tarWin) {
            cout << i;
            break;
        }
    }
	return 0;
}
