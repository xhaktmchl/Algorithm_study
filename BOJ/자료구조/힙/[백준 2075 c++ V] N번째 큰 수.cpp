#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
#include <vector>
#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
//#include <cmath>
using namespace std;
/*
[백준 2075 c++ V] N번째 큰 수
문제: 
접근: 
시간복잡도: O(nlogn)
풀이1: 힙의 루트가 n번째 큰 수가 되도록
    //1.입력
    //모두 우선순위 큐에 삽입
    //2.출력
*/
// 연산자 커스터마이징
struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

priority_queue<int, vector<int>, cmp> pq;
int n,num;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    //모두 우선순위 큐에 삽입
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num;
            pq.push(num);
        }
        
        while (pq.size() > n) pq.pop(); // 메모리 초과때문에 계속 n개만 유지
    }
    //2.출력
    cout << pq.top() << '\n';
    return 0;
}  
