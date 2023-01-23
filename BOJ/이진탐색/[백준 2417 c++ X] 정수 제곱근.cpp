#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
#include <cmath>
using namespace std;
/*
[백준 2417 c++ X] 정수 제곱근
접근1: 에라토스테네스의 채 처럼 제곱을 비교하며 탐색 -> 제일 큰 수 일때 에러
접근2: 이진탐색
시간복잡도: 
풀이: 
*/
long long n, res = sqrt(pow(2,63)-1);

void binarySearch() {

    long long s = 0, e = sqrt(pow(2, 63) - 1)+1;
    long long ceil = sqrt(pow(2, 63) - 1) + 1;
    long long mid;

    while (s <= e) {
        mid = (s + e) / 2;
        // 예외처리
        if (mid >= ceil) {
            res = mid;
            break;
        }
        
        long long num = mid * mid;
        if (num == n) {
            res = mid;
            break;
        }
        else if (num > n) {
            e = mid - 1;
            res = min(res, mid);
        }
        else if (num < n) {
            s = mid + 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    cin >> n;
    binarySearch();
    cout << res << '\n';
    return 0;
}
