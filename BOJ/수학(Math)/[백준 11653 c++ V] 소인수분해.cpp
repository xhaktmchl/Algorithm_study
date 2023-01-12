#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
#include <vector>
using namespace std;
/*
[백준 11653 c++ V] 소인수분해
문제: 
접근1: 
시간복잡도: 
풀이:
    //1.입력
    //3.소인수 분해
*/
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //1.입력
    cin >> n;
    //2.소인수 분해
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            cout << i << '\n';
            n /= i;
        }
    }
    return 0;
}
