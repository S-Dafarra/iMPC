#ifndef IMPC_COST_H
#define IMPC_COST_H

#include "iMpc/Constants.h"
#include <iDynTree/Core/VectorDynSize.h>
#include <iDynTree/Core/MatrixDynSize.h>

namespace iMpc{
    class Cost;
}

class iMpc::Cost{
    
public:
    Cost();
    
    virtual ~Cost();
    
    virtual bool isQuadratic();
    
    virtual bool evaluateCost(const iDynTree::VectorDynSize& x, const iDynTree::VectorDynSize& u, const iDynTree::VectorDynSize& parameters, double& cost);
    
    virtual bool getQuadraticCost(const iDynTree::VectorDynSize& parameters, iDynTree::MatrixDynSize& hessian, iDynTree::VectorDynSize& gradient);
    
    virtual enum iMpc::ConstraintType getCostType() = 0;
};

#endif