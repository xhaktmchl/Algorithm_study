#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
using namespace std;
/*
[백준 1735 c++ O] 분수 합
문제:
접근: 
시간복잡도: n
풀이:
    //1.입력
    //2.분수의 합
    //3.기약분수로 만들기
*/
int up1, up2, down1, down2;

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
    //3.기약분수로 만들기
    for (int i = 30000; i >= 1; i--) {
        if (up % i == 0 && down % i == 0) {
            up /= i;
            down /= i;
        }
    }
    cout << up << " " << down << '\n';
    return 0;
}
