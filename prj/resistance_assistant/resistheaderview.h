#ifndef RESISTHEADERVIEW_H
#define RESISTHEADERVIEW_H

#include <QHeaderView>

class ResistHeaderView : public QHeaderView
{
public:
    ResistHeaderView();

    void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const;
    QSize sectionSizeFromContents ( int logicalIndex ) const  ;

    int sectionSizeHint ( int logicalIndex ) const;

   QSize sizeHint () const;
};

#endif // RESISTHEADERVIEW_H
