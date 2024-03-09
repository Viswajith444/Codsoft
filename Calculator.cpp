#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
// #include <conio.h>


template<typename T>
class Calculator{
    private:
        std::string post_fix_expression;

    public:

        Calculator(std::string input) : post_fix_expression(input){}

        T add( T a, T b){
            return a + b;
        }

        T sub( T a, T b){
            return a - b;
        }

        T div( T a, T b){
            return a / b;
        }

        T mod( T a, T b){
            return a % b;
        }

        T mul( T a, T b){
            return a * b;
        }

};

bool fn(char ch){ // please delete me and do hash table
    switch (ch)
        {
            case '+':
                return 1;
                
            case '-':
                return 1;
                
            case '*':
                return 1;
                
            case '/':
                return 1;
                
            default:
                return 0;
        }
}
int main(){

    double a,b;
    char ch;
    while(true){

        printf("\x1b[2J");
        printf("\x1b[H");
        std::string input;
        // printf("\x1b[uANSISYSRC");
        // scanf("%lf %c %lf", &a, &ch, &b);
        // getchar();
        std::cin >>  input;
        
        std::stack<char> operand, op;
        std::string post_fix_expression = ""; 
        
        for(char& ch: input){
            if(isdigit(ch)){
                operand.push(ch);
            }
            else if(fn(ch)){
                post_fix_expression += operand.top();
                operand.pop();
                post_fix_expression += operand.top();
                operand.pop();
                post_fix_expression += ch;
            }
        }
        double ans;
        switch (ch)
        {
            case '+':
                ans = a + b;
                break;
            
            case '-':
                ans = a - b;
                break;

            case '*':
                ans = a * b;
                break;

            case '/':
                ans = a / b;
                break;

            default:
                std::cout  << "Error" << std::endl;
                continue;
        }

        std::cout << "Result: " << ans << "\nPress any key to continue" << std::endl;
        
        std::cin.get();
    }
}