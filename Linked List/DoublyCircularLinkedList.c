#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head, *last = NULL;

void menu();
void createNode();
void insertAtBeginning();
void insertAtEnd();
void insertAtPosition();
void deleteByValue();
void deleteByPosition();
void display();
void freeList();

int main(void) {
    int choice;
    while(1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createNode();
                break;

            case 2:
                insertAtBeginning();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                insertAtPosition();
                break;
            case 5:
                deleteByValue();
                break;
            case 6:
                deleteByPosition();
                break;
            case 7:
                display();
                break;
            case 8:
                freeList();
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 8.\n");
                break;
        }
    }
    return 0;
}

void menu() {
    printf("\n\n---DOUBLY CIRCULAR LINKED LIST---\n");
    printf("1. Create nodes\n");
    printf("2. Insert at beginning\n");
    printf("3. Insert at end\n");
    printf("4. Insert at specific position\n");
    printf("5. Delete by value\n");
    printf("6. Delete by position\n");
    printf("7. Display the list\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

void createNode() {
    node *tnp, *p;
    int value, n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        tnp = (node *)malloc(sizeof(node));
        if (tnp == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        tnp->data = value;
        tnp->next = NULL;
        tnp->prev = NULL;

        if (head == NULL && last == NULL) {
            head = tnp;
            last = tnp;
            tnp->next = tnp;
            tnp->prev = tnp;
            p = head;
        } else {
            p->next = tnp;
            tnp->prev = p;
            head->prev = tnp;
            tnp->next = head;
            last = tnp;
            p = tnp;
        }
    }
}

void freeList() {
    node *temp;

    if (head == NULL && last == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        temp = head;
        head = head->next;
        free(temp);
    }
    while (head != last );
    free(last);
    head = NULL;
    last = NULL;
    printf("List freed successfully\n");
    return;
}

void display() {
    node *p;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    p = head;
    printf("List: ");
    do {
        printf("[%d] -> ", p->data);
        p = p->next;
    } while (p != head);
    printf("NULL\n");

}

void insertAtBeginning() {
    node *tnp;
    int value;
    printf("Enter to insert at beginning: ");
    scanf("%d", &value);

    tnp = (node *)malloc(sizeof(node));
    if (tnp == NULL) {
        printf("MEMORY ALLOCATION FAILED\n");
        return;
    }

    tnp->data = value;
    tnp->prev = NULL;
    tnp->next = NULL;

    if (head == NULL && last == NULL) {
        head = tnp;
        last = tnp;
    } else {
        head->prev = tnp;
        tnp->next = head;
        last->next = tnp;
        tnp-> prev = last;
        head = tnp;
    }

    printf("%d Inserted at the beginning successfully\n\n", value);

}

void insertAtEnd() {
        node *tnp;
        int value;
        printf("Enter the value to insert: ");
        scanf("%d", &value);

        tnp = (node *)malloc(sizeof(node));

        if (tnp == NULL) {
            printf("ALLOCATION FAILED\n\n");
            return;
        }

        tnp->data = value;
        tnp->prev = NULL;
        tnp->next = NULL;

        if (head == NULL && last == NULL) {
            head = tnp;
            last = tnp; 
        } else {
            last->next = tnp;
            tnp->prev = last;
            head->prev = tnp;
            tnp->next = head;
            last = tnp;
        }

        printf("%d Inserted at end successfullly\n", value);
}

void insertAtPosition() {

    node *tnp;
    int position, value;

    tnp = (node *)malloc(sizeof(node));
    if (tnp == NULL) {
        printf("Memory Allocation failed\n");
        return;
    }

    printf("Enter data to insert: ");
    scanf("%d", &value);
    tnp->data = value;
    tnp->next = NULL;
    tnp->prev = NULL;

    printf("Enter the position to insert at: ");
    scanf("%d", &position);

    if (position <= 0) {
        printf("Position can't be negative or zero\n");
        free(tnp);
        return;
    }

    if (position == 1) {
        if (head == NULL) {
            head = tnp;
            last = tnp;
            tnp->next = tnp;
            tnp->prev = tnp;
        } else {
            tnp->next = head;
            tnp->prev = last;
            head->prev = tnp;
            last->next = tnp;
            head = tnp;
        }
    } else {
        if (head == NULL) {
            printf("List is empty. Position must be 1.\n");
            free(tnp);
            return;
        }

        node *temp = head;
        int i;
        for (i = 1; i < position - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        // Check if position exceeds the list length + 1
        if (i < position - 1) {
            printf("Position exceeds the list length. Inserting at the end.\n");
        }

        tnp->next = temp->next;
        tnp->prev = temp;
        temp->next->prev = tnp;
        temp->next = tnp;
        if (temp == last) {
            last = tnp;
        }
    }
}

void deleteByValue() {
    int value;
    node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter the value to delete: ");
    scanf("%d", &value);

    node *p = head;
    while (p!= last && p->data != value) {      //p->next != head
        p = p->next;
    }

    if(p == last && p->data != value) {                  //p->next == head
        printf("Value not found\n");
        return;
    }
    
    if (p->prev != p && p->next != p) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    } else {
        // flag++;
        head = NULL;
        last = NULL;
    }


    if(last == p) {
        last = p->prev;
    }

    if(head == p) {
        head = p->next;
    }

    free(p);
    printf("%d deleted from the list\n", value);
}

void deleteByPosition() {
    node *tnp, *p;
    int position, i;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter the node you want to delete: ");
    scanf("%d", &position);

    if (position <= 0) {
        printf("Enter natural number for position\n");
        return;
    }
    
    if (position == 1) {
        p = head;
        
        if (p->next == p && p->prev == p) {
            head = NULL;
            last = NULL;
        } else {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            head = head->next;
        }
        free(p);
        printf("Node at position %d deleted\n", position);
        return;
    }
    
    p = head;

    for (i = 1; i < position; i++) {
        p = p->next;
        if (p == head) {
            printf("Position out of bounds\n");
            return;
        }
    }

    p->next->prev = p->prev;
    p->prev->next = p->next;

    if(p == last) {
        last = p->prev;
    }

    free(p);
    printf("Node at position %d deleted\n", position);
}