/*
** $Id: xttitle.c,v 1.2 1999/09/27 22:12:28 michaelj Exp $
** xttitle 1.1
**
** Copyright (c) Michael A. Jarvis <michael@jarvis.com>
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
You should have received a copy of the GNU General Public License
along with this program.  If not, see <htp://www.gnu.org/licenses/>.
**************************************************************************
** Sets the title and icon name of an xterm window.
**
** Example:
** alias logs='xttitle SYSLOG  && tail -f /var/log/syslog'
**
*/
#include <stdio.h>
#include <stdlib.h>

#define FORMAT "\033]2;%s\007\033\\\033[1A\n\033]1;%s\007\033\\\033[1A\n\033]21;%s\033\\\033[1A\n\033]2L;%s\033\\\033[1A\n"

static void usage( const char *prog );

int main( int argc, char *argv[] )
{
    char *title = NULL; /* Used to set the title of the window */
    char *icon  = NULL; /* Used to set the icon name */

    switch ( argc ) {
        case 1:
            usage(argv[0]);
            exit(1);
            break;      /*  Never reached */

        case 2:
            /*  If there was just one parameter, set icon to same as title.   */
            title = argv[1];
            icon  = argv[1];
            break;

        case 3:
            /*  They passed both window title AND icon name */
            title = argv[1];
            icon  = argv[2];
            break;

        default:
            usage(argv[0]);
            exit(1);
            break;      /*  Never reached */
    }

    printf( FORMAT, title, icon, title, icon );

    exit(0);
}

static void usage( const char *prog )
{
    printf("Usage:  %s <window title> [ <icon title> ]\n", prog );
}

