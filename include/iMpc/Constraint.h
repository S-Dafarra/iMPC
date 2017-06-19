#ifndef IMPC_CONSTRAINT_H
#define IMPC_CONSTRAINT_H

#include "iMpc/Constants.h"
#include <iDynTree/Core/VectorDynSize.h>
#include <iDynTree/Core/MatrixDynSize.h>

namespace iMpc{
    class Constraint;
    class LinearConstraint;
}

class iMpc::Constraint{
    
public:
    Constraint();
    
    virtual ~Constraint();
    
    virtual bool getConstraintInfo(unsigned int& n, enum iMpc::ConstraintType& type) = 0;
    
    virtual bool evaluateConstraint(const iDynTree::VectorDynSize& x,
                                    const iDynTree::VectorDynSize& u,
                                    const iDynTree::VectorDynSize& parameters,
                                    iDynTree::VectorDynSize& costraints) = 0;

    virtual bool evaluateConstraintJacobian(const iDynTree::VectorDynSize& x,
                                    const iDynTree::VectorDynSize& u,
                                    const iDynTree::VectorDynSize& parameters,
                                    iDynTree::MatrixDynSize& dCostraints_dx) = 0;
    
    virtual bool getLowerBound(const iDynTree::VectorDynSize& parameters, iDynTree::VectorDynSize &lowerBound);
    
    virtual bool getUpperBound(const iDynTree::VectorDynSize& parameters, iDynTree::VectorDynSize &upperBound);
    
    virtual bool getEqualityRightHandSide(const iDynTree::VectorDynSize& parameters, iDynTree::VectorDynSize &rightHandSide);
};


class iMpc::LinearConstraint{
    
public:
    
    LinearConstraint();
    
    virtual ~LinearConstraint();
    
    virtual bool getConstraintType(enum iMpc::ConstraintType& type) = 0;
    
    virtual bool getConstraintMatrix(const iDynTree::VectorDynSize& parameters, iDynTree::MatrixDynSize& A) = 0;
    
    virtual bool getLowerBound(const iDynTree::VectorDynSize& parameters, iDynTree::VectorDynSize &lowerBound);
    
    virtual bool getUpperBound(const iDynTree::VectorDynSize& parameters, iDynTree::VectorDynSize &upperBound);
    
    virtual bool getEqualityRightHandSide(const iDynTree::VectorDynSize& parameters, iDynTree::VectorDynSize &rightHandSide);
};

#endif