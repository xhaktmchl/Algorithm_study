#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[알고리즘잡스 ch7 01 O] 대소문자 변환
풀이: 
시간복잡도: 
주의:
*/
string str;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  getline(cin,str);
  
  for(int i=0;i<str.length();i++){
    // 소문자
    if(str[i]>='a' && str[i]<='z'){
      str[i] = 'A'+(str[i]-'a');
    }
    // 대문자
    else if(str[i]>='A' && str[i]<='Z'){
      str[i] = 'a'+(str[i]-'A');
    }
  }
  cout<<str<<'\n';
  return 0;
}
