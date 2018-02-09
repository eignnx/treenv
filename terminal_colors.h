#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define printf_color(color, ...) \
do {                             \
    printf(color);               \
    printf(__VA_ARGS__);         \
    printf(ANSI_COLOR_RESET);    \
} while (0)

#define printf_red(...)     printf_color(ANSI_COLOR_RED,     __VA_ARGS__)
#define printf_green(...)   printf_color(ANSI_COLOR_GREEN,   __VA_ARGS__)
#define printf_yellow(...)  printf_color(ANSI_COLOR_YELLOW,  __VA_ARGS__)
#define printf_blue(...)    printf_color(ANSI_COLOR_BLUE,    __VA_ARGS__)
#define printf_magenta(...) printf_color(ANSI_COLOR_MAGENTA, __VA_ARGS__)
#define printf_cyan(...)    printf_color(ANSI_COLOR_CYAN,    __VA_ARGS__)
