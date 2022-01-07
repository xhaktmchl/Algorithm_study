#include <iostream>
using namespace std;
/*
[알고리즘잡스 ch3 O] array 3
풀이:  행의 첫번째와 그 행의 커지는 숫자의 규칙을 찾음
시간복잡도: O(n*n)=10000
*/
int n,rowFirst=0;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
 
  cin>>n;
  for(int i=1;i<=n;i++){
    rowFirst +=i;// 행의 첫 번째 숫자
    int plus = i;
    int cur=rowFirst; // 출력될 현재 숫자
    for(int k=1;k<=n-i+1;k++){
      cout<<cur<<" ";
      cur +=plus;
      plus++;
    }
    cout<<'\n';
  }
  return 0;
}
