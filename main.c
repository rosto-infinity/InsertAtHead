#include <stdio.h>
#include <stdlib.h>

// D�finition de la structure du n�ud
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour ins�rer un n�ud au d�but de la liste
void insertAtHead(Node **head, int newData) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Fonction pour afficher la liste cha�n�e
void printList(Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Fonction principale
int main() {
    Node *head = NULL; // Initialisation de la t�te de la liste

    // Insertion de quelques �l�ments
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);

    // Affichage de la liste
    printf("Liste cha�n�e : ");
    printList(head);

    // Lib�ration de la m�moire
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
