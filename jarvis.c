#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Jarvis: Hello, how can I assist you?\n");
    while (1) {
        printf("You: ");
        scanf("%[^\n]%*c", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        printf("Jarvis: I'm sorry, I didn't understand your request. Could you please rephrase it?\n");
    }
    printf("Jarvis: Goodbye!\n");
    return 0;
}

