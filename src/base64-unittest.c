/*
 * base64-unittest.c - unit tests for base64.c
 * Copyright (c) 2016 Alexey Salmin
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
*/
#include "config.h"

#include "src/test_harness.h"
#include "src/base64.h"

#include <openssl/bio.h>
#include <openssl/evp.h>
#include <stdlib.h>
#include <string.h>

static const char *input[] = {
  "H",
  "Hello",
  "Hello, world!",
};

static const char *reference_output[] = {
  "SA==",
  "SGVsbG8=",
  "SGVsbG8sIHdvcmxkIQ==",
};

TEST(standalone_test) {
  int i, count;
  count = sizeof(input) / sizeof(*input);
  for (i = 0; i < count; i++) {
    size_t outlen;
    char *outstr;
    outlen = base64_encode(input[i], strlen(input[i]), &outstr);
    ASSERT_EQ(outlen, strlen(reference_output[i]));
    ASSERT_STREQ(outstr, reference_output[i]);
    free(outstr);
  }
}

TEST_HARNESS_MAIN
