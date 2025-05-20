#ifndef MYSYSLOG_TEXT_H
#define MYSYSLOG_TEXT_H

#ifdef __cplusplus
extern "C" {
#endif

int mysyslog_text_log(const char* msg, int level, const char* proc, const char* path);

#ifdef __cplusplus
}
#endif

#endif // MYSYSLOG_TEXT_H 