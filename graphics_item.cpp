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

#include <QGraphicsSceneMouseEvent>
#include "graphics_item.h"

//QGraphicsObject used to display the video feedback (frame) on the gui_server and gui_robot

Graphic_object::Graphic_object(bool move, int w_scene, int h_scene, int x, int y)
{
    if(move == true)   setFlag(ItemIsMovable);

    width_scene     = w_scene;
    height_scene    = h_scene;
    x_coord         = x;
    y_coord         = y;

    android_logo.load(":/Images/Image_files/android_logo2.jpg");

    width           = width_scene/3;    //set fixed width
    float c         = (float)(width_scene/3) / (float)android_logo.width();   //scale height to width
    height          = (int)(android_logo.height() * c);

    old_width       = width;
    old_height      = height;
}

QRectF Graphic_object::boundingRect() const
{
    return QRectF(0,0,width,height);
}

void Graphic_object::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(a_pixmap.isNull()==true) a_pixmap = android_logo.scaled(width,height);

    float c         = (float)(width_scene/3) / (float)a_pixmap.width();   //scale height to width
    height          = (int)(a_pixmap.height() * c);

    if(height != old_height)  //clear old image
    {
        painter->eraseRect(QRectF(0,0,old_width,old_height));
        old_height = height;
    }

    QRectF rec = boundingRect();
    painter->drawPixmap(rec,a_pixmap, a_pixmap.rect());
//    setPos(x_coord, y_coord);
}

void Graphic_object::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event)
{
    QGraphicsItem::mouseDoubleClickEvent(event);
    update();

    if(event->button() == Qt::LeftButton)
        emit show_dialog();
}

void Graphic_object::display_image(QImage ima)
{
    a_pixmap    = QPixmap::fromImage(ima);
    update();
}
