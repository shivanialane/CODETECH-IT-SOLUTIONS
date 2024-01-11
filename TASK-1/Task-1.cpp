#include <bits/stdc++.h>
using namespace std;
int main(){
	//Seed the random number generator with the current time for randomness.
    srand(static_cast<unsigned int>(time(0)));
    
    // generate a random number in range 1 to 100
    int Hidden_Number = rand() % 100 + 1;
    
    int guess_number,tries=0;
    cout << "Welcome to the Number Guessing Game!" << "\n";
    do {
        cout << "Enter your guess_number (between 1 and 100): ";
        cin >> guess_number;
        tries++;
        if (guess_number > Hidden_Number) {
            cout << "Too high, Try again." << "\n";
        } else if (guess_number < Hidden_Number) {
            cout << "Too low, Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number in " << tries << " tries." << "\n";
        }

    } while (guess_number != Hidden_Number);

    return 0;
}
 
