#ifndef DITHERFACTORY_H
#define DITHERFACTORY_H
#include "idither.h"
#include "dithermethodid.h"
#include <memory>


class DitherFactory
{
public:
   std::shared_ptr<IDither> getMethod(DitherMethodId MethodId);

};

#endif // DITHERFACTORY_H
