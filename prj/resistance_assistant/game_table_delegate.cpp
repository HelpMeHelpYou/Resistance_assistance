#include "game_table_delegate.h"
#include <QPainter>
#include <math.h>
#include "game.h"

game_table_delegate::game_table_delegate()
{
}


void paint_disagreed ( QPainter * painter, const QRect & rect, const QPalette & palette)
{
    double scale_factor = rect.height()/2.5;

    painter->save();

    painter->setRenderHint(QPainter::Antialiasing, true);

    QPolygonF denied;

    QColor  color (255,0,0,100);

    denied << QPointF(scale_factor*0.8,scale_factor*0.6)
           << QPointF (scale_factor*0.6,0.8*scale_factor)
           << QPoint (-0.8*scale_factor,-0.6*scale_factor)
           << QPoint(-0.6*scale_factor,-0.8 *scale_factor)
           << QPoint (0.8*scale_factor,0.6*scale_factor);

    painter ->translate(rect.center());

    QPen pen = painter->pen();
    pen.setColor(color);
    painter->setPen(pen);

    for (int i  = 0; i < 0.3 *scale_factor ;i++)
    painter->drawEllipse(QPointF(0,0),1*scale_factor - i  ,1*scale_factor -i);



     QBrush brush = painter->brush();



     brush.setStyle(Qt::SolidPattern);

     brush.setColor(color);
     painter->setBrush(brush);



    painter->drawPolygon(denied,Qt::WindingFill);


    painter->restore();

}

void paint_agreed ( QPainter * painter, const QRect & rect, const QPalette & palette)
{
    double scale_factor = rect.height()/2.5;

    painter->save();
    painter->setRenderHint(QPainter::Antialiasing, true);

    QPolygonF denied;

    denied << QPointF(scale_factor*0.8,scale_factor*0.6)
           << QPointF (scale_factor*0.6,0.8*scale_factor)
           << QPoint (-0.8*scale_factor,-0.6*scale_factor)
           << QPoint(-0.6*scale_factor,-0.8 *scale_factor)
           << QPoint (0.8*scale_factor,0.6*scale_factor);

    painter ->translate(rect.center());

    QPen pen = painter->pen();
    pen.setColor(QColor(255,255,255,100));
    painter->setPen(pen);

    for (int i  = 0; i < 0.3 *scale_factor ;i++)
    painter->drawEllipse(QPointF(0,0),1*scale_factor - i  ,1*scale_factor -i);


    for (int i  = 0.7*scale_factor; i < 1 *scale_factor ;i++)
    painter->drawEllipse(QPointF(0,0),1*scale_factor - i  ,1*scale_factor -i);



    painter->restore();

}

void paint_leader ( QPainter * painter, const QRect & rect, const QPalette & palette)
{
     QColor  color (0,0,255,100);
    QColor  color2 (0,0,255,200);

    QPolygonF starPolygon;
    QPolygonF rombPolygon;

    double scale_factor = rect.height()/2.5;



    painter->save();

    painter ->translate(rect.center());
    painter->scale(scale_factor,scale_factor);
    painter->setRenderHint(QPainter::Antialiasing, true);


    QPen pen = painter->pen();
    pen.setColor(color2);
    painter->setPen(pen);

    rombPolygon << QPointF (1 , 0) <<QPointF (0 , 1.5) << QPointF (-1 , 0) << QPointF (0 ,-1.5)
                << QPointF (1 , 0);

    painter->drawPolygon(rombPolygon,Qt::WindingFill);




    painter->setPen(Qt::NoPen);

    QBrush brush = painter->brush();
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    painter->setBrush(brush);

    for (int i = 1; i < 7; ++i)
        starPolygon << QPointF(0 + 1 * cos((0.8 * (i+0.375) * 3.14)),
                               0 + 1 * sin((0.8 * (i+0.375) * 3.14) ));




    painter->drawPolygon(starPolygon,Qt::WindingFill);



    painter->restore();

}

void paint_complited (QPainter * painter, const QRect & rect, const QPalette & palette)
{
    painter->save();

    painter->restore();

}

void paint_nominated (QPainter * painter, const QRect & rect, const QPalette & palette)

{

    painter->save();

    painter->setRenderHint(QPainter::Antialiasing, true);

    double scale_factor = rect.height()/2.5;


    QColor  color (128,64,64,100);
   QColor  color2 (128,64,64,200);

   painter ->translate(rect.center());

   QPen pen = painter->pen();
   pen.setColor(color);
   painter->setPen(pen);

   for (int i  = 0; i < 0.3 *scale_factor ;i++)
   painter->drawEllipse(QPointF(0,0),1*scale_factor - i  ,1*scale_factor -i);


   for (int i  = 0.7*scale_factor; i < 1 *scale_factor ;i++)
   painter->drawEllipse(QPointF(0,0),1*scale_factor - i  ,1*scale_factor -i);


   painter->restore();


}

void paint_agreement_mood (QPainter * painter, const QRect & rect, const QPalette & palette)
{

    painter->save();


    QColor  color (250,250,250,50);

    QBrush brush;


    brush.setStyle(Qt::SolidPattern);

    brush.setColor(color);
    painter->setBrush(brush);

    painter->fillRect(rect,brush);

    painter->restore();
}


void paint_disagreement_mood (QPainter * painter, const QRect & rect, const QPalette & palette)
{

    painter->save();


    QColor  color (50,50,50,50);

    QBrush brush;


    brush.setStyle(Qt::SolidPattern);

    brush.setColor(color);
    painter->setBrush(brush);

    painter->fillRect(rect,brush);

    painter->restore();
}


void paint_failed_mood (QPainter * painter, const QRect & rect, const QPalette & palette)
{

    painter->save();


    QColor  color (150,50,50,50);

    QBrush brush;


    brush.setStyle(Qt::SolidPattern);

    brush.setColor(color);
    painter->setBrush(brush);

    painter->fillRect(rect,brush);

    painter->restore();
}

void paint_succes_mood (QPainter * painter, const QRect & rect, const QPalette & palette)
{

    painter->save();


    QColor  color (50,50,150,50);

    QBrush brush;


    brush.setStyle(Qt::SolidPattern);

    brush.setColor(color);
    painter->setBrush(brush);

    painter->fillRect(rect,brush);

    painter->restore();
}






void paint_stats(QPainter * painter, const QRect & rect, const QPalette & palette, int total, int fail)
{

    painter->save();


    QColor  color (10,10,10,50);

    QString str = QString("%1/%2").arg(fail).arg(total);

    painter->drawText(rect,str);

    painter->restore();
}



void paint2(QPainter *painter, const QRect &rect,
                       const QPalette &palette, int mode)
{
    QPolygonF starPolygon;
        QPolygonF diamondPolygon;

       // starPolygon << QPointF(1.0, 0.5);
        for (int i = 1; i < 7; ++i)
            starPolygon << QPointF(0.5 + 0.5 * cos((0.8 * (i+0.375) * 3.14)),
                                   0.5 + 0.5 * sin((0.8 * (i+0.375) * 3.14) ));

        diamondPolygon << QPointF(0.4, 0.5) << QPointF(0.5, 0.4)
                       << QPointF(0.6, 0.5) << QPointF(0.5, 0.6)
                       << QPointF(0.4, 0.5);



    painter->save();

    painter->setRenderHint(QPainter::Antialiasing, true);
  //  painter->setPen(Qt::NoPen);

    if (mode == 1) {
        painter->setBrush(palette.highlight());
    } else {
        painter->setBrush(palette.foreground());
    }

    int yOffset = (rect.height() - 20) / 2;
    painter->translate(rect.x(), rect.y() + yOffset);
    painter->scale(20, 20);

    for (int i = 0; i < 4; ++i) {
        if (i < 2) {
            painter->drawPolygon(starPolygon, Qt::WindingFill);
        } else if (mode == 1) {
            painter->drawPolygon(diamondPolygon, Qt::WindingFill);
        }
        painter->translate(1.0, 0.0);
    }

    painter->restore();
}



void game_table_delegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  //  if (option.state & QStyle::State_Selected)



    if(index.data().type() == QVariant::UInt)


    {

        if ((index.data().toUInt() & 0xf0) == pic(agreed_mood) )
            paint_agreement_mood(painter, option.rect, option.palette);


        if ((index.data().toUInt() & 0xf0) == pic(disagreed_mood) )
            paint_disagreement_mood(painter, option.rect, option.palette);

        if ((index.data().toUInt() & 0xf0) == pic(success_mood) )
            paint_succes_mood(painter, option.rect, option.palette);


        if ((index.data().toUInt() & 0xf0) == pic(failed_mood) )
            paint_failed_mood(painter, option.rect, option.palette);


    if ((index.data().toUInt() & 0xf) ==  pic(leader))
        paint_leader(painter, option.rect, option.palette);


   if((index.data().toUInt() & 0xf) == pic(agreed))
        paint_agreed(painter, option.rect, option.palette);

    if ((index.data().toUInt() & 0xf) == pic(disagreed) )
        paint_disagreed(painter, option.rect, option.palette);

    if ((index.data().toUInt() & 0xf) == pic(nominated) )
        paint_nominated(painter, option.rect, option.palette);

    if (((index.data().toUInt() & 0xf) == pic( win_participant )) ||
            ((index.data().toUInt() & 0xf) == pic( lose_participant )))
        paint_stats (painter,option.rect,option.palette,(0xf00 &index.data().toUInt()) >> 8 ,(0x0f000&index.data().toUInt())>>12  );

    }

}


  QSize game_table_delegate::sizeHint(const QStyleOptionViewItem &option,const QModelIndex &index) const
  {
      return QSize(15,15);

  }
