#include <stdio.h>

int check_left(int, int);
int check_right(int, int);
int check_up(int, int);
int check_down(int, int);

int graph[10][10];

int main (void) {
  int distances[10][10];
  int max_distance = 0;

  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
      scanf("%d", &graph[x][y]);
    }
  }

  // clear distances
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
      distances[x][y] = 0;    
    }
  }

  // walk the graph
  for (int y = 0; y < 10; y++) {
    for (int x = 0; x < 10; x++) {
      if (graph[y][x] == 0) {
        distances[y][x] = check_left(x, y);

        // TODO - when there is no land bound
        // TODO - on one side we need to continue 
        // TODO - checking on the other sides and
        // TODO - dont let that 0 overrule
        int right_moves = check_right(x, y);
        if (distances[y][x] > right_moves && right_moves > 0) {
          distances[y][x] = right_moves;
        }
      
        int up_moves = check_up(x, y);
        if (distances[y][x] > up_moves && up_moves > 0) {
          distances[y][x] = up_moves;
        }
              
        int down_moves = check_down(x, y);
        if (distances[y][x] > down_moves && down_moves > 0) {
          distances[y][x] = down_moves;
        }
      } 
    }
  }

  printf("================== Graph ===================\n");
  
  for (int y = 0; y < 10; y++) {
    for (int x = 0; x < 10; x++) {
      printf("%d ", graph[y][x]);     
    }
    printf("\n");
  }

  printf("================ Distances =================\n");

  for (int y = 0; y < 10; y++) {
    for (int x = 0; x < 10; x++) {
      printf("%d ", distances[y][x]);
      if (distances[y][x] > max_distance) {
        max_distance = distances[y][x];
      }
    }
    printf("\n");
  }

  printf("============================================\n");
  printf("Max Distance: %d\n", max_distance);
  printf("Farthest From Land\n");

  int first = 0;
  for (int y = 0; y < 10; y++) {
    for (int x = 0; x < 10; x++) {
      if (distances[y][x] == max_distance) {
        if (first == 0) {
          first = 1;
          printf("[%d,%d]", y+1, x+1);
        } else {
          printf(", [%d,%d]", y+1, x+1);
        }
      }
    }
  }
  printf("\n\n");
}

int check_left(int x, int y) {
  int newX = x;
  int foundLand = 0;
  int moves = 0;

  while (newX > -1 && foundLand == 0) {
    if (graph[y][newX] == 1) {
      foundLand = 1;
      break;
    }
    newX--;
    moves++;
  }

  if (foundLand == 1) {
    return moves;
  } else {
    return 0;
  }
}

int check_right(int x, int y) {
  int newX = x;
  int foundLand = 0;
  int moves = 0;

  while (newX < 11 && foundLand == 0) {
    if (graph[y][newX] == 1) {
      foundLand = 1;
      break;
    }
    newX++;
    moves++;
  }

  if (foundLand == 1) {
    return moves;
  } else {
    return 0;
  }
}

int check_up(int x, int y) {
  int newY = y;
  int foundLand = 0;
  int moves = 0;

  while (newY > -1 && foundLand == 0) {
    if (graph[newY][x] == 1) {
      foundLand = 1;
      break;
    }
    newY--;
    moves++;
  }

  if (foundLand == 1) {
    return moves;
  } else {
    return 0;
  }
}

int check_down(int x, int y) {
  int newY = y;
  int foundLand = 0;
  int moves = 0;

  while (newY < 11 && foundLand == 0) {
    if (graph[newY][x] == 1) {
      foundLand = 1;
      break;
    }
    newY++;
    moves++;
  }

  if (foundLand == 1) {
    return moves;
  } else {
    return 0;
  }
}
  
