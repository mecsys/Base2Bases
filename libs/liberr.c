/*
 * liberr.c - Implement the error-handling library
 */
#include <errno.h>  /* for definition of errno */
#include <stdarg.h> /* for the vararg declarations */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "liberr.h" /* our own header */

void err_ret(const char *fmt, ...)
{
        va_list ap;

        va_start(ap, fmt);
        err_prn(fmt, ap, NULL);
        va_end(ap);
        return;
}

void err_quit(const char *fmt, ...)
{
        va_list ap;

        va_start(ap, fmt);
        err_prn(fmt, ap, NULL);
        va_end(ap);
        exit(1);
}

void log_ret(char *logfile, const char *fmt, ...)
{
        va_list ap;

        va_start(ap, fmt);
        err_prn(fmt, ap, logfile);
        va_end(ap);
        return;
}

void log_quit(char *logfile, const char *fmt, ...)
{
        va_list ap;

        va_start(ap, fmt);
        err_prn(fmt, ap, logfile);
        va_end(ap);
        exit(1);
}

extern void err_prn(const char *fmt, va_list ap, char *logfile)
{
        int save_err;
        char buf[MAXLINELEN];
        FILE *plf;

        save_err = errno; /* value caller might want printed */
        vsprintf(buf, fmt, ap);
        sprintf(buf + strlen(buf), ": %s\n", strerror(save_err));
        fflush(stdout);
        if(logfile != NULL) 
                if((plf = fopen(logfile, "a")) != NULL) {
                        fputs(buf, plf);
                        fclose(plf);
                } else
                        fputs("failed to open log file\n", stderr);
        else
                fputs(buf, stderr);
        fflush(NULL); /* flush everything */
        return;
}
