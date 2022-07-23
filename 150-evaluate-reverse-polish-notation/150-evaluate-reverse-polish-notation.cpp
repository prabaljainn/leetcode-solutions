
class Solution {
public:
    int eval(char op, int a, int b){
        switch(op){
            case '+':
                return a+b;
            case '-':
                return a-b;
            case '*':
                return a*b;
            case '/':
                return floor(a/b);
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size(); i++){
            
            if(tokens[i] != "+" and 
              tokens[i] != "-" and
               tokens[i] != "*" and
               tokens[i] != "/" 
              
              ){
                s.push(stoi(tokens[i]));
            }
            else{
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                char op = tokens[i][0];
                s.push(eval(op, a, b));
            }
        }
        return s.top();
        
    }
};