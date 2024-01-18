#include <bits/stdc++.h>
using namespace std;
int main() {
    double n1, n2, ans;
    char op;
    cout << "Enter first number: ";
    cin >> n1;
	cout << "Enter second number: ";
    cin >> n2;
    cout << "Choose operation (+, -, *, /): ";
    cin >> op;
    switch (op) {
        case '+':
            ans = n1 + n2;
            break;
        case '-':
            ans = n1 - n2;
            break;
        case '*':
            ans = n1 * n2;
            break;
        case '/':
            if(n2!=0){
                ans = n1/n2;
            }
			else{
                cout << "Error: Division by zero is not allowed." <<"\n";
                return 1;
            }
            break;
        default:
            cout << "Error: Invalid operation." <<"\n";
            return 1; 
    }
    cout << "Result: " << ans << "\n";
    return 0; 
}

