#ifndef MYSYSLOG_H
#define MYSYSLOG_H

#ifdef __cplusplus
extern "C" {
#endif

// Уровни логирования
#define MYSYSLOG_DEBUG    0
#define MYSYSLOG_INFO     1
#define MYSYSLOG_WARN     2
#define MYSYSLOG_ERROR    3
#define MYSYSLOG_CRITICAL 4

// Типы драйверов (плагины)
#define MYSYSLOG_DRIVER_TEXT 0
#define MYSYSLOG_DRIVER_JSON 1

// Типы форматов (на будущее)
#define MYSYSLOG_FORMAT_DEFAULT 0
#define MYSYSLOG_FORMAT_EXT    1

// Основная функция логирования
int mysyslog(const char* msg, int level, int driver, int format, const char* path);

#ifdef __cplusplus
}
#endif

#endif // MYSYSLOG_H 