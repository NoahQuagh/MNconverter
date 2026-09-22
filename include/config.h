//
// Created by noahq on 22/09/2026.
//

#ifndef CONFIG_H
#define CONFIG_H

#define BUFFER_SIZE 1024

// Formats sortie
typedef enum {
    FORMAT_JSON,
    FORMAT_CSV,
    FORMAT_UNKNOWN
} OutputFormat;

// struc de la configuration de l'exécution
typedef struct {
    char *input_path;
    char *output_path;
    OutputFormat format;
} Config;

#endif