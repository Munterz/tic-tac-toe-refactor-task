# Tic-Tac-Toe Refactored

This project is based on a tutorial from GeeksforGeeks called "Simple Tic-Tac-Toe Game using C++".  

---

## ✅ What I did

I took the code from the tutorial and made some improvements to make the code easier to read and maintain. I did **not** add any new features, only changed the code structure (refactoring).

---

## 🔧 Changes I made

### 1. Extracted functions
- Split `player_turn()` into three smaller functions:
    - `getMoveChoice()`
    - `convertChoiceToCoords()`
    - `makeMove()`

**Why:** Easier to understand and debug.

---

### 2. Created a `Board` class
- Moved the game board `grid[3][3]` into its own class.
- Moved `display_board()` and `gameover()` logic into the `Board` class.

**Why:**
- Better structure
- Encapsulates board-related logic
- Easier to expand in the future

---

### 3. Cleaned up logic
- Replaced magic numbers and repeated conditions with cleaner function calls.
- Used `.at(row, col)` methods to access board cells safely.

---

## ✅ Result

The game runs exactly the same as the original tutorial version, but the code is now better organized and easier to work with.
