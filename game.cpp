#include <iostream>
#include <conio.h>
#include <cstdlib>

const int width = 20, height = 20;
char gameBoard[height][width];

struct SnakeSegment {
  int x;
  int y;
};

std::vector<SnakeSegment> snake;

void initGame() {
  // Initialize game board and snake
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      gameBoard[i][j] = ' ';
    }
  }
  snake.push_back({width / 2, height / 2});
  snake.push_back({snake[0].x - 1, snake[0].y});
  // Place food at random position
  gameBoard[rand() % height][rand() % width] = '*';
}

void updateGame() {
  // Get user input and update direction
  char input = _getch();
  // ...
  
  // Move snake head
  snake[0].x += dx;
  snake[0].y += dy;
  
  // Check collisions and handle consequences
  if (// collision with walls or snake body) {
    // Game over
  } else if (gameBoard[snake[0].y][snake[0].x] == '*') {
    // Eat food, grow snake, place new food
  }
  
  // Update remaining snake segments
  for (int i = 1; i < snake.size(); ++i) {
    snake[i].x = snake[i - 1].x;
    snake[i].y = snake[i - 1].y;
  }
}

void drawGame() {
  // Clear console and redraw game board with snake and food
  system("cls");
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      std::cout << gameBoard[i][j];
    }
    std::cout << std::endl;
  }
}

int main() {
  initGame();
  while (true) {
    updateGame();
    drawGame();
    // Delay between updates
    Sleep(100);
  }
  return 0;
}
