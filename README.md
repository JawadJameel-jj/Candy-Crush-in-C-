# 🍬 Candy Crush (C++ Console Game)

A fully interactive **Candy Crush-style game** built in **C++**, featuring colorful console graphics, real-time input handling, and multiple difficulty levels.

---

## 🎮 Game Overview

This is a **console-based puzzle game** where players swap adjacent candies to form matches of 3 or more and score points before time or moves run out.

---

## 🚀 Features

### 🎯 Gameplay

* Match-3 mechanics (horizontal, vertical, diagonal)
* Special patterns like **L-shapes**
* Real-time swapping system
* Score tracking system

### 🧩 Game Modes

* **Easy Mode**

  * 8x8 grid
  * 5 candy types
  * 60 seconds time limit
* **Hard Mode**

  * 10x10 grid
  * 7 candy types
  * 40 seconds time limit

### ⏱️ Timer System

* Countdown timer using `chrono`
* Game ends when time runs out

### 🎨 Visuals

* Colored candies using ANSI escape codes
* Interactive cursor selection
* Highlighted selected candy

### 🎮 Controls

* Arrow Keys → Move cursor
* `Enter` → Select candy
* `S` → Swap candies
* `X` → Exit game

---

## 🧠 Core Concepts Used

* **2D Arrays** → Game board
* **Randomization (`rand`)** → Candy generation
* **Game Loops** → Continuous gameplay
* **File Handling** → Instructions & score file
* **Keyboard Input (`_getch`)** → Real-time controls
* **Time Management (`chrono`)** → Timer system

---

## 🗂️ Project Structure

```id="v8c0p3"
├── main.cpp          # Complete game logic
├── help.txt          # Instructions file
├── score.txt         # Stores player scores
```

---

## ▶️ How to Run

### 🖥️ Requirements

* Windows OS (uses `<conio.h>` and `<Windows.h>`)
* C++ Compiler (e.g., g++, MSVC)

### ⚙️ Compile & Run

```bash id="7oz5zj"
g++ main.cpp -o candy_crush
./candy_crush
```

---

## 🕹️ How to Play

1. Start the game
2. Enter your name
3. Select mode (Easy / Hard)
4. Use arrow keys to navigate
5. Press:

   * `Enter` → Select candy
   * `S` → Swap with adjacent candy
6. Match candies to earn points
7. Game ends when:

   * Time runs out ⏱️
   * Moves finish

---

## 🏆 Scoring System

* Match of 3 → +5 points
* Special shapes → bonus points
* Score displayed live during gameplay

---

## 📂 Additional Features

* 📖 Instructions loaded from `help.txt`
* 🧾 Score system using `score.txt`
* 🎬 Credits screen

---

## ⚠️ Limitations

* Windows-only (due to `conio.h` and `Windows.h`)
* No advanced animations (console-based)
* Basic file-based score storage

---

## 🔮 Future Improvements

* Add leaderboard system
* Sound effects 🎵
* GUI version (SFML / Qt)
* Better animations
* Save/load game progress

---

## 👨‍💻 Developers

* **Jawad Jameel**
* **Muhammad Rayyan Asim**

FAST NUCES – BS Computer Science (Batch 2023)

---
