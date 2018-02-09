#include <stdio.h>
#include <stdbool.h>    // bool
#include <stdlib.h>     // malloc
#include <string.h>     // strdup

#include "simpletreeprint.h"

extern const char **environ;
static bool _env_count_called = false;
static size_t _env_count = 0;

size_t env_count();
void strarrcpy(char **dest, const char **src);

#define Space "    "

int main()
{
    printf("There are %zu environment variables defined.\n", env_count());

    char **envcpy = malloc(env_count() * sizeof(*envcpy));
    strarrcpy(envcpy, environ);

    //for (int i = 0; envcpy[i] != NULL; i++)
    //    printf("%s\n", envcpy[i]);

    int names = 3;
    int subvalues = 5;

    for (size_t i = 1; i <= names; i++) {
        printf(
            "%sVAR%zu\n",
            (i != names) ? Tee : Ell,
            i
        );
        for (size_t j = 1; j <= subvalues; j++) {
            printf(
                "%s%ssubvalue %zu\n",
                (i != names) ? Pipe : Space,
                (j != subvalues) ? Tee : Ell,
                j
            );
        }
    }


    // Free each string in `envcpy`.
    //for (char **p = envcpy; p != NULL; p++)
    //    free(*p);

    // Free array itself.
    //free(envcpy);
}

size_t env_count()
{
    if (!_env_count_called) {
        _env_count_called = true;
        for (const char **envp = environ; *envp; envp++, _env_count++);
    }
    return _env_count;
}

// Copies strings to array `dest` from array `src`.
// Stops when a null string is encountered.
// New strings placed in `dest` are heap allocated.
void strarrcpy(char **dest, const char **src)
{
    while (*src) {
        *dest = strdup(*src);
        src++, dest++;
    }
}

