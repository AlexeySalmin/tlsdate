/*
 * base64.c - routine to encode data using BASE64. Implemented as a simple
 * wrapper over the OpenSSL base64 BIO filter.
 * Copyright (c) 2016 Alexey Salmin
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
*/

#include <openssl/bio.h>
#include <openssl/evp.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "src/base64.h"

size_t
base64_encode(const char *inbuf, size_t insize, char **outstr) {
  BIO *bio_mem, *bio_b64;
  char *outbuf;
  size_t outsize;

  bio_mem = BIO_new(BIO_s_mem());
  bio_b64 = BIO_new(BIO_f_base64());
  BIO_push(bio_b64, bio_mem);	

  BIO_set_flags(bio_b64, BIO_FLAGS_BASE64_NO_NL);
  BIO_write(bio_b64, inbuf, insize);
  BIO_flush(bio_b64);

  outsize = BIO_get_mem_data(bio_mem, &outbuf);
  *outstr = malloc(outsize + 1);
  memcpy(*outstr, outbuf, outsize);
  (*outstr)[outsize] = '\0';

  BIO_free_all(bio_b64);
  return outsize;
}
