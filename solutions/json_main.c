#include "json_list.h"
     #include <stdio.h>
     #include <stdlib.h>
     #include <unistd.h>

     void usage(const char *prog) {
         fprintf(stderr, "Usage: %s -i <file.json>\n", prog); // Zeige Hilfe
         exit(EXIT_FAILURE);
     }

     int main(int argc, char *argv[]) {
         int opt;
         char *filename = NULL;

         while ((opt = getopt(argc, argv, "i:")) != -1) {
             if (opt == 'i') {
                 filename = optarg; // Dateiname aus Option
             } else {
                 usage(argv[0]); // Ungültige Option
             }
         }
         if (!filename) {
             usage(argv[0]); // Kein Dateiname angegeben
         }

         JObject *head = parse_json(filename); // JSON parsen
         print_list(head);                     // Liste ausgeben
         free_list(head);                      // Liste freigeben
         return 0;                             // Fertig
     }
