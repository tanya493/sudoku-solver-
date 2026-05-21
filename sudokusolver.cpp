/*
 * ╔══════════════════════════════════════════════════════════════╗
 * ║           CONSOLE-BASED SUDOKU SOLVER IN C++                ║
 * ║           Problem Based Learning (PBL) Project              ║
 * ╚══════════════════════════════════════════════════════════════╝
 *
 * Algorithm : Backtracking (Recursive)
 * Features  : Input puzzle, solve, display board, validate input
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

const int SIZE = 9;
const int EMPTY = 0;

// ─────────────────────────────────────────────
//  DISPLAY BOARD
// ─────────────────────────────────────────────
void displayBoard(const vector<vector<int>>& board) {
    cout << "\n  +-------+-------+-------+\n";
    for (int row = 0; row < SIZE; row++) {
        cout << "  | ";
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == EMPTY)
                cout << ". ";
            else
                cout << board[row][col] << " ";

            if ((col + 1) % 3 == 0)
                cout << "| ";
        }
        cout << "\n";
        if ((row + 1) % 3 == 0)
            cout << "  +-------+-------+-------+\n";
    }
    cout << "\n";
}

// ─────────────────────────────────────────────
//  VALIDATION CHECKS
// ─────────────────────────────────────────────
bool isInRow(const vector<vector<int>>& board, int row, int num) {
    for (int col = 0; col < SIZE; col++)
        if (board[row][col] == num)
            return true;
    return false;
}

bool isInCol(const vector<vector<int>>& board, int col, int num) {
    for (int row = 0; row < SIZE; row++)
        if (board[row][col] == num)
            return true;
    return false;
}

bool isInBox(const vector<vector<int>>& board, int startRow, int startCol, int num) {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (board[startRow + row][startCol + col] == num)
                return true;
    return false;
}

bool isSafe(const vector<vector<int>>& board, int row, int col, int num) {
    return !isInRow(board, row, num)
        && !isInCol(board, col, num)
        && !isInBox(board, row - row % 3, col - col % 3, num);
}

// ─────────────────────────────────────────────
//  BACKTRACKING SOLVER
// ─────────────────────────────────────────────
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == EMPTY) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board))
                            return true;
                        board[row][col] = EMPTY;  // backtrack
                    }
                }
                return false;  // no valid number found → backtrack
            }
        }
    }
    return true;  // all cells filled
}

// ─────────────────────────────────────────────
//  VALIDATE INITIAL BOARD INPUT
// ─────────────────────────────────────────────
bool isValidBoard(const vector<vector<int>>& board) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            int num = board[row][col];
            if (num != EMPTY) {
                // temporarily remove to check placement
                vector<vector<int>> temp = board;
                temp[row][col] = EMPTY;
                if (!isSafe(temp, row, col, num)) {
                    cout << "  [!] Conflict at cell (" << row + 1 << ", " << col + 1 << ") with value " << num << "\n";
                    return false;
                }
            }
        }
    }
    return true;
}

// ─────────────────────────────────────────────
//  INPUT PUZZLE
// ─────────────────────────────────────────────
void inputPuzzle(vector<vector<int>>& board) {
    cout << "\n  Enter the Sudoku puzzle row by row.\n";
    cout << "  Use 0 or . for empty cells. Separate numbers by spaces.\n";
    cout << "  Example: 5 3 0 0 7 0 0 0 0\n\n";

    for (int row = 0; row < SIZE; row++) {
        cout << "  Row " << row + 1 << ": ";
        for (int col = 0; col < SIZE; col++) {
            string token;
            cin >> token;
            if (token == ".") {
                board[row][col] = 0;
            } else {
                try {
                    int val = stoi(token);
                    if (val < 0 || val > 9) {
                        cout << "  [!] Invalid value. Please enter digits 0-9.\n";
                        col--;  // retry this cell
                    } else {
                        board[row][col] = val;
                    }
                } catch (...) {
                    cout << "  [!] Invalid input. Please enter a digit.\n";
                    col--;
                }
            }
        }
    }
}

// ─────────────────────────────────────────────
//  LOAD SAMPLE PUZZLE (HARD)
// ─────────────────────────────────────────────
void loadSamplePuzzle(vector<vector<int>>& board) {
    vector<vector<int>> sample = {
        {8, 0, 0,  0, 0, 0,  0, 0, 0},
        {0, 0, 3,  6, 0, 0,  0, 0, 0},
        {0, 7, 0,  0, 9, 0,  2, 0, 0},

        {0, 5, 0,  0, 0, 7,  0, 0, 0},
        {0, 0, 0,  0, 4, 5,  7, 0, 0},
        {0, 0, 0,  1, 0, 0,  0, 3, 0},

        {0, 0, 1,  0, 0, 0,  0, 6, 8},
        {0, 0, 8,  5, 0, 0,  0, 1, 0},
        {0, 9, 0,  0, 0, 0,  4, 0, 0}
    };
    board = sample;
}

// ─────────────────────────────────────────────
//  MAIN MENU
// ─────────────────────────────────────────────
void printBanner() {
    cout << "\n";
    cout << "  ╔══════════════════════════════════════╗\n";
    cout << "  ║       SUDOKU SOLVER — C++ PBL        ║\n";
    cout << "  ║     Backtracking Algorithm Demo      ║\n";
    cout << "  ╚══════════════════════════════════════╝\n\n";
}

int main() {
    printBanner();

    vector<vector<int>> board(SIZE, vector<int>(SIZE, EMPTY));

    cout << "  Choose an option:\n";
    cout << "  [1] Enter your own puzzle\n";
    cout << "  [2] Load a sample hard puzzle\n";
    cout << "  >> ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        inputPuzzle(board);
    } else {
        loadSamplePuzzle(board);
        cout << "\n  Sample puzzle loaded!\n";
    }

    cout << "\n  ── Puzzle to Solve ──";
    displayBoard(board);

    if (!isValidBoard(board)) {
        cout << "  [✗] The puzzle has conflicting values. Please re-check your input.\n\n";
        return 1;
    }

    cout << "  Solving";
    for (int i = 0; i < 3; i++) { cout << "."; cout.flush(); }
    cout << "\n";

    if (solveSudoku(board)) {
        cout << "\n  [✓] Puzzle Solved Successfully!\n";
        cout << "  ── Solution ──";
        displayBoard(board);
    } else {
        cout << "\n  [✗] No solution exists for the given puzzle.\n\n";
    }

    return 0;
}