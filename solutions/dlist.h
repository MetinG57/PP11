#ifndef DLIST_H
     #define DLIST_H

     typedef struct DNode {
         void *data;         // Generischer Zeiger für Daten
         struct DNode *prev; // Zeiger auf vorherigen Knoten
         struct DNode *next; // Zeiger auf nächsten Knoten
     } DNode;

     typedef struct DList {
         DNode *head; // Zeiger auf Kopf der Liste
         DNode *tail; // Zeiger auf Ende der Liste
     } DList;

     #endif
