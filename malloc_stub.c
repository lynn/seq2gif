/*
 * Copyright (c) 2014 Hayaki Saito
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "config.h"

#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif  /* HAVE_SYS_TYPES_H */

#if HAVE_ERRNO_H
#include <errno.h>
#endif  /* HAVE_ERRNO_H */

#include <stdlib.h>

#if HAVE_MEMORY_H
#include <memory.h>
#endif  /* HAVE_MEMORY_H */

#if !HAVE_MALLOC
#undef malloc
void *
rpl_malloc(size_t n)
{
    if(n == 0) {
        n = 1;
    }
    return (void *)malloc(n);
}
#endif /* !HAVE_MALLOC */

#if !HAVE_REALLOC
#undef realloc
void *
rpl_realloc(void *p, size_t n)
{
    if (n == 0) {
        n = 1;
    }
    if (p == 0) {
        return malloc(n);
    }
    return (void *)realloc(p, n);
}
#endif /* !HAVE_REALLOC */

#if 0
int
rpl_posix_memalign(void **memptr, size_t alignment, size_t size)
{
#if HAVE_POSIX_MEMALIGN
    return posix_memalign(memptr, alignment, size);
#elif HAVE_ALIGNED_ALLOC
    *memptr = aligned_alloc(alignment, size);
    return *memptr ? 0: ENOMEM;
#elif HAVE_MEMALIGN
    *memptr = memalign(alignment, size);
    return *memptr ? 0: ENOMEM;
#elif HAVE__ALIGNED_MALLOC
    return _aligned_malloc(size, alignment);
#else
# error
#endif /* _MSC_VER */
}
#endif

/* Hello emacs, -*- Mode: C; tab-width: 4; indent-tabs-mode: nil -*- */
/* vim: set expandtab ts=4 : */
/* EOF */