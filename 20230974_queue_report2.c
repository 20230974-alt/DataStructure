#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int pages;
} Document;

Document queue[MAX];
int front = 0, rear = 0;

int isEmpty() {
    return front == rear;
}

int isFull() {
    return rear == MAX;
}

void enqueue(char name[], int pages) {
    if (pages > 50) {
        printf("������ �� �ʰ��� ��� �Ұ�\n");
        return;
    }

    if (isFull()) {
        printf("��⿭�� ���� á���ϴ�\n");
        return;
    }

    strcpy(queue[rear].name, name);
    queue[rear].pages = pages;
    rear++;
}

void cancelJob(char name[]) {
    if (isEmpty()) {
        printf("��⿭�� ����ֽ��ϴ�\n");
        return;
    }

    int found = 0;

    for (int i = front; i < rear; i++) {
        if (strcmp(queue[i].name, name) == 0) {
            found = 1;

            for (int j = i; j < rear - 1; j++) {
                queue[j] = queue[j + 1];
            }

            rear--;
            break;
        }
    }

    if (!found) {
        printf("�ش� ������ �����ϴ�\n");
    }
}

void clearQueue() {
    front = 0;
    rear = 0;
    printf("��⿭ �ʱ�ȭ\n");
}

void printQueue() {
    if (isEmpty()) {
        printf("��⿭�� ����ֽ��ϴ�\n");
        return;
    }

    for (int i = front; i < rear; i++) {
        printf("%s %d\n", queue[i].name, queue[i].pages);
    }
}

int main() {
    int menu;
    char name[50];
    int pages;

    while (1) {
        printf("1. �߰� 2. ��� 3. ��ü���� 4. ��� 0. ����\n");
        scanf("%d", &menu);

        if (menu == 1) {
            scanf("%s %d", name, &pages);
            enqueue(name, pages);
        }
        else if (menu == 2) {
            scanf("%s", name);
            cancelJob(name);
        }
        else if (menu == 3) {
            clearQueue();
        }
        else if (menu == 4) {
            printQueue();
        }
        else if (menu == 0) {
            break;
        }
    }

    return 0;
}
