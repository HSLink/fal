#pragma once

#ifndef FAL_DEBUG
#define FAL_DEBUG                      0
#endif

#if FAL_DEBUG
#ifdef assert
#undef assert
#endif
#define assert(EXPR)                                                           \
if (!(EXPR))                                                                   \
{                                                                              \
    FAL_PRINTF("(%s) has assert failed at %s.\n", #EXPR, __FUNCTION__);        \
    while (1);                                                                 \
}

/* debug level log */
#ifdef  log_d
#undef  log_d
#endif
#define log_d(...)                     FAL_PRINTF("[D/FAL] (%s:%d) ", __FUNCTION__, __LINE__);           FAL_PRINTF(__VA_ARGS__);FAL_PRINTF("\n")

#else

#ifdef assert
#undef assert
#endif
#define assert(EXPR)                   ((void)0);

/* debug level log */
#ifdef  log_d
#undef  log_d
#endif
#define log_d(...)
#endif /* FAL_DEBUG */

/* error level log */
#ifdef  log_e
#undef  log_e
#endif
#define log_e(...)                     FAL_PRINTF("\033[31;22m[E/FAL] (%s:%d) ", __FUNCTION__, __LINE__);FAL_PRINTF(__VA_ARGS__);FAL_PRINTF("\033[0m\n")

/* info level log */
#ifdef  log_i
#undef  log_i
#endif
#define log_i(...)                     FAL_PRINTF("\033[32;22m[I/FAL] ");                                FAL_PRINTF(__VA_ARGS__);FAL_PRINTF("\033[0m\n")