/*
 * Copyright (C) 2010 Sreerenj Balachandran.
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

#include "gst-frontend.h"
#include "gst-backend.h"
#include "globals.h"

int main(int argc, char *argv[])
{
 
  gchar *uri = NULL;

  if (!frontend_init (&argc, &argv)) {
     g_message ("Frontend initialization failure...."); 
     exit (0);
  }

  if (!backend_init (&argc, &argv)) {
    g_message (" Backend creation failure");
    exit (0);
  }
 
  if (argc > 1) {
    if (g_strrstr (argv[1],"rtsp://") || g_strrstr (argv[1],"http://") || g_strrstr (argv[1],"file://"))
      uri = g_strdup (argv[1]);
    else
      uri = g_strdup_printf ("file://%s", argv[1]);
  }
  else {
    g_message ("Specify the media file name..<gstplayer filename>");
    return 0;
  }

  if (!frontend_start ()) {  
     g_message ("Player UI creation failure...."); 
     exit (0);
  }
  if (!backend_start (uri)) {  
    g_message ("Gstreamer backend creation failure");
    exit (0);
  }

  loop = g_main_loop_new (NULL, FALSE);
  g_main_loop_run (loop);

  backend_stop ();

}
