#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
/*
[백준 11279 c++ OO] 최대 힙
문제: 맥스 힙자료구조를 이용해 입력괴 출력을 하라
접근: 맥스힙 뼈대문제 -> 우선순위큐 stl 이용
접근2: 노드 구조체를 정의 -> 우선순위 큐 stl 이용
시간복잡도: O(n*logn)
풀이:
// 0 입력 -> 빈큐 아니면 최댓값 출력, 없으면 0출력
// 그 외 숫자 맥스힙에 푸쉬

*/
int n,num;
priority_queue<int> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if(num==0){
            if (pq.empty()) {
                cout << 0 << '\n';
                continue;
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else { pq.push(num); }
    }
    return 0;
}
