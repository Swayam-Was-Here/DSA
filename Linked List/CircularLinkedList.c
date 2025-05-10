#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};


void menu();
void freeList();
void createNode();
void display();
void insertAtBeginning();
void insertAtEnd();
void insertAtPosition();
void deleteByValue();
void deleteByPosition();

struct node *last = NULL;

int main(void) {	
	int choice;
	while(1) {
		menu();
		scanf("%d", &choice);
		switch(choice) {
			case 1: createNode(); break;
			case 2: insertAtBeginning(); break;
			case 3: insertAtEnd(); break;
			case 4: insertAtPosition(); break;
			case 5: deleteByValue(); break;
			case 6: deleteByPosition(); break;
			case 7: display(); break;
			case 8: freeList();
				printf("Exiting...");
				exit(0);
			default: 
				printf("Invalid Choice!\n");
				break;
			}
	}
}

void menu() {
	printf("\n--- Circular Linked List Operations ---\n");
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
	int n, value;
	printf("Enter number of nodes to create: ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		tnp = (struct node *)malloc(sizeof(struct node));
		if(tnp == NULL) {
			printf("Memory allocation failed!\n");
			return;
		}
		printf("Enter data for node %d: ", i + 1);
		scanf("%d", &value);
		tnp->data = value;
		tnp->next = NULL;

		if(last == NULL) {
			last = tnp;
			p = last;
		} else {
			p->next = tnp;
			p = tnp;
		}
	}
}

void display() {
	struct node *p;
	if(last == NULL) {
		printf("List is empty\n");
		return;
	}
	p = last;
	while(p != NULL) {
		printf("%d -> ", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void freeList() {
	struct node *p, *temp;
	if(last == NULL) {
		printf("List is empty\n");
		return;
	}
	p = last;
	while(p != NULL) {
		temp = p;
		p = p->next;
		free(temp);
	}
	last = NULL;
	printf("List freed successfully\n");
}

void insertAtBeginning() {
	struct node *tnp;
	int value;
	tnp = (struct node *)malloc(sizeof(struct node));
	if(tnp == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	printf("Enter data to insert at beginning: ");
	scanf("%d", &value);
	tnp->data = value;
	tnp->next = last;
	last = tnp;
	printf("%d inserted at the beginning\n", value);
}

void insertAtEnd() {
	struct node *tnp;
	int value;
	tnp = (struct node *)malloc(sizeof(struct node));
	if(tnp == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	printf("Enter data to insert at end: ");
	scanf("%d", &value);
	tnp->data = value;
	tnp->next = NULL;

	if(last == NULL) {
		last = tnp;
	} else {
		struct node *p = last;
		while(p->next != NULL) {
			p = p->next;
		}
		p->next = tnp;
	}
	printf("%d inserted at the end\n", value);
}

void insertAtPosition() {
	struct node *tnp, *p;
	int value, pos, i;
	tnp = (struct node *)malloc(sizeof(struct node));
	if(tnp == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	printf("Enter data to insert: ");
	scanf("%d", &value);
	tnp->data = value;
	tnp->next = NULL;

	printf("Enter position to insert at: ");
	scanf("%d", &pos);

	if(pos == 1) {
		tnp->next = last;
		last = tnp;
		printf("%d inserted at position %d\n", value, pos);
		return;
	}

	p = last;
	for(i = 1; i < pos - 1 && p != NULL; i++) {
		p = p->next;
	}

	if(p == NULL) {
		printf("Position out of bounds\n");
		free(tnp);
		return;
	}

	tnp->next = p->next;
	p->next = tnp;

	printf("%d inserted at position %d\n", value, pos);
}

void deleteByValue() {
	struct node *p, *temp;
	int value;
	if(last == NULL) {
		printf("List is empty\n");
		return;
	}
	printf("Enter value to delete: ");
	scanf("%d", &value);
	p = last;

	while(p != NULL && p->data != value) {
		p = p->next;
	}

	if(p == NULL) {
		printf("%d not found in the list\n", value);
		return;
	}

	if(p == last) {
		last = p->next;
	} else {
		struct node *prev = last;
		while(prev->next != p) {
			prev = prev->next;
		}
		prev->next = p->next;
	}

	free(p);
	printf("%d deleted from the list\n", value);
}

void deleteByPosition() {
	struct node *p, *temp;
	int pos, i;
	if(last == NULL) {
		printf("List is empty\n");
		return;
	}
	printf("Enter position to delete: ");
	scanf("%d", &pos);

	if(pos == 1) {
		p = last;
		last = p->next;
		free(p);
		printf("Node at position %d deleted\n", pos);
		return;
	}

	p = last;
	for(i = 1; i < pos - 1 && p != NULL; i++) {
		p = p->next;
	}

	if(p == NULL || p->next == NULL) {
		printf("Position out of bounds\n");
		return;
	}

	temp = p->next;
	p->next = temp->next;

	free(temp);
	printf("Node at position %d deleted\n", pos);
}
