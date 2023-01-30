#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
#include <vector>
#include <queue> // priority_queue<자료형, 구현체, 비교 연산자>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
#include <cmath>
using namespace std;
/*
[백준 11286 c++ V] 절댓값 힙
문제: 
접근: 
시간복잡도: O(nlogn)
풀이1: 
    //1.입력
    //2.0이면
    //비어있으면 0출력
    //있으면 절댓값 가장 작고, 실제값 가장 작은 값 출력
    //3.0아니 정수면 푸쉬
*/
struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) != abs(b)) {
            return abs(a) > abs(b);
        }
        else {
            return a > b;
        }
    }
};
int n,num;
priority_queue<int, vector<int>, cmp> pq;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n;
    //2.0이면
    //비어있으면 0출력
    //있으면 절댓값 가장 작고, 실제값 가장 작은 값 출력
    //3.0아니 정수면 푸쉬
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num == 0) {
            if (pq.empty()) cout<<0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(num);
    }
    return 0;
}  
