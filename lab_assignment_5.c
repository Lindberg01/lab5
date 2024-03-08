/*
COP3502C Spring 2024 Lab 4
Copyright 2024 Lindberg Gay
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head) {
    int count = 0;
    node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|

void insertChar(node** pHead, char c)  //Insert at the end!
{
    node* newNode = (node*)malloc(sizeof(node));
    
    newNode->letter = c;
    node* last = *pHead;
    newNode->next = NULL;

    if (*pHead == NULL) {
        *pHead = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead) {
    node* current = *pHead;
    node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *pHead = NULL;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head) {
    int clength = 0;
    node* current = head;
    clength = length(head);
    
    char* str = (char*)malloc((clength+1) * sizeof(char));
    if (str == NULL) {
        exit(1);
    }
    current = head;
    int index = 0;
    while (current != NULL) {
        str[index++] = current->letter;
        current = current->next;
    }
    str[clength] = '\0';
    return str;
}
int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt", "r");

    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        //for (i = strLen; i > 0; i--)
        {
            fscanf(inFile, " %c", &c);
            insertChar(&head, c);
        }

        str = toCString(head);
        printf("String is : %s\n", str);

        free(str);
        deleteList(&head);

        if (head != NULL)
        {
            break;
        }
    }

    fclose(inFile);
}

