#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

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
	printf("\n--- Linked List Operations ---\n");
        printf("1. Create a new node\n");
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
    struct node *tnp, *p;
    int value, n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        tnp = (struct node *)malloc(sizeof(struct node));
        if (tnp == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        tnp->data = value;
        tnp->next = NULL;

        if (head == NULL) {
            head = tnp;
            p = head;
        } else {
            p->next = tnp;
            p = tnp;
        }
    }    
}

void insertAtBeginning() {
    struct node *tnp;
    int value;
    tnp = (struct node *)malloc(sizeof(struct node));
    if (tnp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data to insert at beginning: ");
    scanf("%d", &value);
    tnp->data = value;
    tnp->next = head;
    head = tnp;
    printf("%d inserted at the beginning\n", value);
}

void insertAtEnd() {
    struct node *tnp, *p;
    int value;
    tnp = (struct node *)malloc(sizeof(struct node));
    if (tnp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data to insert at end: ");
    scanf("%d", &value);
    tnp->data = value;
    tnp->next = NULL;

    if (head == NULL) {
        head = tnp; // list was empty: new node is head
    } else {
        p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = tnp;
    }
    printf("%d inserted at the end.\n", value);
}

void insertAtPosition() {
    struct node *tnp, *p;
    int value, position;
    tnp = (struct node *)malloc(sizeof(struct node));
    if (tnp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data to insert: ");
    scanf("%d", &value);
    tnp->data = value;

    printf("Enter position: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Position must be ≥ 1.\n");
        free(tnp);
        return;
    }

    if (position == 1) {
        tnp->next = head;
        head = tnp;
        printf("%d inserted at position %d\n", value, position);
        return;
    }

    p = head;
    for (int i = 1; i < position - 1 && p != NULL; i++) {
        p = p->next;
    }

    if (p == NULL) {
        printf("Position out of bounds.\n");
        free(tnp);
        return;
    }

    tnp->next = p->next;
    p->next = tnp;
    printf("%d inserted at position %d\n", value, position);


}

void deleteByValue() {
    struct node *p, *q;
    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->data == value) {
        p = head;
        head = head->next;
        free(p);
        printf("%d deleted from the list.\n", value);
        return;
    }

    p = head;
    while (p->next != NULL && p->next->data != value) {
        p = p->next;
    }

    if (p->next == NULL) {
        printf("%d not found in the list.\n", value);
        return;
    }

    q = p->next;
    p->next = q->next;
    free(q);
    printf("%d deleted from the list.\n", value);
}

void deleteByPosition() {
    struct node *p, *q;
    int position;
    printf("Enter position to delete: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Position must be ≥ 1.\n");
        return;
    }

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position == 1) {
        p = head;
        head = head->next;
        free(p);
        printf("Node at position %d deleted.\n", position);
        return;
    }

    p = head;
    for (int i = 1; i < position - 1 && p != NULL; i++) {
        p = p->next;
    }

    if (p == NULL || p->next == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    q = p->next;
    p->next = q->next;
    free(q);
    printf("Node at position %d deleted.\n", position);
}

void display() {
    struct node *p;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    p = head;
    printf("Linked List: ");
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void freeList() {
    struct node *p, *q;
    p = head;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    head = NULL;
    printf("List freed.\n");
}
