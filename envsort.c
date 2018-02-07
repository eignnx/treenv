#include <stdio.h>
#include <stdbool.h>     // bool

extern char **environ;
static bool _env_count_called = false;
static size_t _env_count = 0;

size_t env_count();

int main()
{
    
    printf("There are %zu environment variables defined.", env_count());
}

size_t env_count()
{
    if (!_env_count_called) {
        _env_count_called = true;
        for (char **envp = environ; *envp; envp++, _env_count++);
    }
    return _env_count;
}
