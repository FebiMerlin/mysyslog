#include "mysyslog_text.h"
#include <stdio.h>
#include <time.h>

static const char* level_names[] = {"DEBUG", "INFO", "WARN", "ERROR", "CRITICAL"};

int mysyslog_text_log(const char* msg, int level, const char* proc, const char* path) {
    FILE* f = fopen(path, "a");
    if (!f) return -1;
    time_t now = time(NULL);
    if (level < 0 || level > 4) level = 1;
    fprintf(f, "%ld %s %s %s\n", now, level_names[level], proc, msg);
    fclose(f);
    return 0;
} 