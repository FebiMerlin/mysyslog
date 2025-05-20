#include "mysyslog.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

static const char* level_names[] = {"DEBUG", "INFO", "WARN", "ERROR", "CRITICAL"};

typedef int (*driver_log_func)(const char*, int, const char*, const char*);

int mysyslog(const char* msg, int level, int driver, int format, const char* path) {
#ifdef _WIN32
    const char* dll_name = NULL;
    const char* proc_name = NULL;
    if (driver == MYSYSLOG_DRIVER_TEXT) {
        dll_name = "../libmysyslog-text/mysyslog_text.dll";
        proc_name = "mysyslog_text_log";
    } else if (driver == MYSYSLOG_DRIVER_JSON) {
        dll_name = "../libmysyslog-json/mysyslog_json.dll";
        proc_name = "mysyslog_json_log";
    } else {
        return -2;
    }
    HMODULE hmod = LoadLibraryA(dll_name);
    if (!hmod) return -3;
    driver_log_func logfunc = (driver_log_func)GetProcAddress(hmod, proc_name);
    if (!logfunc) {
        FreeLibrary(hmod);
        return -4;
    }
    char proc[64] = "example-app"; // TODO: получить имя процесса
    int res = logfunc(msg, level, proc, path);
    FreeLibrary(hmod);
    return res;
#else
    // Для Linux: реализовать через dlopen/dlsym
    return -10;
#endif
} 