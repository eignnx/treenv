#include <stdio.h>
#include <stdbool.h>    // bool
#include <stdlib.h>     // malloc
#include <string.h>     // strdup

#include "terminal_colors.h"

extern const char **environ;
static bool _env_count_called = false;
static size_t _env_count = 0;

size_t env_count();
void strarrcpy(char **dest, const char **src);
void strarrfree(char **arr, size_t len);

void display_env_fwd(char **env);
void display_env_bwd(char **env);

#define Ell  " └──"
#define Tee  " ├──"
#define Pipe " │  "
#define Space "    "

#define string char *
int cmp(const void *a, const void *b)
{
    // Using an alias for `char *` so my brain doesn't implode.
    return strcmp(*(const string *) a, *(const string *) b);
}

int main()
{
    char **envcpy = malloc(env_count() * sizeof(*envcpy));
    strarrcpy(envcpy, environ);

    // Sort the array alphabetically.
    qsort(envcpy, env_count(), sizeof(char *), cmp);

    if (getenv("FORMAT") != NULL)
        display_env_bwd(envcpy);
    else
        display_env_fwd(envcpy);

    // Free each string in `envcpy`.
    strarrfree(envcpy, env_count());

    // Free array itself.
    free(envcpy);
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

// Free each string in `arr` which is assumed
// to have been dynamically allocated.
void strarrfree(char **arr, size_t len)
{
    while (len-- > 0)
        free(*arr++);
}

void display_env_fwd(char **env)
{
    for (int i = 0; i < env_count(); i++) {

        // Split line into (name, value) across '='.
        char *name = strtok(env[i], "=");
        printf_cyan("%s\n", name);

        // Split value across ':' for PATH variable.
        char *value = strtok(NULL, ":");
        char *next;
        do {
            next = strtok(NULL, ":");
            printf("%s", (next) ? Tee : Ell);
            printf_yellow("%s\n", value);
            value = next;
        } while (next);

        printf("\n");
    }
}

void display_env_bwd(char **env)
{
    for (size_t i = 0; i < env_count(); i++) {
        char *name = strtok(env[i], "=");
        char *value = strtok(NULL, "=");

        printf_yellow("%s\n", value);
        printf("%s", Ell);
        printf_cyan("%s\n\n", name);
    }
}


