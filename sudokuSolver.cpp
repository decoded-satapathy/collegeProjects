#include <iostream>
using namespace std;

bool issafe(int sudoku[9][9], int row, int col, int digit) {
    // Same row
    for (int j = 0; j < 9; j++) {
        if (sudoku[row][j] == digit) {
            return false;
        }
    }
    // Same column
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == digit) {
            return false;
        }
    }
    // Same grid
    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;
    // Checking the value in the grid
    for (int i = sr; i < sr + 3; i++) {
        for (int j = sc; j < sc + 3; j++) {
            if (sudoku[i][j] == digit) {
                return false;
            }
        }
    }
    return true;
}

bool sudokusolver(int sudoku[9][9], int row, int col) {
    // Base case
    if (row == 9) {
        return true;
    }
    // Recursive part
    // Setting the value of the next row and next column
    int nextrow = row;
    int nextcol = col + 1;
    if (nextcol == 9) {
        nextrow = row + 1;
        nextcol = 0;
    }
    if (sudoku[row][col] != 0) {
        return sudokusolver(sudoku, nextrow, nextcol);
    }
    for (int digit = 1; digit <= 9; digit++) {
        if (issafe(sudoku, row, col, digit)) {
            sudoku[row][col] = digit;
            if (sudokusolver(sudoku, nextrow, nextcol)) {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}

void printsudoku(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        if(i % 3 ==0){
            cout<<"-----------------------"<<endl;
        }
        for (int j = 0; j < 9; j++) {
            if((j+1)%3 == 0){
                cout << sudoku[i][j] << " | ";
            }else{
                cout << sudoku[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout<<"-----------------------"<<endl;

}

int main() {
    int sudoku[9][9] = {
        {7, 0, 0, 0, 0, 0, 2, 0, 0},
        {4, 0, 2, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 2, 0, 1, 0, 0, 0},
        {3, 0, 0, 1, 8, 0, 0, 9, 7},
        {0, 0, 9, 0, 7, 0, 6, 0, 0},
        {6, 5, 0, 0, 3, 2, 0, 0, 1},
        {0, 0, 0, 4, 0, 9, 0, 0, 0},
        {5, 0, 0, 0, 0, 0, 1, 0, 6},
        {0, 0, 6, 0, 0, 0, 0, 0, 8}
    };
    cout<<"Original Sudoko"<<endl;
    printsudoku(sudoku);
    cout<<endl;

    if (sudokusolver(sudoku, 0, 0)) {
        cout << "Solution exists" << endl;
        printsudoku(sudoku);
    } else {
        cout << "Solution does not exist" << endl;
    }

    return 0;
}

