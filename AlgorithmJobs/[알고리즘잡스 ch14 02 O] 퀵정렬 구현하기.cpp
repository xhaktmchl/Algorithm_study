#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch14 02 O] 퀵정렬 구현하기
풀이: 퀵정렬sort stl 이용
// 1.숫자입력
//2.퀵정렬
//3. 정렬된 숫자 출력
시간복잡도: O(n+m)= 100+99
*/
#define MAX 100010
int n;
int ar[MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  // 1.숫자입력
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>ar[i];
  }
  //2.퀵정렬
  sort(ar,ar+n);
  
  //3. 정렬된 숫자 출력
  for(int i=0;i<n;i++){
    cout<<ar[i]<<" ";
  }
  return 0;
}
