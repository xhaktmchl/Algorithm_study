#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch10 01 O] 트리 순회 결과 출력하기
풀이: 이진 트리 탐색 ->인덱스를 부모노드로 하고 일차 배열에 왼자식,오른자식 저장
시간복잡도: O(log2(n))= log2(100) = 6
*/
#define MAX 110
int n,a,b,c;
int L[MAX];
int R[MAX];

// 이진트리 전위순회 재귀
void preorder(int node){
  // 기저사례: 자식노드가 없는 경우-1
  if(node == -1){
    return;
  }
  cout<<node<<" ";
  preorder(L[node]);
  preorder(R[node]);
}

// 이진트리 중위순회 재귀
void inorder(int node){
  // 기저사례: 자식노드가 없는 경우-1
  if(node == -1){
    return;
  }
  inorder(L[node]);
  cout<<node<<" ";
  inorder(R[node]);
}

// 이진트리 중위순회 재귀
void postorder(int node){
  // 기저사례: 자식노드가 없는 경우-1
  if(node == -1){
    return;
  }
  postorder(L[node]);
  postorder(R[node]);
  cout<<node<<" ";
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a>>b>>c;
    L[a]=b;
    R[a]=c;
  }
  // 전위순회
  preorder(0); cout<<'\n';
  // 중위순회
  inorder(0); cout<<'\n';
  // 후위순회
  postorder(0); cout<<'\n';
  return 0;
}
