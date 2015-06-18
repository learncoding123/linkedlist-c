#include <stdio.h>

struct node {
	int value;
	struct node *next;
};

typedef struct node Node;

Node *head;
Node *tail;

void insert(int);
int fetch(int);
int main(int argc, char *argv[]) {
	int choice;
	int value;
	int index;
	while(1) {
		printf("What do you want to do?\n\n");
		printf("1. Insert \n2. Fetch \n3. Exit \n");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("\nEnter the value you want to insert!\n");
				scanf("%d", &value);
				insert(value);
				printf("\nInserted the value %d into linkedList\n", value); 
				break;
			case 2:
				printf("\nValue at what index you want to fetch\n");
				scanf("%d", &index);
				value = fetch(index);
				printf("\nValue at index %d is %d\n", index, value); //need to fetch real value
				break;
			case 3:
				printf("\nExiting...\n");
				return 0;
			default:
				break;
		}
	}
}


void insert(int value) {
	
	Node newNode;
	newNode.value = value;
	
	if(head == NULL) {
		//this means list is empty
		head = &newNode;
		tail = &newNode;
	} else {
		//list is not empty
		//tail is pointer to last node
		//(*tail) is last node itself
		(*tail).next = &newNode;
		
		//now newNode is the last node and tail should always store pointer to last node.
		tail = &newNode;
	}
}

int fetch(int index) {
	if(head == NULL) {
		return -1;
	}
	
	Node element = *head;
	for (int i = 0; i < index; i++) {
		if(element.next == NULL) {
			return -1;
		}
		//element.next is pointer to some Node. So *(element.next) will be a Node
		element = *(element.next);
	}
	
	return element.value;
	
}