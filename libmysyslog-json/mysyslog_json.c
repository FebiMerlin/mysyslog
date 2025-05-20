#include "mysyslog_json.h"
#include <stdio.h>
#include <time.h>

static const char* level_names[] = {"DEBUG", "INFO", "WARN", "ERROR", "CRITICAL"};

int mysyslog_json_log(const char* msg, int level, const char* proc, const char* path) {
    FILE* f = fopen(path, "a");
    if (!f) return -1;
    time_t now = time(NULL);
    if (level < 0 || level > 4) level = 1;
    fprintf(f, "{\"timestamp\":%ld,\"log_level\":\"%s\",\"process\":\"%s\",\"message\":\"%s\"}\n", now, level_names[level], proc, msg);
    fclose(f);
    return 0;
} 