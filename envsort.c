#include <stdio.h>
#include <stdbool.h>    // bool
#include <stdlib.h>     // malloc
#include <string.h>     // strdup

extern const char **environ;
static bool _env_count_called = false;
static size_t _env_count = 0;

size_t env_count();
void strarrcpy(char **dest, const char **src);

int main()
{
    printf("There are %zu environment variables defined.", env_count());

    char **envcpy = malloc(env_count() * sizeof(*envcpy));
    strarrcpy(envcpy, environ);

    for (int i = 0; envcpy[i] != NULL; i++)
        printf("%s\n", envcpy[i]);

    // Free each string in `envcpy`.
    for (char *p = envcpy; p != NULL; p++)
        free(p);

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
