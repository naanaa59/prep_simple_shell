#include "main.h"


Node *createNode(char data[])
{
	Node *newNode;

	newNode = (Node *)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		strcpy(newNode->data, data);
		newNode->next = NULL;
	}
	return (newNode);
}

void append(Node **head, char data[])
{
	Node *newNode;

	newNode = createNode(data);
	if (*head == NULL)
	{
		*head = newNode;
	} else
	{
		Node *temp;

		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void displayList(Node *head)
{
	Node *temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%s\n", temp->data);
		temp = temp->next;
	}
}

int main(void)
{
	char *path;
	Node *head= NULL;
	Node *temp;

	path = getenv("PATH");


	if (path != NULL)
	{
		char *token;

		token = strtok(path, ":");
		while (token != NULL)
		{
			append(&head, token);
			token = strtok(NULL, ":");
		}
	}

	printf("List of directories in the PATH variable:\n");
	displayList(head);


	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}

	return (0);
}

