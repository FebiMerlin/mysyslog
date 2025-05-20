#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <windows.h>
#include "../libmysyslog/mysyslog.h"

volatile int running = 1;

BOOL WINAPI console_handler(DWORD signal) {
    if (signal == CTRL_C_EVENT) {
        running = 0;
    }
    return TRUE;
}

typedef struct {
    char path[256];
    int driver;
    int format;
} config_t;

int read_config(const char* cfg_path, config_t* cfg) {
    FILE* f = fopen(cfg_path, "r");
    if (!f) return -1;
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        if (strncmp(line, "path=", 5) == 0) {
            strncpy(cfg->path, line+5, sizeof(cfg->path)-1);
            cfg->path[strcspn(cfg->path, "\r\n")] = 0;
        } else if (strncmp(line, "driver=", 7) == 0) {
            cfg->driver = atoi(line+7);
        } else if (strncmp(line, "format=", 7) == 0) {
            cfg->format = atoi(line+7);
        }
    }
    fclose(f);
    return 0;
}

int main(int argc, char* argv[]) {
    config_t cfg = {"mysyslog_daemon.log", 0, 0};
    if (argc > 1) {
        if (read_config(argv[1], &cfg) != 0) {
            printf("Не удалось прочитать конфиг %s\n", argv[1]);
            return 1;
        }
    }
    SetConsoleCtrlHandler(console_handler, TRUE);
    int count = 0;
    while (running) {
        char msg[128];
        int level = count % 5;
        snprintf(msg, sizeof(msg), "daemon message #%d", count+1);
        mysyslog(msg, level, cfg.driver, cfg.format, cfg.path);
        printf("[mysyslog-daemon] %s\n", msg);
        Sleep(2000);
        count++;
    }
    printf("Демон завершён.\n");
    return 0;
} 