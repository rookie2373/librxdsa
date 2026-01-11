/**
  * @test Hello world test
  * @file test_hello_world.c
  * @brief Test file for hello_world API. 
  * 
  * Tests built to check hello_world program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void hello_world();

/** 
 *  @brief Hello world program. Prints hello world!
 *. @return 0 if test succeeds else 1
 * Prints the prompt for librxdsa!
 */
int main() {
    const char* expected_output = "rxDSA 2026.1.2 (D2026.1.2, Jan 11 2026, 09:17:13) [Clang 16.0.0 (clang-1600.0.26.6)] on darwin\nVisit \"github.com/rookie2373\" for more information\n";

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
