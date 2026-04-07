#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printScore(int scores[], int size, double avg, int option) {
    if (option == 0) printf("\n[��� �л� ���� ���]\n");
    else if (option == 1) printf("\n[��� �̻� �л� ���� ��� (���: %.2f)]\n", avg);
    else if (option == 2) printf("\n[��� �̸� �л� ���� ��� (���: %.2f)]\n", avg);

    for (int i = 0; i < size; i++) {
     
        if (option == 0) {
            printf("�л� %d: %d��\n", i + 1, scores[i]);
        }
        else if (option == 1 && scores[i] >= avg) {
            printf("�л� %d: %d��\n", i + 1, scores[i]);
        }
        else if (option == 2 && scores[i] < avg) {
            printf("�л� %d: %d��\n", i + 1, scores[i]);
        }
    }
    printf("-------------------------------\n");
}

int main() {
    int scores[10];
    int sum = 0;
    double average;

    srand(time(NULL));

  
    for (int i = 0; i < 10; i++) {
        scores[i] = rand() % 101;
        sum += scores[i];
    }
    average = (double)sum / 10;


    printf("��ü ��� ����: %.2f\n", average);


    printScore(scores, 10, average, 0);


    printScore(scores, 10, average, 1);


    printScore(scores, 10, average, 2);

    return 0;
}
