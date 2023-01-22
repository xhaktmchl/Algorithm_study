#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
using namespace std;
/*
[백준 10798 c++ O] 세로읽기
접근1: 
시간복잡도: n*n
풀이: 
    //1.입력
    //2.문자열 탐색
*/
char a[20][20];
string str;
int maxSize = -1;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    
    //1.입력
    for (int i = 0; i < 5; i++) {
        cin >> str;
        int size = str.size();
        if (size > maxSize) maxSize = size;
        for (int j = 0; j < size; j++) {
            a[i][j] = str[j];
        }
    }
    //2.문자열 탐색
    for (int j = 0; j < maxSize; j++) {
        for (int i = 0; i < 5; i++) {
            if (a[i][j] != 0) {
                cout << a[i][j];
            }
        }
    }
    return 0;
}
