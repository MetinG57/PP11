#include <stdlib.h>
     #include <string.h>
     #include "json_list.h"

     // Parsed JSON-Array in eine verkettete Liste
     JObject* parse_json(const char *filename) {
         JObject *head = NULL, *tail = NULL;
         json_error_t error;
         json_t *root = json_load_file(filename, 0, &error);
         if (!root) {
             fprintf(stderr, "Fehler beim Laden der JSON-Datei: %s\n", error.text);
             return NULL;
         }
         if (!json_is_array(root)) {
             fprintf(stderr, "JSON ist kein Array\n");
             json_decref(root);
             return NULL;
         }

         for (size_t i = 0; i < json_array_size(root); i++) {
             json_t *obj = json_array_get(root, i);
             if (!json_is_object(obj)) continue;

             json_t *name = json_object_get(obj, "name");
             json_t *age = json_object_get(obj, "age");
             if (!json_is_string(name) || !json_is_integer(age)) continue;

             JObject *new_node = malloc(sizeof(JObject));
             if (!new_node) continue;
             new_node->name = strdup(json_string_value(name)); // Name duplizieren
             new_node->age = json_integer_value(age);
             new_node->next = NULL;

             if (!head) {
                 head = tail = new_node; // Erster Knoten
             } else {
                 tail->next = new_node; // Ans Ende anhängen
                 tail = new_node;
             }
         }
         json_decref(root); // JSON freigeben
         return head;
     }

     // Gibt die Liste aus
     void print_list(JObject *head) {
         for (JObject *p = head; p; p = p->next) {
             printf("Name: %s, Age: %d\n", p->name, p->age);
         }
     }

     // Gibt die Liste frei
     void free_list(JObject *head) {
         JObject *current = head;
         while (current) {
             JObject *next = current->next;
             free(current->name); // Duplizierten String freigeben
             free(current);       // Knoten freigeben
             current = next;
         }
     }
