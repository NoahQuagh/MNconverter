//
// Created by noahq on 22/09/2026.
//

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/**
 * @brief Affiche les consignes d'utilisation du programme sur la sortie d'erreur standard.
 *
 * @param prog_name Le nom de l'exécutable.
 */
void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s -i <fichier_entree> -o <fichier_sortie> -t <json|csv>\n", prog_name);
}

/**
 * @brief Convertit une chaîne de caractères représentant un format en sa valeur énumérée OutputFormat.
 *
 * @param format_str La chaîne de caractères à analyser.
 * @return OutputFormat Renvoie FORMAT_... si la chaîne est reconnue,
 *                      sinon renvoie FORMAT_UNKNOWN.
 */
OutputFormat parse_format(const char *format_str) {
    if (strcmp(format_str, "json") == 0) return FORMAT_JSON;
    if (strcmp(format_str, "csv") == 0) return FORMAT_CSV;
    return FORMAT_UNKNOWN;
}


/**
 * principal qui analyse les arguments passés par l'utilisateur, prépare la structure Config et valide les entrées avant de lancer les processus
 * @param argc nb d'argument
 * @param argv tableau des arguments
 * @return {EXIT_SUCCESS | EXIT_FAILURE} reussite du démarage de la commande
 */
int main(int argc, char *argv[]) {
    Config config = {NULL,NULL,FORMAT_UNKNOWN};
    int opt;

    while ((opt = getopt(argc,argv,"i:o:t:"))!=-1) {
        switch (opt) {
            case 'i':
                config.input_path = optarg;
                break;
            case 'o':
                config.output_path = optarg;
                break;
            case 't':
                config.format=parse_format(optarg);
                break;
            default:
                return EXIT_FAILURE;
        }
    }

    if (!config.input_path || !config.output_path || config.format == FORMAT_UNKNOWN) {
        fprintf(stderr, "Erreur : Arguments manquants ou format invalide.\n");
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}