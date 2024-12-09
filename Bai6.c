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

void traverseFromStart(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sach trong\n");
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int replaceValue(Node *head, int oldValue, int newValue)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == oldValue)
        {
            temp->data = newValue;
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main()
{
    int n, i, value, oldValue, newValue;
    Node *head = NULL;

    printf("Nhap so luong phan tu trong danh sach (n): ");
    scanf("%d", &n);

    if (n > 0)
    {
        printf("Nhap cac phan tu cua danh sach:\n");
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    printf("Danh sach ban dau:\n");
    traverseFromStart(head);

    printf("Nhap gia tri can thay the: ");
    scanf("%d", &oldValue);

    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);

    int result = replaceValue(head, oldValue, newValue);

    if (result)
    {
        printf("Danh sach sau khi thay the:\n");
        traverseFromStart(head);
    }
    else
    {
        printf("Khong tim thay phan tu thay the\n");
    }

    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
