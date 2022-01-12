#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch8 03 V] binary
풀이: 재귀: 
시간복잡도: O(MAX)=11 
*/
#define MAX 14
int n;
string binary;
// 재귀
void re(int cur){
  // 기저사례: cur가 0또는 1이면
  if(cur == 1 || cur==0){
    if(cur == 1) binary+=('0'+cur); // 처음 숫자가 1이면 추가
    reverse(binary.begin(),binary.end());
    cout<<binary<<'\n';
    return;
  }
  // 나눈 나머지
  int mod = cur%2;
  binary+= ('0'+mod);
  // 나눈 목 재귀
  re(cur/2);
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>n;
  re(n);
  return 0;
}
