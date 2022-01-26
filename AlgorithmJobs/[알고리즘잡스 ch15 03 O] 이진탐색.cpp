#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch15 03 O] 이진탐색
풀이: 이진탐색binary_search  stl 이용
// 오름차순 숫자 입출력
  // 츨력: 이진탐색으로 숫자 포함 유무
// 이진탐색binary_search(시작주소, 끝주소], 탐색 숫자)
시간복잡도: O(nlogn)= 10만 이상
*/
#define MAX 100010
int ar[MAX];
int n,q,num;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  // 오름차순 숫자 입출력
  cin>>n>>q;
  for(int i=0;i<n;i++){
    cin>>ar[i];
  }
  // 츨력: 이진탐색으로 숫자 포함 유무 
  for(int i=0;i<q;i++){
    cin>>num;
    if(binary_search(ar,ar+n,num)){
      cout<<"YES"<<'\n';
    } // (시작주소, 끝주소], 탐색 숫자)
    else{ cout<<"NO"<<'\n';}
  }
  return 0;
}
