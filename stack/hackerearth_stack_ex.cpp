#include <iostream>
using namespace std;
//declaring top variable locally
int top;

void check(char *stack, char *str, int length){
    for(int i=0; i<length; i++){
        if(str[i] == '('){
            top++;
            stack[top] = '('; 
        }
        if(str[i] == ')'){
            if(top == -1){
                top--;
                break;
            }
            else{
                top--;
            }
        }
    }
    if(top == -1){
        cout << "String is Balanced" << endl;
    }
    else{
        cout << "String is Unbalanced" << endl;
    }
}
int main(){
    //balanced string with equal number of '(' and ')'
    char str1[] = { '(', 'a', '+', '(','b','-','c',')',')' };

    // unbalanced string with unequal number of '(' and ')'
    char str2[] = { '(','(','a','+','b',')' };

    //declaring stack 
    char stack[15];
    //top needs to be initialised -1 every time check
    top = -1;
    check(stack, str1, 9);
    //top needs to be initialised -1 every time check
    top = -1;
    check(stack, str2, 6);

    return 0;

}

