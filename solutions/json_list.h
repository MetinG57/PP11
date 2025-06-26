#ifndef JSON_LIST_H
     #define JSON_LIST_H

     #include <jansson.h>

     typedef struct JObject {
         char *name;         // Name aus JSON
         int age;            // Alter aus JSON
         struct JObject *next; // Nächster Knoten
     } JObject;

     JObject* parse_json(const char *filename); // Parsed JSON in Liste
     void     print_list(JObject *head);       // Gibt Liste aus
     void     free_list(JObject *head);        // Gibt Liste frei

     #endif
