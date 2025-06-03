#include <stddef.h>  // size_t type

// Function to count string length
size_t my_strlen(const char *str) {
    // Error check: NULL pointer
    if (str == NULL) {
        return 0;
    }
    
    size_t length = 0;  // Counter variable
    
    // Loop until '\0' is found
    while (str[length] != '\0') {
        length++;  // Increment counter
    }
    
    return length;  // Return length
}