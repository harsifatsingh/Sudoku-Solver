# ⚡️ Ultra-Fast C Sudoku Solver ⚡️

A blazing-fast, highly-optimized Sudoku solver in pure C, combining advanced constraint-propagation techniques with a backtracking fallback for guaranteed solutions. Perfect for embedding in games, tutorials, or as a demonstration of high-performance algorithm design.

---

## 🚀 Key Features

* **Hybrid Solving Strategy**
  * **Constraint Propagation**: Applies *naked singles* and *unique box singles* iteratively to fill easy cells in linear time.
  * **Backtracking**: When propagation stalls, a depth-first search with validity checks kicks in—ensuring every valid puzzle is solved.

* **Bitmask-Based Possibility Tracking**
  * Uses a `short int POSSIBLE = 0x1FF` (9 bits) to efficiently represent which numbers remain valid in each cell.
  * Constant-time updates via bitwise operations for row, column, and box elimination.

* **Cache-Friendly Data Structures**
  * 2D arrays of `Square*` laid out in row-major order for optimal memory locality.
  * Pre-allocated `Box` structs with direct pointers to contained squares—no dynamic resizing during solve.

* **Dynamic Unsolved Counter**
  * Global `short UNSOLVED` decremented on each assignment, enabling immediate detection of completion without scanning the grid.

* **Modular, Clean Architecture**
  * Clear separation of concerns:
    * **`puzzle.c`**: Puzzle initialization & propagation
    * **`backtrack.c`**: Recursive backtracking solver
    * **`box.c`** & **`square.c`**: Box- and square-level logic
    * **`sudoku.h`**: Shared types & prototypes
  * Zero external dependencies—compiles with a single `Makefile`.

---

## 🛠️ Installation & Build

1. **Clone the repo**

   ```bash
   git clone https://github.com/harsifatsingh/Sudoku-Solver.git
   cd Sudoku-Solver
   ```

2. **Build**

   ```bash
   make
   ```

   * Produces the `sudoku` executable, linking only standard C libraries.

3. **Run**

   ```bash
   ./sudoku
   ```

   * Prints the initial puzzle, each propagation step, and final solution. Switches automatically to backtracking if needed.

---

## 🧩 Usage Example

```bash
$ ./sudoku
- - - | - - - | - - -
- - - | - - 9 | - - -
- - 4 | - - - | - - -
------+-------+------

1 - - | - - - | - - -
- - - | - - - | - 9 -
- - - | - 8 - | - - -
------+-------+------

- - - | - - - | - - -
- - - | - - - | - - -
- - - | - - - | 9 - -

…constraint propagation…

…switching to backtracking…

…final solution…
```

---

## 🔬 Under the Hood

1. **Initialization**
   * `createPuzzle()`: Loads a 9×9 integer grid into a dynamic 2D array.
   * `setUpPuzzle()`: Wraps each cell in a `Square` struct, assigns it to the correct `Box`, initializes possibility bitmasks, and updates peers for pre-filled values.

2. **Constraint Propagation Loop**
   * **`checkPuzzle()`**: Scans for any cell with exactly one possible value (`solvable == 1`) and fills it.
   * **`boxSingles()`**: Within each 3×3 box, finds numbers that can go in only one cell *even if that cell has multiple possibilities*, and assigns them.
   * Repeats until no further progress.

3. **Backtracking Fallback**
   * **`backtrackSolve()`**: Picks the first empty cell, tries all valid digits via `isValidMove()`, and recurses—backtracking on failure.
   * Guaranteed to terminate with a solution or report unsolvable.

4. **Optimizations & Tweaks**
   * **Bitwise Masks** for speed: Eliminate expensive loops by marking possibilities with single-bit flags.
   * **Early Termination**: Global `UNSOLVED` counter avoids full-grid scans.
   * **Cache Alignment**: Static array sizes (`SIZE_ROWS`, `SIZE_COLUMNS`) tuned for 9×9 grid fits in L1 cache.
   * **Branch-and-Bound**: Constraint propagation reduces search tree dramatically—backtracking invoked *only* on hard puzzles.

---

## 🧪 Performance Benchmarks

| Puzzle Difficulty | Clue Range | Average Solving Time (ms) | Average Backtrack Count | Average Propagation Count |
| ----------------- | ---------- | ------------------------- | ----------------------- | ------------------------- |
| Very Easy         | 50-80      | 0.009651                  | 0.16                    | 0.74                      |
| Easy              | 36-49      | 0.012159                  | 7.66                    | 44.70                     |
| Medium            | 30-35      | 0.047798                  | 267.29                  | 2298.78                   |
| Hard              | 25-29      | 0.511199                  | 3920.94                 | 35098.85                  |
| Very Hard         | 17-24      | 225.426040                | 1260943.22              | 11348245.99               |

---

## ⚖️ License

MIT License © 2025 — feel free to use, modify, and distribute!

---

> “Combining the light-speed of bitwise constraint checks with rock-solid backtracking, this solver is both beautiful in code and brutal in performance.”
> *— Harsifat Singh, Lead Developer*
