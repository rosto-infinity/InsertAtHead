#include <stdio.h>
#include <stdlib.h>

// Définition de la structure du nœud
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour insérer un nœud au début de la liste
void insertAtHead(Node **head, int newData) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Fonction pour afficher la liste chaînée
void printList(Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Fonction principale
int main() {
    Node *head = NULL; // Initialisation de la tête de la liste

    // Insertion de quelques éléments
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);

    // Affichage de la liste
    printf("Liste chaînée : ");
    printList(head);

    // Libération de la mémoire
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
