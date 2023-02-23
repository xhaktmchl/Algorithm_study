#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용), 
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
#include <cmath>
using namespace std; // lower_bound, upper_bound
/*
[백준 14891 c++ O] 톱니바퀴
문제:
접근: 시뮬
시간복잡도: O()
풀이:     
    //1.입력
    //2.시뮬 회전:
    //1) 회전한 톱니의 왼쪽
    //범위검사
    //극이 다른 경우만 회전
    //2)회전한 톱니의 오른쪽
    //3.점수 계산
*/
int a[6][10];
int b[6][10];
int n,top,dir;
int sum = 0;
string stra;

void rotate(int top, int dir) {

    if (dir == 1) {
        int end = b[top][7];
        for (int i = 7; i > 0; i--) b[top][i] = b[top][i - 1];
        b[top][0] = end;
    }
    else if (dir == -1) {
        int start = b[top][0];
        for (int i = 0; i < 7; i++) b[top][i] = b[top][i + 1];
        b[top][7] = start;
    }
}

void updateTop() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 8; j++) {
            a[i][j] = b[i][j];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    for (int i = 1; i <= 4; i++) {
        cin >> stra;
        for (int j = 0; j < 8; j++) {
            a[i][j] = stra[j]-'0';
            b[i][j] = stra[j]-'0';
        }
    }

    //2.시뮬 회전: 
    //1) 회전한 톱니의 왼쪽
    //범위검사
    //극이 다른 경우만 회전
    //2)회전한 톱니의 오른쪽
    //3) 해당 톱니 회전
    //4) 톱니바퀴 갱신
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> top >> dir;
        
        //1) 회전한 톱니의 왼쪽
        int tpdir = dir*-1;
        for (int j = top-1; j > 0; j--) {
            if (a[j + 1][6] == a[j][2]) break;
            else {
                rotate(j, tpdir);
            }
            tpdir *= -1;
        }
        //2)회전한 톱니의 오른쪽
        tpdir = dir * -1;
        for (int j = top + 1; j <= 4; j++) {
            if (a[j][6] == a[j - 1][2]) break;
            else {
                rotate(j, tpdir);
            }
            tpdir *= -1;
        }
        //3) 해당 톱니 회전
        rotate(top, dir);

        updateTop();//4) 톱니바퀴 갱신
    }
    
    //3.점수 계산
    for (int i = 1; i <= 4; i++) {
        if (a[i][0] == 1) sum += pow(2,i-1);
    }
    cout << sum << '\n';
    return 0;
}
