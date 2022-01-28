#include <iostream>
#include <algorithm> //sort
using namespace std;
/*
[알고리즘잡스 ch15 01 VO] 숫자 개수 세기
풀이1: 퀵정렬, 이진탐색 stl 이용
시간복잡도: O(qlogn)= 약 10만 이상
풀이2: 이진탐색 직접 구현
*/
#define MAX 100010
int n,q;
int ar[MAX];
int num;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);
  
  //1.숫자 입력
  cin>>n>>q;
  for(int i=0;i<n;i++){
    cin>>ar[i];
  }
  
  //2.정렬
  //3.질문 입력
  //4.숫자의 갯수 구하기: 찾는 숫자의 마지막 위치 - 찾는 숫자의 처음 위치+1
  sort(ar,ar+n);
  for(int i=0;i<q;i++){
    cin>>num;
    cout<<upper_bound(ar,ar+n,num)-lower_bound(ar,ar+n,num)<<'\n';
  }
  return 0;
}
