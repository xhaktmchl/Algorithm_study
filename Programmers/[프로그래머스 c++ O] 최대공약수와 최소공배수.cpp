#include <string>
#include <vector>

using namespace std;
// [프로그래머스 c++ O] 최대공약수와 최소공배수
// 문제: 두 수의 최대공약수와 최소공배수 구하기
// 접근: 최대공약수: 완전탐색으로 찾고 ,  최소공배수 = 최대공약수*최대공약수로 나눈 각 두수의 곱
// 풀이: 
// 최대공약수: 완전탐색으로 찾고
// 최소공배수 = 최대공약수*최대공약수로 나눈 각 두수의 곱 구하기
vector<int> solution(int n, int m) {
    vector<int> answer;
    int gcd=0;
    // 최대공약수 
    int minNum = min(n,m);
    for(int i=minNum;i>=1;i--){ // 두 수중 작은 수에서 작아지면서 탐색
        if(n%i == 0 && m%i == 0){ 
            gcd=i;
            answer.push_back(gcd);
            break;
        }
    }
    //최소 공배수
    int lcm = gcd*(n/gcd)*(m/gcd); // 최소공배수 = 최대공약수*최대공약수로 나눈 각 두수의 곱
    answer.push_back(lcm); 
    
    return answer;
}
