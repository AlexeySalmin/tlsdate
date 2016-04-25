/*
 * base64.h - routine to encode data using BASE64
 * Copyright (c) 2016 Alexey Salmin
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef BASE64_H
#define BASE64_H
/*
 * Encodes first insize bytes from the binary buffer inbuf using base64. Result
 * is stored as a null-terminated string in the *outstr. Memory for *outstr is
 * allocated by the routine, the caller should free it using free(). 
 * Return value is the length of the resulting string.
 */
size_t base64_encode(const char *inbuf, size_t insize, char **outstr);

#endif /* !BASE64_H */
