#include <stdlib.h>  // malloc, free
#include <stddef.h>  // size_t type

// Declaration of my_strlen function (defined in other file)
size_t my_strlen(const char *str);

// Function to duplicate a string
char *my_strdup(const char *str) {
    // Error check: NULL pointer
    if (str == NULL) {
        return NULL;
    }
    
    // 1. Get length of original string
    size_t len = my_strlen(str);
    
    // 2. Allocate memory (+1 for '\0' terminator)
    char *copy = malloc(len + 1);
    if (copy == NULL) {
        return NULL;  // Memory allocation failed
    }
    
    // 3. Copy string character by character
    for (size_t i = 0; i <= len; i++) {  // <= to include '\0'
        copy[i] = str[i];
    }
    
    return copy;  // Return pointer to duplicated string
}

// Helper function to safely free duplicated string
void my_strdup_free(char *str) {
    if (str != NULL) {
        free(str);
    }
}