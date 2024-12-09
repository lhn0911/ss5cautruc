#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node *insertAtPosition(Node *head, int data, int position)
{
    Node *newNode = createNode(data);

    if (position == 0)
    {
        newNode->next = head;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        return newNode;
    }

    Node *temp = head;
    int index = 0;

    while (temp != NULL && index < position - 1)
    {
        temp = temp->next;
        index++;
    }

    if (temp == NULL)
    {
        printf("Loi vi tri khong hop le\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    return head;
}

void traverse(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n, i, value, dataToInsert, position;
    Node *head = NULL;

    printf("Nhap so luong phan tu trong danh sach (n): ");
    scanf("%d", &n);

    printf("Nhap cac phan tu cua danh sach:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    printf("Danh sach hien tai:\n");
    traverse(head);

    printf("Nhap gia tri can chen: ");
    scanf("%d", &dataToInsert);

    printf("Nhap vi tri can chen: ");
    scanf("%d", &position);

    head = insertAtPosition(head, dataToInsert, position);

    printf("Danh sach sau khi chen:\n");
    traverse(head);

    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
