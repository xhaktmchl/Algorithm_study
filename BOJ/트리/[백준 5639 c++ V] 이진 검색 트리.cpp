#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// [백준 5639 c++ V] 이진 검색 트리
// 문제: 이진트리 전위순회가 주어지면 후위순회 출력
// 접근: 전위입력으로 이진트리 생성 후 -> 후위순회
// 시간복잡도: O(전위순회 입력+ 후위순회 재귀)
// 접근2: 이진트리를 생성하지 않고 풀이 -> 참고풀이들 이해가 안됌.
// 풀이1:
// 이진트리 2차원 배열로 구현
// 전위순회입력으로 이진트리 생성 , 처음 루트만 따로 저장
// 이진트리 후위순회 재귀 출력
#define MAX 1000001
int tree[MAX][2]; // 이진트리

// 전위순회 입력
void insert(int root,int node) {
	if (node < root) {
		if (tree[root][0] == 0) {
			tree[root][0] = node;
			return;
		}
		else { insert(tree[root][0], node);}
	}
	else if (node > root) {
		if (tree[root][1] == 0) {
			tree[root][1] = node;
			return;
		}
		else {	insert(tree[root][1], node);}
	}
}

void postorder(int node) {
	if (tree[node][0] != 0) { postorder(tree[node][0]); } // 왼자식
	if (tree[node][1] != 0) { postorder(tree[node][1]); } // 오른자식
	cout << node << '\n'; 
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	int node, root = 0;
	while (cin >> node) {
		if (root == 0) { root = node; } // 루트노드
		else insert(root, node);
	}

	postorder(root); // 후위순회
	return 0;
}
