#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[101];

    printf("���ڿ��� �Է��ϼ���: ");
   
    fgets(input, sizeof(input), stdin);

 
    input[strcspn(input, "\n")] = '\0';

    int len = strlen(input);

    char* stack = (char*)malloc(sizeof(char) * len);

    
    int top = -1;
    for (int i = 0; i < len; i++) {
        stack[++top] = input[i];
    }

   
    printf("�Ųٷ� ��µ� ���ڿ�: ");
    while (top >= 0) {
        printf("%c", stack[top--]);
    }
    printf("\n");

    free(stack);

    return 0;
}
