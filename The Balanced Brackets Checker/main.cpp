#include <iostream>
#include <string>
using namespace std;

class BalanceBr{
	private:
		int size;
		char* stack;
		int top;
		string symbol;
		
	public:
		BalanceBr(int s, string sym){
		 size = s;
		 symbol = sym;
		 stack = new char[size];
		 top= -1;
		}
		
		bool isFull(){
			return top == size -1;
		}
		
		bool isEmpty(){
			return top == -1;
		}		
		
		void push(char c){
			if(!isFull()){
				stack[++top]=c;
			}
			else{
				cout<<"stack is overflow: "<<endl;
			}
		}
		
		char pop(){
			if(!isEmpty()){
				return stack[top--];
			}
			else{
				cout<<"Underflow :"<<endl;
				return '!';
			}
			
		}
		
		bool CheckBalance(){
		        for (int i = 0; i < symbol.length(); i++) {
            char ch = symbol[i];

            if (ch == '(' || ch == '{' || ch == '[') {
                push(ch);
            }
            
            else if (ch == ')' || ch == '}' || ch == ']') {

                if (isEmpty()) return false;

                char t = pop();

                if ((ch == ')' && t != '(') ||
                    (ch == ']' && t != '[') ||
                    (ch == '}' && t != '{')) {
                    return false;
                }
            }
        }

        return isEmpty();
    }

    ~BalanceBr() { delete[] stack; }
};


int main() {
	
 BalanceBr b1(50, "{[()]}");
    cout << "Input: {[()]}  -> ";
    if (b1.CheckBalance())
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    BalanceBr b2(50, "{[(])}");
    cout << "Input: {[(])}  -> ";
    if (b2.CheckBalance())
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";


	return 0;
}