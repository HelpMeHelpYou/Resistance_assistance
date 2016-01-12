#include "resistheaderview.h"
#include <QPainter>

ResistHeaderView::ResistHeaderView() : QHeaderView(Qt::Horizontal)
{
    this->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
}

void ResistHeaderView::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
{
    painter->save();

   QPoint point = rect.topRight();
  //  point.operator -=(QPoint(0,rect.width()*logicalIndex));
    painter->translate(point);

    painter->rotate(90);

    QRect rect2 (0,0,rect.height(),rect.width());

    QHeaderView::paintSection(painter,rect2, logicalIndex);

    painter->restore();

}

QSize ResistHeaderView::sizeHint() const
{

    QSize sz;// = QHeaderView::sizeHint();

   qWarning ("sizeHint is called width is %d, height is %d",sz.width(),sz.height());

   sz.setWidth(15);

   sz.setHeight(60);



    qWarning ("sizeHint return width is %d, height is %d",sz.width(),sz.height());

    return sz;
}


QSize ResistHeaderView::sectionSizeFromContents ( int logicalIndex ) const
{
    QSize sz = QHeaderView::sectionSizeFromContents(logicalIndex);
   // qWarning ("SectionSizeFromContent is called width is %d, height is %d",sz.width(),sz.height());

    sz.transpose();

   // qWarning ("SectionSizeFromContent return width is %d, height is %d",sz.width(),sz.height());
    return sz;
}

int ResistHeaderView::sectionSizeHint ( int logicalIndex ) const
{
     QHeaderView::sectionSizeHint ( logicalIndex );

    return 15;
}


