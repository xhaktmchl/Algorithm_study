#include <iostream>
#include <algorithm>
using namespace std;
/*
[백준 5639 c++ VV] 이진 검색 트리
문제: 이진트리 전위순회가 주어지면 후위순회 출력
접근: 전위입력으로 이진트리 생성 후 -> 후위순회
시간복잡도: O(전위순회 입력+ 후위순회 재귀)
접근2: 이진트리를 생성하지 않고 풀이 -> 참고풀이들 이해가 안됌.
풀이1:
    //1.전위순회 입력
    //2.입력과 동시에 이진 트리에 푸쉬
    //3.출력: 후위 순위
*/
int node, root;
int tree[1000001][2];

void insert(int par, int curNode) {
    
    // 작을 때
    if (curNode < par) {
        if (tree[par][0] == 0) {
            tree[par][0] = curNode;
            return;
        }
        else insert(tree[par][0], curNode);
    }
    // 클때
    if (curNode > par) {
        if (tree[par][1] == 0) {
            tree[par][1] = curNode;
            return;
        }
        else insert(tree[par][1], curNode);
    }
}

void post(int curNode) {
    if (tree[curNode][0] != 0) { post(tree[curNode][0]); } // 왼자식
    if (tree[curNode][1] != 0) { post(tree[curNode][1]); } // 오른자식
    cout << curNode << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //1.전위순회 입력
    while (cin >> node) {
        if (root == 0) root = node;
        else insert(root, node);
    }
    //2.입력과 동시에 이진 트리에 푸쉬
    //3.출력: 후위 순위
    post(root);
    return 0;
}
