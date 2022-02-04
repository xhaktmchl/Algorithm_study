#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch16 SKM 01 O] 정방향 회전 알고리즘
풀이: 
  //1.수열 입력
  //2.출력: x 부터 y칸 뒤의 수= (x+y)%n
시간복잡도: O(1) 
*/
#define MAX 110
int n,x,y;
int a[MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.수열 입력
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  cin>>x>>y;
  //2.출력: x 부터 y칸 뒤의 수= (x+y)%n
  cout<<a[(x+y)%n]<<'\n';
  return 0;
}
