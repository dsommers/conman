/*****************************************************************************\
 *  $Id: util-str.h,v 1.6 2002/03/14 03:37:00 dun Exp $
 *****************************************************************************
 *  Copyright (C) 2001-2002 The Regents of the University of California.
 *  Written by Chris Dunlap <cdunlap@llnl.gov>.
 *  UCRL-CODE-2002-009.
 *  
 *  This file is part of ConMan, a remote console management program.
 *  For details, see <http://www.llnl.gov/linux/conman.html>.
 *  
 *  ConMan was produced at the University of California, Lawrence Livermore
 *  National Laboratory (UC LLNL) under contract no. W-7405-ENG-48
 *  (Contract 48) between the U.S. Department of Energy (DOE) and The Regents
 *  of the University of California (University) for the operation of UC LLNL.
 *  The rights of the Federal Government are reserved under Contract 48
 *  subject to the restrictions agreed upon by the DOE and University as
 *  allowed under DOE Acquisition Letter 97-1.
 *  
 *  ConMan is free software; you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *  
 *  ConMan is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *  details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with ConMan; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
\*****************************************************************************/


#ifndef _UTIL_STR_H
#define _UTIL_STR_H


#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif /* HAVE_CONFIG_H */

#include <time.h>
#include <unistd.h>


char * create_string(const char *str);
/*
 *  Duplicates string (str) and returns a new string
 *    (or throws a fatal error if insufficient memory is available).
 *  Note that the caller is responsible for freeing this string.
 */

char * create_format_string(const char *fmt, ...);
/*
 *  Creates and returns a new string specified by the format-string (fmt)
 *    (or throws a fatal error if insufficient memory is available).
 *  Note that the caller is responsible for freeing this string.
 */

void destroy_string(char *str);
/*
 *  Destroys the string (str).
 */

size_t append_format_string(char *dst, size_t size, const char *fmt, ...);
/*
 *  Appends the string specified by the format-string (fmt) to a
 *    NUL-terminated string (dst) within a buffer of size (size).
 *  Note that (size) is the full size of (dst), not the space remaining.
 *  Returns the new length of the NUL-terminated string (dst),
 *    or -1 if truncation occurred.
 */

int substitute_string(char *dst, size_t dstlen, const char *src,
    char c, char *sub);
/*
 *  Copies the (src) string into the (dst) buffer of size (dstlen),
 *    substituting all occurrences of char (c) with the string (sub).
 *  Returns the length of the resulting string in (dst),
 *    or -1 if truncation occurred.
 *  Always NUL terminates the dst string (unless dstlen == 0).
 */

char * create_long_time_string(time_t t);
/*
 *  Creates and returns a new string with the specified date & time
 *    in the format "MM/DD/YYYY HH:MM:SS ZONE" in a thread-safe manner
 *    (or throws a fatal error if something strange happens).
 *  If no time is given (t=0), the current date & time is used.
 *  Note that the caller is responsible for freeing this string.
 */

char * create_short_time_string(time_t t);
/*
 *  Creates and returns a new string with the specified
 *    time in the format "HH:MM" in a thread-safe manner
 *    (or throws a fatal error if something strange happens).
 *  If no time is given (t=0), the current time is used.
 *  Note that the caller is responsible for freeing this string.
 */

char * create_time_delta_string(time_t t);
/*
 *  Creates and returns a new string indicating the time delta
 *    between time (t) and the current time.
 *  The difference is broken-down into years, weeks, days, hours,
 *    minutes, and seconds.
 *  Note that the caller is responsible for freeing this string.
 */

struct tm * get_localtime(time_t *tPtr, struct tm *tmPtr);
/*
 *  Gets the local time in a thread-safe manner.
 *  The time struct (*tmPtr) is filled-in with the local time based on (*tPtr);
 *    if (*tPtr == 0), it is set with the current time.
 *  Returns the ptr to the time struct arg (tmPtr).
 */

#ifndef HAVE_STRCASECMP
int strcasecmp(const char *s1, const char *s2);
/*
 *  Compares the two strings 's1' and 's2', ignoring the case of the chars.
 *  Returns less-than-zero if (s1 < s2), zero if (s1 == s2), and
 *    greater-than-zero if (s1 > s2).
 */
#endif /* !HAVE_STRCASECMP */

#ifndef HAVE_STRLCAT
size_t strlcat(char *dst, const char *src, size_t siz);
/*
 *  Appends src to string dst of size siz (unlike strncat, siz is the
 *    full size of dst, not space left).  At most siz-1 characters
 *    will be copied.  Always NUL terminates (unless siz == 0).
 *  Returns strlen(src); if retval >= siz, truncation occurred.
 */
#endif /* !HAVE_STRLCAT */

#ifndef HAVE_STRLCPY
size_t strlcpy(char *dst, const char *src, size_t siz);
/*
 *  Copy src to string dst of size siz.  At most siz-1 characters
 *    will be copied.  Always NUL terminates (unless siz == 0).
 *  Returns strlen(src); if retval >= siz, truncation occurred.
 */
#endif /* !HAVE_STRLCPY */


#endif /* !_UTIL_STR_H */
