#include <iostream>
using namespace std;
/*
[알고리즘잡스 ch2 O] 윷놀이
풀이: 
시간복잡도: O()
*/
int a,b,c,d;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  for(int i=0;i<3;i++){
    cin>>a>>b>>c>>d;
    int sum=a+b+c+d;
    if(sum == 3){cout<<"A"<<'\n';}
    if(sum == 2){cout<<"B"<<'\n';}
    if(sum == 1){cout<<"C"<<'\n';}
    if(sum == 0){cout<<"D"<<'\n';}
    if(sum == 4){cout<<"E"<<'\n';}
  }
  return 0;
}
