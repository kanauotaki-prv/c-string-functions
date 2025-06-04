#include <stdlib.h>  // malloc, free
#include <stddef.h>  // size_t type
#include <string.h>  // strcat

// Declarations of other functions
size_t my_strlen(const char *str);
char *my_strdup(const char *str);

// Function to join multiple strings with separator
char *my_strjoin(char **strings, const char *separator) {
    // Error check: NULL pointers
    if (strings == NULL || separator == NULL) {
        return NULL;
    }
    
    // 1. Count array elements and calculate total length
    size_t count = 0;
    size_t total_len = 0;
    
    // Count strings until NULL is found
    while (strings[count] != NULL) {
        total_len += my_strlen(strings[count]);
        count++;
    }
    
    // If no strings found, return empty string
    if (count == 0) {
        return my_strdup("");
    }
    
    // Add separator length × (count - 1)
    total_len += my_strlen(separator) * (count - 1);
    
    // 2. Allocate memory for result
    char *result = malloc(total_len + 1);
    if (result == NULL) {
        return NULL;  // Memory allocation failed
    }
    
    // 3. Initialize with empty string
    result[0] = '\0';
    
    // 4. Join strings with separator
    for (size_t i = 0; i < count; i++) {
        strcat(result, strings[i]);  // Add current string
        if (i < count - 1) {  // Add separator except for last element
            strcat(result, separator);
        }
    }
    
    return result;  // Return joined string
}

// Helper function to safely free joined string
void my_strjoin_free(char *str) {
    if (str != NULL) {
        free(str);
    }
}