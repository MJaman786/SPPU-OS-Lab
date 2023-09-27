#include <stdio.h>
#include <stdlib.h>

int number_processes = 5;
int number_resources = 3;
int Available_Matrix[3] = {2, 3, 2};

int Remaing_Need_Matrix[5][3] = {
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
};

void Remaing_Need(int re_mat[5][3], int max_need[5][3], int allocated[5][3]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      re_mat[i][j] = max_need[i][j] - allocated[i][j];
    }
  }
}

int main(void) {
  int Allocation_Matrix[5][3] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
  };

  int Max_Need_Matrix[5][3] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
  };

  int finish[5] = {0};
  int ans[5];
  int index = 0;

  printf("----------------------------------\n");
  printf("|Processes| Allocated | Max Need  |\n");
  printf("----------------------------------\n");

  for (int i = 0; i < 5; i++) {
    printf("|     p%d  | ", i);
    for (int j = 0; j < 3; j++) {
      printf("%d | ", Allocation_Matrix[i][j]);
    }
    for (int k = 0; k < 3; k++) {
      printf("%d | ", Max_Need_Matrix[i][k]);
    }
    printf("\n");
  }
  printf("\n");
  printf("------------\n");
  printf("| Rem Need |\n");
  printf("------------\n");
  Remaing_Need(Remaing_Need_Matrix, Max_Need_Matrix, Allocation_Matrix);

  for (int k = 0; k < 5; k++) {
    for (int i = 0; i < 5; i++) {
      if (finish[i] == 0) {
        int flag = 1;
        for (int j = 0; j < 3; j++) {
          if (Remaing_Need_Matrix[i][j] > Available_Matrix[j]) {
            flag = 0;
            break;
          }
        }
        if (flag) {
          ans[index++] = i;
          for (int y = 0; y < 3; y++) {
            Available_Matrix[y] += Allocation_Matrix[i][y];
          }
          finish[i] = 1;
        }
      }
    }
  }

  printf("\nSafe Sequence is = ");
  for (int i = 0; i < 5; i++) {
    printf("P%d", ans[i]);
    if (i != 4) {
      printf(" -> ");
    }
  }
  printf("\n");

  return 0;
}
