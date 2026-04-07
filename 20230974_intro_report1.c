#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main() {
   
    int scores[10];
    int sum = 0;
    double average;


    srand(time(NULL));

    printf("--- �л� ���� ���� ���α׷� ---\n");


    for (int i = 0; i < 10; i++) {
      
        scores[i] = rand() % 101;

        printf("�л� %d�� ����: %d\n", i + 1, scores[i]);

      
        sum += scores[i];
    }

    average = (double)sum / 10;


    printf("��ü �л� ���� �հ�: %d\n", sum);
    printf("��ü �л� ���� ���: %.2f\n", average);


    return 0;
}
