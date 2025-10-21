#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void hello_world();

int main() {
    const char* expected_output = "Thanks for using librxdsa\nWill make it interactive afterwards\n";

    FILE* tmp = tmpfile();
    if (!tmp) {
        perror("tmpfile");
        return 1;
    }

    fflush(stdout);
    int stdout_fd = fileno(stdout);

    if (dup2(fileno(tmp), stdout_fd) == -1) {
        perror("dup2");
        return 1;
    }

    hello_world();

    fflush(stdout);
    rewind(tmp);

    char output[256] = {0};
    fread(output, 1, sizeof(output) - 1, tmp);

    if (strcmp(output, expected_output) == 0) {
        printf("Test passed\n");
        fclose(tmp);
        return 0;
    } else {
        fprintf(stderr, "Test failed\nExpected:\n%s\nGot:\n%s", expected_output, output);
        fclose(tmp);
        return 1;
    }
}
