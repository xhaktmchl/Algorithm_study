#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch3 OO] 주사위 게임
풀이: 
시간복잡도: O(n*3)=3000
*/

int n,a,b,c,money=0,maxN=0;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  cin>>n;
  // 1.반복으로 1~n까지 주사위 3개 입력
  for(int i=0;i<n;i++){
    cin>>a>>b>>c;
    // 2.규칙대로 상금 계산
    if(a==b && b==c){
      money = 10000+a*1000;
    }
    else if((a==b && b!=c) || (a==c && b!=c) || (b==c && a!=c)){
      money = 1000+a*100;
    }
    else if(a==c && b!=c){
      money = 1000+a*100;
    }
    else if(b==c && a!=c){
      money = 1000+b*100;
    }
    else if(a!=b && b!=c){
      int maxDice = max(a,max(b,c));
      money = maxDice*100;
    }
    // 3.최댓값 저장
    maxN = max(maxN,money);
  }
   // 4.최댓값 출력
  cout<<maxN<<'\n';
  
  return 0;
}
