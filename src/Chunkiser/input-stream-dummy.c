/*
 *  Copyright (c) 2010 Luca Abeni
 *
 *  This is free software; see gpl-3.0.txt
 */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "chunkiser_iface.h"

struct input_stream {
  char buff[80];
};

static struct input_stream *open(const char *fname, int *period, const char *config)
{
  fprintf(stderr, "WARNING: This is a dummy chunkiser, only good for debugging! Do not expect anything good from it!\n");
  *period = 40000;
  return malloc(sizeof(struct input_stream));
}

static void close(struct input_stream *s)
{
  free(s);
}

static uint8_t *chunkise(struct input_stream *s, int id, int *size, uint64_t *ts)
{
  sprintf(s->buff, "Chunk %d", id);
  *ts = 40 * id * 1000;
  *size = strlen(s->buff);

  return strdup(s->buff);
}

struct chunkiser_iface in_dummy = {
  .open = open,
  .close = close,
  .chunkise = chunkise,
};
