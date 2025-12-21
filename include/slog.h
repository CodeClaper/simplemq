#ifndef __SLOG_H__
#define __SLOG_H__

typedef enum LLevel {
    INFO,
    DEBUG,
    SUCCS,
    WARN,
    ERROR,
    PANIC
} LLevel;

static const char* SLOG_LEVEL_NAME_LIST[] = {
    "INFO", "DEBUG", "SUCCS", "WARN", "ERROR", "PANIC"
};

#endif
