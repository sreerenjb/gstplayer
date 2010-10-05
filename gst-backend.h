/*
 * Copyright (C) 2010 Sreerenj Balachandran
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __GST_BACKEND__
#define __GST_BACKEND__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<gst/gst.h>
#include <gst/interfaces/xoverlay.h>

typedef struct Media {
  GstElement *pipeline;
  GstBus *bus;
  gchar *uri;
}Media;


gboolean backend_init (int *argc, char **argv[]);

gboolean backend_start (gchar *uri);

static gboolean handle_message (GstBus *bus, GstMessage *message , gpointer data);

GstBusSyncReply CreateWindow (GstBus *bus, GstMessage *message, gpointer data);

void backend_play ();
void backend_pause ();
void backend_seek ();

#endif
