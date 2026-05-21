# 🧩 Sudoku Solver — C++ PBL Project

A console-based Sudoku solver built in C++ using the **Backtracking Algorithm**. This project was developed as part of a Problem Based Learning (PBL) assignment to demonstrate recursion, constraint satisfaction, and algorithmic problem solving.

---

## 📌 Features

- Solve any valid 9×9 Sudoku puzzle
- Enter your own puzzle or load a built-in hard puzzle
- Input validation — detects conflicting values before solving
- Clean ASCII grid display with 3×3 box separators
- Uses `0` or `.` to represent empty cells

---

## 🖥️ Sample Output

```
  +-------+-------+-------+
  | 8 . . | . . . | . . . |
  | . . 3 | 6 . . | . . . |
  | . 7 . | . 9 . | 2 . . |
  +-------+-------+-------+
  ...

  [✓] Puzzle Solved Successfully!

  +-------+-------+-------+
  | 8 1 2 | 7 5 3 | 6 4 9 |
  | 9 4 3 | 6 8 2 | 1 7 5 |
  | 6 7 5 | 4 9 1 | 2 8 3 |
  +-------+-------+-------+
  ...
```

---

## ⚙️ How to Compile & Run

### Requirements
- C++ compiler (g++ recommended)
- C++17 or later

### Steps

```bash
# Clone the repository
git clone https://github.com/tanya493/sudoku-solver-.git
cd sudoku-solver-

# Compile
g++ -o sudoku_solver sudoku_solver.cpp -std=c++17

# Run
./sudoku_solver
```

> On Windows, use `sudoku_solver.exe` instead of `./sudoku_solver`

---

## 🎮 How to Use

1. Run the program
2. Choose an option:
   - **[1]** Enter your own puzzle row by row (use `0` or `.` for empty cells)
   - **[2]** Load a built-in hard puzzle
3. The solver will validate and solve the puzzle instantly

### Input Example
```
Row 1: 5 3 0 0 7 0 0 0 0
Row 2: 6 0 0 1 9 5 0 0 0
...
```

---

## 🧠 Algorithm — Backtracking

The solver uses **recursive backtracking**:

1. Find the first empty cell
2. Try placing digits `1–9`
3. Check if the digit is valid (not repeated in row, column, or 3×3 box)
4. If valid → place it and recurse
5. If no digit works → **backtrack** (reset cell and try previous step again)
6. Repeat until the board is fully solved or no solution exists

---

## 📁 Project Structure

```
sudoku-solver/
│
├── sudoku_solver.cpp    # Main source file
└── README.md            # Project documentation
```

---

## 👩‍💻 Author

**Tanya** — PBL Project, B.Tech CSE

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).
