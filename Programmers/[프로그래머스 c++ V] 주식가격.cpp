#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
// [프로그래머스 c++ V] 주식가격
// 문제: 초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 가격이 떨어지지 않은 기간은 몇 초인지를 return 
// 접근: 완전탐색-> 탐색하다 떨어지면 떨어진 곳의 인덱스-그 전의 값들 모두 떨어졌는지 비교 -> 길이가 10만이라 이러면 10만*10만이라 시간초과 날거라고 생각했는데-> 각 인덱스와 현재 탐색하는 인덱스 값의 차가 곧 시간인 것을 이용해 스택에 저장하고 가격이 떨어질 때 마다 처리해주면 시간복잡도 n*2 까지는 안돼는 듯
// 풀이: 
// 완전탐색으로 0부터 주식가격 쩔어지는지 검사하면서 스택에 인덱스 푸쉬
// 가격 떨어지면 떨어지기 전 가격들 전부 현재가격과 비교하며 가격 떨어진 거면 팝
// 탐색이 끄나고 마지막 까지 떨어지지 않아서 스택에 남아있는 주식들 전부 시간 계산하며 팝 
stack<int> st;
vector<int> solution(vector<int> prices) {
   
    int n = prices.size();
    vector<int> answer(n);
    // 탐색하며 떨어지는지 검사하고 해당 시간 스택에 푸쉬
    for(int i=0;i<n;i++){
        while(!st.empty() && prices[st.top()] > prices[i]){ // 전 주식가격들 전부 비교
            answer[st.top()] = i-st.top();
            st.pop();
        }
        st.push(i);
    }
    // 끝까지 떨어지지 않은 주식가격들 걸린시간 저장
     while(!st.empty()){
            answer[st.top()] = (n-1)-st.top(); // 걸린 시간
            st.pop();
        }
    return answer;
}
