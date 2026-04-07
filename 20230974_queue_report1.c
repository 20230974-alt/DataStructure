#include <stdio.h>
#include <stdbool.h>


#define SIZE 30 

typedef struct {
    int data[SIZE];
    int front;
    int rear;
} LinearQueue;

void initQueue(LinearQueue* q) {
    q->front = 0;
    q->rear = -1;
}


bool isEmpty(LinearQueue* q) {
    return q->rear < q->front;
}

bool isFull(LinearQueue* q) {
    return q->rear == SIZE - 1;
}


bool enqueue(LinearQueue* q, int value) {
    if (isFull(q)) {
        printf("ť�� ���� á���ϴ�. ������ �� �����ϴ�.\n");
        return false;
    }
    q->rear++;
    q->data[q->rear] = value;
    return true;
}


int dequeue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("ť�� ��� �ֽ��ϴ�.\n");

        initQueue(q);

        return -1;
    }
    int value = q->data[q->front];
    q->front++;

    
    if (isEmpty(q)) {
        initQueue(q);
    }

    return value;
}


void printQueue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("���� ť�� ��� �ֽ��ϴ�.\n");
        return;
    }
    printf("���� ť ����: [ ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("]\n");
}

int main() {
    LinearQueue q;
    initQueue(&q);

    int choice, data;


    while (1) {
        printf("\nť ���� ���α׷�\n");
        printf("1. ����\n");
        printf("2. ����\n");
        printf("3. ť ���\n");
        printf("4. ����\n");
        printf("����");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("������ ������ �Է�:");
            scanf("%d", &data);
            if (enqueue(&q, data)) {
                printf("%d �����Ͱ� ���ԵǾ����ϴ�.\n", data);
            }
            break;

        case 2:
            data = dequeue(&q);
            if (data != -1) {
                printf("������ ������: %d\n", data);
            }
            break;

        case 3:
            printQueue(&q);
            break;

        case 4:
            printf("���α׷��� �����մϴ�.\n");
            return 0;

        default:
            printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
        }
    }

    return 0;
}
