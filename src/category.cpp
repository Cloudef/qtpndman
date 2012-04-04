#include "category.h"

QPndman::Category::Category(pndman_category const* p, QObject* parent) :
  QObject(parent), main(QString::fromUtf8(p->main)), sub(QString::fromUtf8(p->sub))
{
}

QString QPndman::Category::getMain() const
{
  return main;
}
QString QPndman::Category::getSub() const
{
  return sub;
}

