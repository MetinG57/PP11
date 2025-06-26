#include <stdio.h>
     #include "slist.h"

     int main(void) {
         SNode *head = NULL; // Starte mit leerer Liste
         int choice, val;

         do {
             printf("1) Count nodes\n2) Add node\n3) Exit\n> "); // Menü
             if (scanf("%d", &choice) != 1) break; // Eingabe prüfen
             switch (choice) {
                 case 1:
                     printf("Count: %d\n", count_nodes(head)); // Anzahl ausgeben
                     for (SNode *p = head; p; p = p->next)
                         printf("Node at %p: %d\n", (void*)p, p->value); // Knoten ausgeben
                     break;
                 case 2:
                     printf("Value: ");
                     scanf("%d", &val); // Wert einlesen
                     head = add_node(head, val); // Knoten hinzufügen
                     break;
                 case 3:
                     free_list(head); // Liste freigeben
                     break;
                 default:
                     printf("Invalid option\n"); // Ungültige Eingabe
             }
         } while (choice != 3); // Bis Exit gewählt wird

         return 0; // Fertig
     }
