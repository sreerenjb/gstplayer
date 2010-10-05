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

#ifndef __GST_FRONTEND__
#define __GST_FRONTEND__

#include <gdk/gdkx.h>
#include <gtk/gtk.h>
#include <glib.h>

typedef struct Player {
  GtkWidget *app_window;
  GtkWidget *video_window;
  GtkWidget *pause_button;
  GtkWidget *play_button;
  GtkWidget *table;
}Player;

gboolean frontend_init (int *argc, char **argv[]);
gboolean frontend_start ();
static void video_widget_realize_cb (GtkWidget * widget, gpointer data);
static void frontend_play (GtkWidget *widget, gpointer data);
static void frontend_pause (GtkWidget *widget, gpointer data);

#endif
