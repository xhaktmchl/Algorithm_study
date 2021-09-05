#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// [백준 1991 c++ V] 트리 순회
// 문제: 이진트리의 전,중,후위 순회 출력
// 접근: 트리 -> 연결리스트 벡터로 구현-> 왼,오 자식 없으면 -1,있으면 노드번호 푸쉬
// 시간복잡도: ??
// 풀이1: 
// 트리를 연결리스트에 노드 번호로 변환 입력 , 왼,오 자식 없으면 -1,있으면 노드번호 푸쉬
// 1.전위순회
// 부모노드 출력, 왼자식 재귀, 오른자식 재귀
// 2.중위
//  왼자식 재귀 부모노드 출력,, 오른자식 재귀
// 3.후위
//  왼자식 재귀 오른자식 재귀 부모노드 출력,
#define MAX 30
int n;
vector<int> tree[MAX];

// 전위
void preorder(int node) {
	cout << (char)('A' + node); // 부모 먼저
	if (tree[node][0] != -1) { preorder(tree[node][0]); } // 왼 자식 있으면 탐색
	if (tree[node][1] != -1) { preorder(tree[node][1]); } // 오른자식 있으면 탐색
}
//중위
void inorder(int node) {
	if (tree[node][0] != -1) { inorder(tree[node][0]); }
	cout << (char)('A' + node); // 부모 중간
	if (tree[node][1] != -1) { inorder(tree[node][1]); }
}
//후위
void postorder(int node) {

	if (tree[node][0] != -1) { postorder(tree[node][0]); }
	if (tree[node][1] != -1) { postorder(tree[node][1]); }
	cout << (char)('A' + node); // 부모 마지막
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	// 트리 그래프 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		char node, lch, rch;
		cin >> node >> lch >> rch;
		
		int nodeN = node - 'A'; // 부모노드
		// 왼 자식 
		if(lch != '.') {// 있으면
			int lchN = lch - 'A';
			tree[nodeN].push_back(lchN);
		}
		else { tree[nodeN].push_back(-1); } // 없으면
		// 오른 자식	
		if (rch != '.') {
			int rchN = rch - 'A';
			tree[nodeN].push_back(rchN);
		}
		else { tree[nodeN].push_back(-1); }
		
	}
	// 전위,중위,후위순회 출력
	preorder(0); cout << '\n';
	inorder(0); cout << '\n';
	postorder(0); cout << '\n';
	return 0;
}
