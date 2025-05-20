#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libmysyslog/mysyslog.h"

void print_usage() {
    printf("Использование: mysyslog-client -m <message> -l <level> -d <driver> -f <format> -p <path>\n");
    printf("  -m <message>   Сообщение для записи в лог\n");
    printf("  -l <level>     Уровень логирования (0-DEBUG, 1-INFO, 2-WARN, 3-ERROR, 4-CRITICAL)\n");
    printf("  -d <driver>    Драйвер (0-text, 1-json)\n");
    printf("  -f <format>    Формат (0-default)\n");
    printf("  -p <path>      Путь к файлу лога\n");
}

int main(int argc, char* argv[]) {
    const char* msg = NULL;
    int level = 1;
    int driver = 0;
    int format = 0;
    const char* path = "mysyslog.log";

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-m") == 0 && i+1 < argc) { msg = argv[++i]; }
        else if (strcmp(argv[i], "-l") == 0 && i+1 < argc) { level = atoi(argv[++i]); }
        else if (strcmp(argv[i], "-d") == 0 && i+1 < argc) { driver = atoi(argv[++i]); }
        else if (strcmp(argv[i], "-f") == 0 && i+1 < argc) { format = atoi(argv[++i]); }
        else if (strcmp(argv[i], "-p") == 0 && i+1 < argc) { path = argv[++i]; }
        else if (strcmp(argv[i], "-h") == 0) { print_usage(); return 0; }
    }
    if (!msg) {
        print_usage();
        return 1;
    }
    int res = mysyslog(msg, level, driver, format, path);
    if (res != 0) {
        printf("Ошибка логирования: %d\n", res);
        return 2;
    }
    printf("Сообщение успешно записано в лог.\n");
    return 0;
} 