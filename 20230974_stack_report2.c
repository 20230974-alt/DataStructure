#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char str[200];
    char stack[200];
    int top = -1;
    bool isValid = true;

    printf("���ڿ��� �Է��ϼ���: ");

    fgets(str, sizeof(str), stdin);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char ch = str[i];

  
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
     
        else if (ch == ')' || ch == '}' || ch == ']') {
          
            if (top == -1) {
                isValid = false;
                break;
            }

            char openPair = stack[top--]; 

            if ((ch == ')' && openPair != '(') ||
                (ch == '}' && openPair != '{') ||
                (ch == ']' && openPair != '[')) {
                isValid = false;
                break;
            }
        }
    }

   
    if (top != -1) {
        isValid = false;
    }

 
    if (isValid) {
        printf(">> ��ȿ�� ��ȣ\n");
    }
    else {
        printf(">> ��ȿ���� ���� ��ȣ\n");
    }

    return 0;
}
