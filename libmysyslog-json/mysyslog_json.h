#ifndef MYSYSLOG_JSON_H
#define MYSYSLOG_JSON_H

#ifdef __cplusplus
extern "C" {
#endif

int mysyslog_json_log(const char* msg, int level, const char* proc, const char* path);

#ifdef __cplusplus
}
#endif

#endif // MYSYSLOG_JSON_H 