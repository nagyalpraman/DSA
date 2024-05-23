#include <stdio.h>
#include <string.h>
int main()
{
    char str[100], stack[100];
    int flag = 0, len, i, top = -1;

    printf("enter expression:");
    gets(str);
    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            top++;
            stack[top] = str[i];
        }

        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            char ch = stack[top];
            if (ch == '[')
                ch = ']';
            else if (ch == '(')
                ch = ')';
            else
                ch = '}';

            if (ch == str[i])
            {
                top--;
            }
            else
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0 && top == -1)
    {
        printf("the expression is balanced");
    }
    else
    {
        printf("the expression is not balanced");
    }
    return 0;
}

