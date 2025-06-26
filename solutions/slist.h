#ifndef SLIST_H
     #define SLIST_H

     typedef struct SNode {
         int value;          // Wert des Knotens
         struct SNode *next; // Zeiger auf nächsten Knoten
     } SNode;

     SNode* add_node(SNode *head, int value); // Fügt Knoten hinzu
     int    count_nodes(SNode *head);         // Zählt Knoten
     void   free_list(SNode *head);           // Gibt Liste frei

     #endif
