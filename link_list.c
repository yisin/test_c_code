#include <stdio.h>
#include <stdlib.h>

struct listMac {
	char mac[18];
	struct listMac *nextPtr;
};

typedef struct listMac ListMac;
typedef ListMac *ListMacPtr;

void insert(ListMacPtr *sPtr, char value);
char delete(ListMacPtr *sPtr, char value);
int isEmpty(ListMacPtr sPtr);
void printList(ListMacPtr currentPtr);
void instructions(void);

int main(void)
{
	ListMacPtr startPtr = NULL;
	int choice = 0;
	char item[18]={0};

	instructions();
	printf("? ");
	scanf( "%d", &choice);

	while (choice != 3) {

		switch(choice) {
			case 1: printf("Enter a character: ");
				scanf("\n%s", &item);
				insert(&startPtr, item);
				printList(startPtr);
				break;
			case 2:
				if (!isEmpty(startPtr)) {
					printf("Enter character to be deleted: ");
					scanf("\n%s", &item);

					if (delete(&startPtr, item)) {
						printf("%c deleted.\n", item);
						printList(startPtr);
					}
					else{
						printf("%c not found.\n\n", item);
					}
				}
				else{
					printf("List is empty.\n\n");
				}
 				break;
 			default:
 				printf("Invalid choice.\n\n");
 				instructions();
 				break;
		}  //end switch()
		printf("?");
		scanf("%d", &choice);
	} // end whild
	printf("end of run.\n");
	return 0;
}

void instructions(void)
{
	printf("Enter your choice:\n"
		"	1 to insert an element into the list.\n"
		"	2 to delete an element from the list.\n"
		"	3 to end\n");
}

void insert(ListMacPtr *sPtr, char value)
{
	ListMacPtr newPtr;
	ListMacPtr previousPtr;
	ListMacPtr currentPtr;

	newPtr = malloc(sizeof(ListMac));

	if (newPtr != NULL)
	{
		newPtr->mac = value;
		newPtr->nextPtr = NULL;

		previousPtr = NULL;
		currentPtr = *sPtr;

		while (currentPtr != NULL && value > currentPtr->mac) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (previousPtr == NULL) {
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else {
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else{
		printf("%c not inserted. No memory avaiable\n", value);
	}
}

char delete(ListMacPtr *sPtr, char value)
{
	ListMacPtr previousPtr;
	ListMacPtr currentPtr;
	ListMacPtr tempPtr;

	if (value == (*sPtr)->mac) {
		tempPtr = *sPtr;
		*sPtr = (*sPtr)->nextPtr;
		free (tempPtr);
		return value;
	}
	else{
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;

		while (currentPtr != NULL && currentPtr->mac != value) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (currentPtr != NULL) {
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free(tempPtr);
			return value;
		}
	}

	return '\0';
}

int isEmpty(ListMacPtr sPtr)
{
	return sPtr == NULL;
}

void printList(ListMacPtr currentPtr)
{
	if (currentPtr == NULL) {
		printf("List is empty.\n\n");
	}
	else {
		printf("The list is:\n");
		while(currentPtr != NULL) {
			printf("%c --> ", currentPtr->mac);
			currentPtr = currentPtr->nextPtr;
		}
		printf("NULL\n\n");
	}
}