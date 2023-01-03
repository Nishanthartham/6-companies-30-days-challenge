// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

//using external stack
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> operands;

        for (string i:tokens){
            if (i.size()>1 or isdigit(i[0])){
                operands.push(atoi(i.c_str()));
            }
            else{
                int second = operands.top();
                operands.pop();
                int first = operands.top();
                operands.pop();
                    if (i == "+") operands.push(first+second);
                    else if  (i == "-") operands.push(first-second);
                    else if  (i == "*") operands.push(first*second);
                    else operands.push(first/second);
            }
        }
        return operands.top();
    }
};


//using recursion

// class Solution {
// public:
//     int evalRPN(vector<string>& tokens) {
//         string front = tokens.back();
//         tokens.pop_back();
//         if (front.size()>1 or isdigit(front[0])){
//             return atoi(front.c_str());

//         }
        
//             int second = evalRPN(tokens);
//             int first = evalRPN(tokens);
//             if (front == "+")
//             return first+second;
//             else if (front == "-")
//             return first-second;
//             else if (front == "*")
//             return first*second;
//             else
//             return first/second;
        
//     }
// };
