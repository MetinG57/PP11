#include <stdlib.h>
     #include "slist.h"

     // Fügt einen neuen Knoten mit value am Anfang der Liste hinzu
     SNode* add_node(SNode *head, int value) {
         SNode *new_node = malloc(sizeof(SNode)); // Neuer Knoten
         if (!new_node) return head; // Falls malloc fehlschlägt
         new_node->value = value;    // Setze Wert
         new_node->next = head;      // Verlinke mit bisherigem Kopf
         return new_node;            // Neuer Kopf
     }

     // Zählt die Anzahl der Knoten in der Liste
     int count_nodes(SNode *head) {
         int count = 0;
         for (SNode *p = head; p != NULL; p = p->next) {
             count++; // Zähle jeden Knoten
         }
         return count;
     }

     // Gibt die gesamte Liste frei
     void free_list(SNode *head) {
         SNode *current = head;
         while (current != NULL) {
             SNode *next = current->next; // Speichere nächsten Knoten
             free(current);              // Gib aktuellen Knoten frei
             current = next;             // Gehe zum nächsten
         }
     }
