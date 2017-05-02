#ifndef IMPC_CONSTRAINT_H
#define IMPC_CONSTRAINT_H

#include "iMpc/Constants.h"
#include <iDynTree/Core/VectorDynSize.h>

namespace iMpc{
    class Constraint;
}

class iMpc::Constraint{
    
public:
    Constraint();
    
    virtual ~Constraint();
    
    virtual bool getConstraintInfo(unsigned int& n, enum iMpc::ConstraintType& type) = 0;
    
    virtual bool evaluateConstraint(const iDynTree::VectorDynSize& x, const iDynTree::VectorDynSize& u, const iDynTree::VectorDynSize& parameters, iDynTree::VectorDynSize& result) = 0;
    
    virtual bool isAffine();
    
    virtual bool getLowerBound(const iDynTree::VectorDynSize& parameters, iDynTree::VectorDynSize &lowerBound);
    
    virtual bool getUpperBound(const iDynTree::VectorDynSize& parameters, iDynTree::VectorDynSize &upperBound);
    
    virtual bool getEqualityRightHandSide(const iDynTree::VectorDynSize& parameters, iDynTree::VectorDynSize &rightHandSide);
};


#endif