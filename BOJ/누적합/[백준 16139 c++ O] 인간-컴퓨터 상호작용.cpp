#include <iostream>
#include <algorithm>
#include <string>
#include <cstring> // memset
using namespace std;
/*
[백준 16139 c++ O] 인간-컴퓨터 상호작용
문제:
접근1: 완탐 -> 시간 초과
접근2: 누적합-> 구간 까지의 알파벳 갯수 저장
시간복잡도: O(n)
풀이:
    //1.입력
    //2.누적합: 모든 알파벳마다 누적합 저장하기
    //해당 알파벳이면
    //아니면
    //3.q번 구간합: 알파벳 갯수 구하기
    // psum[알파벳 인덱스][r+1]-psum[알파벳 인덱스][l]
    //4.출력
*/
string str;
int q;
int psum[30][200010];
char ch;
int r, l;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    //1.입력
    cin >> str;
    cin >> q;
    //2.누적합: 모든 알파벳마다 누적합 저장하기
    //해당 알파벳이면
    //아니면
    for (char al = 'a'; al <= 'z'; al++) {
        int size = str.length();
        for (int i = 0; i < size; i++) {
            if (str[i] == al) {
                psum[al - 'a'][i + 1] = psum[al - 'a'][i] + 1;
            }
            else {
                psum[al - 'a'][i + 1] = psum[al-'a'][i];
            }
        }
    }
    //3.q번 구간합: 알파벳 갯수 구하기
    // psum[알파벳 인덱스][r+1]-psum[알파벳 인덱스][l]
    //4.출력
    for (int i = 0; i < q; i++) {
        cin >> ch >> l >> r;
        cout << psum[ch - 'a'][r+1] - psum[ch - 'a'][l]<<'\n';
    }
}  
