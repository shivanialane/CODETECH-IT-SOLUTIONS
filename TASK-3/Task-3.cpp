#include <bits/stdc++.h>
using namespace std;
//1) To display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char> >& b) {
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<b[i][j];
            if(j<2){
            	cout << " | ";
			}
        }
        cout<<"\n";
        if(i<2){
        	cout << "---------" <<"\n";
		} 
    }
}
//To check if the current player has won

bool checkWin(const vector<vector<char> >& b, char p) {
	//check rows and columns
    for(int i=0;i<3;i++){
        if ((b[i][0] == p && b[i][1] == p && b[i][2] == p) ||
            (b[0][i] == p && b[1][i] == p && b[2][i] == p)) {
            return true;
        }
    }
   //Check diagonals
    if ((b[0][0] == p && b[1][1] == p && b[2][2] == p) ||
        (b[0][2] == p && b[1][1] == p && b[2][0] == p)) {
        return true;
    }
    return false;
}
// To check if the game is a draw
bool checkDraw(const vector<vector<char> >& b) {
    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
        	// If there is an empty space, the game is not a draw
            if(b[i][j] == ' ') {
                return false; 
            }
        }
    }
    // If no empty space is found, it's a draw
    return true; 
}

int main() {
    vector<vector<char> > b(3, vector<char>(3, ' '));
    char cur_player = 'X';
    do {
        // Display the current state of the board
        displayBoard(b);
        // current player to enter their move
        int r,c;
        cout<<"Player "<< cur_player << ", enter your move (row and column): ";
        cin >> r>> c;
        // Update the game board with the player's move
        if (r >= 1 && r <= 3 && c >= 1 && c <= 3 && b[r - 1][c - 1] == ' ') {
            b[r - 1][c - 1] = cur_player;

           // Check for a win
            if (checkWin(b,cur_player)){
                displayBoard(b);
                cout << "Player: " << cur_player << " wins!" <<"\n";
                break;
            }

            // Check for a draw
            if (checkDraw(b)) {
                displayBoard(b);
                cout << "It's a draw" << "\n";
                break;
            }

            // Switch players
            cur_player = (cur_player == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move!! Please try again." <<"\n";
        }
    }while (true);

    return 0;
}

