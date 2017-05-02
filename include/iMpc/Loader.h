#ifndef IMPC_LOADER_H
#define IMPC_LOADER_H

#include "iMpc/Constants.h"
#include "iMpc/Model.h"
#include "iMpc/Constraint.h"
#include <iDynTree/Core/VectorFixSize.h>
#include <iDynTree/Core/VectorDynSize.h>
#include <iDynTree/Core/MatrixDynSize.h>

namespace iMpc {
    class Loader;
}


class iMpc::Loader{
    
public:
    Loader();
   
    ~Loader();
    
    bool setModel(iMpc::Model* model);
    
    iMpc::Model& model();
    
    bool setFeedback(const double t, const iDynTree::VectorDynSize& x, const iDynTree::VectorDynSize& u, const iDynTree::VectorDynSize& parameters);
    
    bool discretizeModel(const double dT, const enum iMpc::iMpcDiscretizationMethods method);
    
    bool setParameters(const iDynTree::VectorDynSize& parameters);
};

#endif
