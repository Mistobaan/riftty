#ifndef CHILD_H
#define CHILD_H

#include <sys/termios.h>
#include "std.h"

#ifdef LINUX
#include <pty.h>
#include <sys/types.h>
#include <linux/limits.h>
#include <termios.h>
#include <sys/ioctl.h>
#endif

extern char *home, *cmd;

void child_create(const char *argv[], struct winsize *winp);
void child_poll(void);
void child_kill(bool point_blank);
void child_write(const char *, uint len);
void child_printf(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
void child_send(const char *, uint len);
void child_sendw(const wchar *, uint len);
void child_resize(struct winsize *winp);
bool child_is_alive(void);
bool child_is_parent(void);
mintty_wstring child_conv_path(mintty_wstring);
void child_fork(char *argv[]);

#endif
