/*
 * proxy-bio.h - BIO layer for transparent proxy connections
 *
 * Copyright (c) 2012 The Chromium Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef PROXY_BIO_H
#define PROXY_BIO_H

#include <stdint.h>

#include <openssl/bio.h>

#include "util.h"

struct proxy_ctx {
  char *host;
  uint16_t port;
  char *userpass;
  int connected;
  int (*connect)(BIO *b);
};

BIO *BIO_new_proxy();

/* These do not take ownership of their string arguments. */
int BIO_proxy_set_type (BIO *b, const char *type);
int BIO_proxy_set_host (BIO *b, const char *host);
void BIO_proxy_set_port (BIO *b, uint16_t port);
void BIO_proxy_set_userpass (BIO *b, const char *userpass);

#endif /* !PROXY_BIO_H */
