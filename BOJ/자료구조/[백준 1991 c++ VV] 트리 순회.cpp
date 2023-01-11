#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
/*
[백준 1991 c++ VV] 트리 순회
문제: 이진트리의 전,중,후위 순회 출력
접근: 트리 -> 연결리스트 벡터로 구현-> 왼,오 자식 없으면 -1,있으면 노드번호 푸쉬
시간복잡도: ??
풀이1:
// 트리를 연결리스트에 노드 번호로 변환 입력 , 왼,오 자식 없으면 -1,있으면 노드번호 푸쉬
// 1.전위순회
// 부모노드 출력, 왼자식 재귀, 오른자식 재귀
// 2.중위
//  왼자식 재귀 부모노드 출력,, 오른자식 재귀
// 3.후위
//  왼자식 재귀 오른자식 재귀 부모노드 출력,
*/
int n;
char node, lch, rch;
vector<char> tree[30];

void pre(char curNode) {
    if (curNode == '.') return;

    cout << curNode;
    int nodeIdx = curNode - 'A';
    pre(tree[nodeIdx][0]);
    pre(tree[nodeIdx][1]);
}

void in(char curNode) {
    if (curNode == '.') return;

    int nodeIdx = curNode - 'A';
    in(tree[nodeIdx][0]);
    cout << curNode;
    in(tree[nodeIdx][1]);
}

void post(char curNode) {
    if (curNode == '.') return;

    int nodeIdx = curNode - 'A';
    post(tree[nodeIdx][0]);
    post(tree[nodeIdx][1]);
    cout << curNode;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //1.입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> node >> lch >> rch;

        int nodeIdx = node - 'A';
       
        tree[nodeIdx].push_back(lch);
        tree[nodeIdx].push_back(rch);
    }
    //2.트리 입력 및 구현
    //3.전위
    pre('A'); cout << '\n';
    //4.중위
    in('A'); cout << '\n';
    //5.후위
    post('A'); cout << '\n';
    return 0;
}
