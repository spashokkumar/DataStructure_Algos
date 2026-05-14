/**
 * @file main.c
 * @brief Menu-driven implementation of a Singly Linked List in C.
 * @author spashokkumar
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct Node
 * @brief Represents a single element in the singly linked list.
 */
struct Node
{
    int val;            /**< Integer data held by the node */
    struct Node *next;  /**< Pointer to the next sequential node */
};

typedef struct Node N;

/* Global pointers for list operations */
N *start = NULL; 
N *tmp = NULL;
N *ptr = NULL;

/* Function Prototypes */
void createList(void);
void displayList(void);
void insertBeg(void);
void insertEnd(void);
void countNodes(void);
void insertAt(void);
void insertBefore(void);
void searchNode(void);
void deleteFirst(void);
void deleteLast(void);
void deleteByValue(void);
void deleteByPosition(void);
void updateNode(void);
void reverseList(void);
void freeAllNodes(void);

/**
 * @brief Application entry point displaying the interactive console menu.
 */
int main(void)
{
    int ch;
    do
    {
        printf("\n...M.E.N.U...\n");
        printf("1...Create Node / Append to List.\n");
        printf("2...Display List.\n");
        printf("3...Insert at beginning.\n");
        printf("4...Insert at the end.\n");
        printf("5...Count nodes.\n");
        printf("6...Insert after specific position.\n");
        printf("7...Insert before a given value.\n");
        printf("8...Search an element.\n");
        printf("9...Delete first element.\n");
        printf("10...Delete last element.\n");
        printf("11...Delete node by value.\n");
        printf("12...Delete node by position.\n");
        printf("13...Update a node's value.\n");
        printf("14...Reverse the List.\n");
        printf("0...EXIT.\n");
        printf("\nEnter your choice: ");
        
        if (scanf("%d", &ch) != 1) {
            printf("\nInvalid Input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (ch)
        {
        case 0:
            freeAllNodes();
            printf("\nEnd of Program\n");
            break;
        case 1: createList(); break;
        case 2: displayList(); break;
        case 3: insertBeg(); break;
        case 4: insertEnd(); break;
        case 5: countNodes(); break;
        case 6: insertAt(); break;
        case 7: insertBefore(); break;
        case 8: searchNode(); break;
        case 9: deleteFirst(); break;
        case 10: deleteLast(); break;
        case 11: deleteByValue(); break;
        case 12: deleteByPosition(); break;
        case 13: updateNode(); break;
        case 14: reverseList(); break;
        default: printf("\nInvalid Input!!\n"); break;
        }
    } while (ch != 0);

    return 0;
}

/**
 * @brief Allocates and appends a node to construct or extend the list.
 */
void createList(void)
{
    ptr = (N *)malloc(sizeof(N));
    if (!ptr) { printf("\nMemory allocation failed!\n"); return; }
    
    printf("\nEnter value: ");
    scanf("%d", &ptr->val);
    ptr->next = NULL;

    if (start == NULL)
    {
        start = ptr;
    }
    else
    {
        tmp = start;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = ptr;
    }
    printf("Node successfully created.\n");
}

/**
 * @brief Traverses and prints all integer elements inside the list sequentially.
 */
void displayList(void)
{
    if (start == NULL)
    {
        printf("\nList is Empty!\n");
        return;
    }
    tmp = start;
    printf("\nList Elements: ");
    while (tmp != NULL)
    {
        printf("%d -> ", tmp->val);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

/**
 * @brief Inserts an allocated node at the structural beginning of the list.
 */
void insertBeg(void)
{
    ptr = (N *)malloc(sizeof(N));
    if (!ptr) { printf("\nMemory allocation failed!\n"); return; }
    
    printf("\nEnter value: ");
    scanf("%d", &ptr->val);
    
    ptr->next = start;
    start = ptr;
    printf("Node inserted at beginning.\n");
}

/**
 * @brief Appends an allocated node to the absolute end of the list safely.
 */
void insertEnd(void)
{
    if (start == NULL)
    {
        createList();
        return;
    }
    ptr = (N *)malloc(sizeof(N));
    if (!ptr) { printf("\nMemory allocation failed!\n"); return; }
    
    printf("\nEnter value: ");
    scanf("%d", &ptr->val);
    ptr->next = NULL;
    
    tmp = start;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = ptr;
    printf("Node inserted at end.\n");
}

/**
 * @brief Traverses the list to calculate and output total node footprint.
 */
void countNodes(void)
{
    int c = 0;
    tmp = start;
    while (tmp != NULL)
    {
        c++;
        tmp = tmp->next;
    }
    printf("\nNumber of Nodes are: %d\n", c);
}

/**
 * @brief Inserts a node immediately after an explicit target 1-indexed position.
 */
void insertAt(void)
{
    if (start == NULL)
    {
        printf("\nList is empty. Cannot insert at position.\n");
        return;
    }
    int pos, c = 1;
    printf("\nAfter which position to insert: ");
    scanf("%d", &pos);
    
    tmp = start;
    while (tmp != NULL && c < pos)
    {
        tmp = tmp->next;
        c++;
    }
    
    if (tmp == NULL)
    {
        printf("\nPosition out of range!\n");
        return;
    }
    
    ptr = (N *)malloc(sizeof(N));
    if (!ptr) { printf("\nMemory allocation failed!\n"); return; }
    
    printf("\nEnter value: ");
    scanf("%d", &ptr->val);
    
    ptr->next = tmp->next;
    tmp->next = ptr;
    printf("Node inserted successfully.\n");
}

/**
 * @brief Finds a given node value target and inserts a node directly before it.
 */
void insertBefore(void)
{
    if (start == NULL)
    {
        printf("\nList is Empty!\n");
        return;
    }
    int target;
    printf("\nEnter structural value before which you want to insert: ");
    scanf("%d", &target);
    
    if (start->val == target)
    {
        insertBeg();
        return;
    }
    
    tmp = start;
    while (tmp->next != NULL && tmp->next->val != target)
    {
        tmp = tmp->next;
    }
    
    if (tmp->next == NULL)
    {
        printf("\nTarget value not found in list.\n");
        return;
    }
    
    ptr = (N *)malloc(sizeof(N));
    if (!ptr) { printf("\nMemory allocation failed!\n"); return; }
    
    printf("\nEnter value to insert: ");
    scanf("%d", &ptr->val);
    
    ptr->next = tmp->next;
    tmp->next = ptr;
    printf("Node inserted successfully.\n");
}

/**
 * @brief Iterates the entire list to lookup value index matching user target.
 */
void searchNode(void)
{
    if (start == NULL)
    {
        printf("\nList is Empty!\n");
        return;
    }
    int target, position = 1, flag = 0;
    printf("\nEnter node value for searching: ");
    scanf("%d", &target);
    
    tmp = start;
    while (tmp != NULL)
    {
        if (tmp->val == target)
        {
            flag = 1;
            break;
        }
        tmp = tmp->next;
        position++;
    }
    
    if (flag == 1)
        printf("\nValue found at position %d\n", position);
    else
        printf("\nValue doesn't exist\n");
}

/**
 * @brief Deletes and frees the head element node of the linked list safely.
 */
void deleteFirst(void)
{
    if (start == NULL)
    {
        printf("\nList is already Empty!\n");
        return;
    }
    tmp = start;
    start = start->next;
    free(tmp);
    printf("\nFirst node deleted successfully.\n");
}

/**
 * @brief Deletes and drops the final leaf node of the current list structure.
 */
void deleteLast(void)
{
    if (start == NULL)
    {
        printf("\nList is already Empty!\n");
        return;
    }
    if (start->next == NULL)
    {
        free(start);
        start = NULL;
        printf("\nLast remaining node deleted.\n");
        return;
    }
    
    tmp = start;
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
    printf("\nLast node deleted successfully.\n");
}

/**
 * @brief Traverses to pinpoint a particular matching integer value and wipes it out.
 */
void deleteByValue(void)
{
    if (start == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }
    int target;
    printf("\nEnter value which you want to delete: ");
    scanf("%d", &target);
    
    if (start->val == target)
    {
        deleteFirst();
        return;
    }
    
    tmp = start;
    int flag = 0;
    while (tmp->next != NULL)
    {
        if (tmp->next->val == target)
        {
            flag = 1;
            break;
        }
        tmp = tmp->next;
    }
    
    if (flag == 1)
    {
        ptr = tmp->next;
        tmp->next = tmp->next->next;
        free(ptr);
        printf("\nNode with value %d deleted.\n", target);
    }
    else
    {
        printf("\nValue doesn't exist in the List\n");
    }
}

/**
 * @brief Targets an accurate 1-indexed target position to erase from linear flow.
 */
void deleteByPosition(void)
{
    if (start == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }
    int pos;
    printf("\nEnter position which you want to delete: ");
    scanf("%d", &pos);
    
    if (pos == 1)
    {
        deleteFirst();
        return;
    }
    
    tmp = start;
    int c = 1;
    while (tmp != NULL && c < pos - 1)
    {
        tmp = tmp->next;
        c++;
    }
    
    if (tmp == NULL || tmp->next == NULL)
    {
        printf("\nPosition out of bounds!\n");
        return;
    }
    
    ptr = tmp->next;
    tmp->next = tmp->next->next;
    free(ptr);
    printf("\nNode at position %d deleted.\n", pos);
}

/**
 * @brief Rewrites payload values contained inside standard matching nodes.
 */
void updateNode(void)
{
    if (start == NULL)
    {
        printf("\nList is Empty!\n");
        return;
    }
    int target, flag = 0;
    printf("\nEnter value which you want to update: ");
    scanf("%d", &target);
    
    tmp = start;
    while (tmp != NULL)
    {
        if (tmp->val == target)
        {
            flag = 1;
            break;
        }
        tmp = tmp->next;
    }
    
    if (flag == 1)
    {
        int newVal;
        printf("\nEnter value to update with: ");
        scanf("%d", &newVal);
        tmp->val = newVal;
        printf("\nNode updated successfully.\n");
    }
    else
    {
        printf("\nValue not found in list.\n");
    }
}

/**
 * @brief Inverts structural pointers in-place to reverse tracking linear paths.
 */
void reverseList(void)
{
    N *next_node = NULL;
    ptr = NULL;
    tmp = start;
    while (tmp != NULL)
    {
        next_node = tmp->next;
        tmp->next = ptr;
        ptr = tmp;
        tmp = next_node;
    }
    start = ptr;
    printf("\nList successfully reversed.\n");
}

/**
 * @brief Safely wipes memory pools of remaining allocations on application exit.
 */
void freeAllNodes(void)
{
    tmp = start;
    while (tmp != NULL)
    {
        ptr = tmp->next;
        free(tmp);
        tmp = ptr;
    }
    start = NULL;
}
