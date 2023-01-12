#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
using namespace std;
/*
[백준 1735 c++ OO] 분수 합
문제:
접근: 
시간복잡도: n
풀이:1
    //1.입력
    //2.분수의 합
    //3.기약분수로 만들기
풀이2: 최대공약수(유클리드 호제법) 으로 두 수 나누기
*/
int up1, up2, down1, down2;

// 유클리드 호제법: 최대 공약수 구하기
int gcd(int a, int b) {
    if (b > a) {
        int tp = b;
        b = a;
        a = tp;
    }

    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //1.입력
    cin >> up1 >> down1;
    cin >> up2 >> down2;
    //2.분수의 합
    int up = up1 * down2 + up2 * down1;
    int down = down1 * down2;
    //3.기약분수로 만들기 : 최대공약수로 두 수 나누기
    int gcdNum = gcd(up, down);
    cout << up / gcdNum << " " << down / gcdNum << '\n';
    return 0;
}
