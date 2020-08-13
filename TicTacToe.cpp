#include <vector>
#include <iostream>

using namespace std;

void drawBoard(const vector < char >&gameBoard) {
   for (int i = 0; i < 9; i += 3) {
      cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
         << gameBoard.at(i + 2) << "  " << endl;
      if (i < 6) {
         cout << "-----|-----|-----" << endl;
      }
   }
   cout << endl;
    
   return;
}

void initVector(vector <char> &v) {
    for (unsigned int i = 0; i < v.size(); i++) {
      v.at(i)='a' + i;
    }
   // TODO: implement function
   return;
}


int convertPosition(char boardPosition) {
   int index;
   index = boardPosition - 'a';
   // TODO: implement function
   return index;
}

bool validPlacement(const vector<char>  &gameBoard, int positionIndex) {
   if (gameBoard.size() == 0 && positionIndex == 0) {
     return false;
   }
   if (positionIndex >= gameBoard.size() || positionIndex < 0) {
     return false;
   }
   if (gameBoard.at(positionIndex) == 'X' || gameBoard.at(positionIndex) == 'O') {
     return false;
   }
   // TODO: implement function
   else {
     return true;
    }
}

///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///     Continues asking for a position until a valid position has been entered.

int getPlay(const vector<char> &gameBoard) {
   
   // TODO: implement function
   char boardPosition = ' ';
   int position;
   
   cout << "Please choose a position: " << endl;
   cin >> boardPosition;
   position = convertPosition(boardPosition);

   while (!validPlacement(gameBoard, position)) {
     cout << "Please choose a position: " << endl;
     cin >> boardPosition;
     position = convertPosition(boardPosition);
   }
   return position;
}


///     Winning conditions in tic-tac-toe require three marks from same 
///     player in a single row, column or diagonal.

bool gameWon(const vector<char> &gameBoard) {
   if (gameBoard.at(0) == gameBoard.at(1) && gameBoard.at(1) == gameBoard.at(2)) {
      return true;
   }
   else if (gameBoard.at(0) == gameBoard.at(4) && gameBoard.at(4) == gameBoard.at(8)) {
      return true;
   }
   else if (gameBoard.at(2) == gameBoard.at(4) && gameBoard.at(4) == gameBoard.at(6)) {
      return true;
   }
   else if (gameBoard.at(3) == gameBoard.at(4) && gameBoard.at(4) == gameBoard.at(5)) {
      return true;
   }
   else if (gameBoard.at(6) == gameBoard.at(7) && gameBoard.at(7) == gameBoard.at(8)) {
      return true;
   }
   else if (gameBoard.at(0) == gameBoard.at(3) && gameBoard.at(3) == gameBoard.at(6)) {
      return true;
   }
   else if (gameBoard.at(1) == gameBoard.at(4) && gameBoard.at(4) == gameBoard.at(7)) {
      return true;
   }
   else if (gameBoard.at(2) == gameBoard.at(5) && gameBoard.at(5) == gameBoard.at(8)) {
      return true;
   }
    else {
      return false;
   } 
   // TODO: implement function
   return false;
}

bool boardFull(const vector<char> &gameBoard) {
   int count = 0;
   for (unsigned int i = 0; i < gameBoard.size(); ++i) {
     if (gameBoard.at(i) == 'X' || gameBoard.at(i) == 'O') {
       ++count;
     }
   }
     if (count == gameBoard.size()) {
      return true;
     }
   // TODO: implement function
   return false;
}


// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main() {
   // Variables that you may find useful to utilize
   vector<char> gameBoard(9);
   int curPlay;
   int whosTurn = PLAYER1; // Player 1 always goes first and is 'X'

   /// TODO: Initialize board to empty state
   initVector(gameBoard);
   /// TODO: Display the empty board
   drawBoard(gameBoard);
   /// TODO: Get a play
   while (!gameWon(gameBoard) && !boardFull(gameBoard)) {

    /// TODO: Get a play
    /// TODO: Set the play on the board
      curPlay = getPlay(gameBoard);

    /// TODO: Switch the turn to the other player
      if (whosTurn == PLAYER1) {
        gameBoard.at(curPlay) = 'X';
        drawBoard(gameBoard);
        whosTurn = PLAYER2;
      }
      else if (whosTurn == PLAYER2) {
        gameBoard.at(curPlay) = 'O';
        drawBoard(gameBoard);
        whosTurn = PLAYER1;
      }
    }

    /// TODO: Output the updated board
   /// TODO: Determine winner and output appropriate message

   if (!gameWon(gameBoard)) {
     cout << "No one wins" << endl;
   }

   else {
     if (whosTurn == PLAYER2) {
       cout << "Player 1 Wins!!" << endl;
     }
     else {
       cout << "Player 2 Wins!!" << endl;
     }
   }
   return 0;
}