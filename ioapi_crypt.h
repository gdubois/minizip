/* crypt.h -- base code for traditional PKWARE encryption
   Version 1.2.0, September 16th, 2017

   Copyright (C) 2012-2017 Nathan Moinvaziri
     https://github.com/nmoinvaz/minizip
   Copyright (C) 1998-2005 Gilles Vollant
     Modifications for Info-ZIP crypting
     http://www.winimage.com/zLibDll/minizip.html
   Copyright (C) 2003 Terry Thorsen

   This code is a modified version of crypting code in Info-ZIP distribution

   Copyright (C) 1990-2000 Info-ZIP.  All rights reserved.

   This program is distributed under the terms of the same license as zlib.
   See the accompanying LICENSE file for the full text of the license.
*/

#ifndef _MZSTREAM_CRYPT_H
#define _MZSTREAM_CRYPT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "zlib.h"
#include "ioapi.h"

#ifdef __cplusplus
extern "C" {
#endif

int32_t ZCALLBACK mzstream_crypt_open(voidpf stream, const char* filename, int mode);
int32_t ZCALLBACK mzstream_crypt_read(voidpf stream, void* buf, uint32_t size);
int32_t ZCALLBACK mzstream_crypt_write(voidpf stream, const void* buf, uint32_t size);
int64_t ZCALLBACK mzstream_crypt_tell(voidpf stream);
int32_t ZCALLBACK mzstream_crypt_seek(voidpf stream, uint64_t offset, int origin);
int32_t ZCALLBACK mzstream_crypt_close(voidpf stream);
int32_t ZCALLBACK mzstream_crypt_error(voidpf stream);

void              mzstream_crypt_set_password(voidpf stream, char *password);
void              mzstream_crypt_set_verify(voidpf stream, uint8_t verify1, uint8_t verify2);
void              mzstream_crypt_get_verify(voidpf stream, uint8_t *verify1, uint8_t *verify2);

voidpf            mzstream_crypt_alloc(void);
void              mzstream_crypt_free(voidpf stream);

#ifdef __cplusplus
}
#endif

#endif
