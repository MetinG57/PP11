#include <stdio.h>
     #include "dlist.h"  // Enthält DNode und DList

     // Statisches Array für 5 Knoten (Werte 1–5)
     DNode nodes[5];
     DList list;

     int main(void) {
         // Initialisiere statische Knoten
         for (int i = 0; i < 5; i++) {
             nodes[i].data = (void*)(long)(i + 1); // Speichere Index + 1 als Daten
             nodes[i].prev = (i > 0) ? &nodes[i - 1] : NULL; // Verlinke vorherigen Knoten
             nodes[i].next = (i < 4) ? &nodes[i + 1] : NULL; // Verlinke nächsten Knoten
         }
         list.head = &nodes[0]; // Kopf der Liste
         list.tail = &nodes[4]; // Ende der Liste

         // Traversiere vorwärts
         printf("Forward: ");
         for (DNode *p = list.head; p != NULL; p = p->next) {
             printf("%ld ", (long)p->data); // Gib Daten aus
         }
         printf("\n");

         // Traversiere rückwärts
         printf("Backward: ");
         for (DNode *p = list.tail; p != NULL; p = p->prev) {
             printf("%ld ", (long)p->data); // Gib Daten aus
         }
         printf("\n");

         return 0; // Fertig
     }
