/*******************************************************************************************************
Copyright (c) 2011 Regents of the University of California.
All rights reserved.

This software was developed at the University of California, Irvine.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in
   the documentation and/or other materials provided with the
   distribution.

3. All advertising materials mentioning features or use of this
   software must display the following acknowledgment:
   "This product includes software developed at the University of
   California, Irvine by Nicolas Oros, Ph.D.
   (http://www.cogsci.uci.edu/~noros/)."

4. The name of the University may not be used to endorse or promote
   products derived from this software without specific prior written
   permission.

5. Redistributions of any form whatsoever must retain the following
   acknowledgment:
   "This product includes software developed at the University of
   California, Irvine by Nicolas Oros, Ph.D.
   (http://www.cogsci.uci.edu/~noros/)."

THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL THE UNIVERSITY OR THE PROGRAM CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************************************/

#ifndef GRAPHICS_ITEM_H
#define GRAPHICS_ITEM_H

#include <QObject>
#include <QGraphicsObject>
#include <QPainter>
#include <QDebug>

//QGraphicsObject used to display the video feedback (frame) on the gui_server and gui_robot
class Graphic_object : public QGraphicsObject    //used tp be QgraphicsItem
{
  Q_OBJECT

public:
    Graphic_object(bool move, int w_scene, int h_scene, int x, int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
    QPixmap a_pixmap;
    QPixmap android_logo;
    int width, height, old_width, old_height;
    int width_scene, height_scene;
    int x_coord, y_coord;

signals:
    void show_dialog();

public slots:
    void display_image(QImage ima);

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);
};

#endif // GRAPHICS_ITEM_H
