#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK 100
#define MAX_OUTPUT 100005

typedef struct
{
    int data[MAX_STACK];
    int top;
} IntStack;

typedef struct
{
    char *data[MAX_STACK];
    int top;
} StringStack;

void initializeIntStack(IntStack *stack)
{
    stack->top = -1;
}

void initializeStringStack(StringStack *stack)
{
    stack->top = -1;
}

void pushInt(IntStack *stack, int value)
{
    stack->top++;
    stack->data[stack->top] = value;
}

int popInt(IntStack *stack)
{
    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

void pushString(StringStack *stack, char *str)
{
    stack->top++;
    stack->data[stack->top] = str;
}

char *popString(StringStack *stack)
{
    char *str = stack->data[stack->top];
    stack->top--;
    return str;
}

char *createEmptyString()
{
    char *str = (char *)malloc(MAX_OUTPUT);
    str[0] = '\0';
    return str;
}

char *decodeString(char *s)
{
    IntStack numberStack;
    StringStack stringStack;

    initializeIntStack(&numberStack);
    initializeStringStack(&stringStack);

    char *currentString = createEmptyString();

    int currentNumber = 0;

    int length = strlen(s);

    for (int i = 0; i < length; i++)
    {
        char currentCharacter = s[i];

        if (isdigit(currentCharacter))
        {
            currentNumber = currentNumber * 10;
            currentNumber = currentNumber + (currentCharacter - '0');
        }
        else if (currentCharacter == '[')
        {
            pushInt(&numberStack, currentNumber);

            pushString(&stringStack, currentString);

            currentString = createEmptyString();

            currentNumber = 0;
        }
        else if (currentCharacter == ']')
        {
            int repeatCount = popInt(&numberStack);

            char *previousString = popString(&stringStack);

            int previousLength = strlen(previousString);
            int currentLength = strlen(currentString);

            char *newString = createEmptyString();

            strcpy(newString, previousString);

            for (int j = 0; j < repeatCount; j++)
            {
                strcat(newString, currentString);
            }

            free(previousString);
            free(currentString);

            currentString = newString;
        }
        else
        {
            int currentLength = strlen(currentString);

            currentString[currentLength] = currentCharacter;
            currentString[currentLength + 1] = '\0';
        }
    }

    return currentString;
}
