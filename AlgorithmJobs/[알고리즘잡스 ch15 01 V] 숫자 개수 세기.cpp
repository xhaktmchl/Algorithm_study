#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[알고리즘잡스 ch15 01 V] 숫자 개수 세기
풀이1: 퀵정렬, 이진탐색 stl 이용
시간복잡도: O(qlogn)= 약 10만 이상
풀이2: 이진탐색 직접 구현
*/
#define MAX 100010
int n,m;
int ar[MAX];
int num;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  // 숫자 입력
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>ar[i];
  }
  // 2.정렬
  sort(ar,ar+n);
  //3.원하는 값 갯수 구하기 : 찾는값 제일 뒤 - 찾는값 맨 앞
  for(int i=0;i<m;i++){
    cin>>num;
    cout<<upper_bound(ar,ar+n,num)-lower_bound(ar,ar+n,num)<<'\n';
  }
  return 0;
}
