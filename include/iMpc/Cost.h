#ifndef IMPC_COST_H
#define IMPC_COST_H

#include "iMpc/Constants.h"
#include <iDynTree/Core/VectorDynSize.h>
#include <iDynTree/Core/MatrixDynSize.h>
#include <vector>

namespace iMpc{
    class Cost;
    class QuadraticCost;
}

class iMpc::Cost{
    
public:
    Cost();
    
    virtual ~Cost();
    
    virtual bool evaluateCost(const iDynTree::VectorDynSize& x, const iDynTree::VectorDynSize& u, const iDynTree::VectorDynSize& parameters, double& cost) = 0;
    
    virtual bool evaluateCostJacobian(const iDynTree::VectorDynSize& x, const iDynTree::VectorDynSize& u, const iDynTree::VectorDynSize& parameters, iDynTree::VectorDynSize& dCost_dx) = 0;

    virtual enum iMpc::ConstraintType getCostType() = 0;
};

class iMpc::QuadraticCost{
    
public:
    QuadraticCost();
    
    virtual ~QuadraticCost();
    
    virtual bool getQuadraticCost(const iDynTree::VectorDynSize& parameters, iDynTree::MatrixDynSize& weights, iDynTree::VectorDynSize& referenceValue) = 0;
    
    virtual bool getQuadraticCost(const iDynTree::VectorDynSize& parameters, iDynTree::MatrixDynSize& weights, std::vector <iDynTree::VectorDynSize > & referenceTrajectory) = 0;
    
    virtual enum iMpc::ConstraintType getCostType() = 0;
    
};

#endif