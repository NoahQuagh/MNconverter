#detection du systeme
ifeq ($(OS),Windows_NT)
    RM = rmdir /s /q
    FIXPATH = $(subst /,\,$1)
else
    RM = rm -rf
    FIXPATH = $1
endif

# nom de l'exécutable final
EXEC = bin/MNconverter

# compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

# chemin des dossiers
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# recherche automatique de tous les fichiers .c dans src/ et ses sous-dossiers
SRCS = $(shell find $(SRC_DIR) -name '*.c')

# transformation de la liste des .c en fichiers objets .o dans le dossier build/
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# regle principale (par défaut)
all: $(EXEC)

# regle pour lier l'exécutable final
$(EXEC): $(OBJS) | $(BIN_DIR)
	$(CC) $(OBJS) -o $@

# regle pour compiler chaque fichier .c en fichier .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# creation des dossiers de sortie s'ils n'existent pas
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# nettoyage des fichiers temporaires (.o)
clean:
	$(RM) $(BUILD_DIR)

# nettoyage complet (fichiers tmp + exe)
fclean: clean
	$(RM) $(BIN_DIR)

# recompile complète
re: fclean all

# evite les conflits si des fichiers s'appellent clean, fclean, etc.
.PHONY: all clean fclean re