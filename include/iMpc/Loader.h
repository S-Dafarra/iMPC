#ifndef IMPC_LOADER_H
#define IMPC_LOADER_H

#include "iMpc/Constants.h"
#include "iMpc/Model.h"
#include "iMpc/Constraint.h"
#include "iMpc/Cost.h"
#include <iDynTree/Core/VectorFixSize.h>
#include <iDynTree/Core/VectorDynSize.h>
#include <iDynTree/Core/MatrixDynSize.h>
#include <string>

namespace iMpc {
    class Loader;
}


class iMpc::Loader{
    
    bool prepareProblem();
    
    bool discretizeLTIModel();
    
    int getNrOfVariables();
    
    bool getBoundsInfo(iDynTree::VectorDynSize &lowerBound, iDynTree::VectorDynSize &upperBound);
    
    int getNrOfConstraints();
    
    bool getConstraintsInfo(iDynTree::VectorDynSize &lowerBound, iDynTree::VectorDynSize &upperBound);
    
    bool setIntermediateResult(const iDynTree::VectorDynSize& x);
    
    bool evaluateConstraints(iDynTree::VectorDynSize& costraints);
    
    bool evaluateConstraintsJacobian(iDynTree::MatrixDynSize& dCostraints_dx);
    
    bool evaluateCost(double* cost);
    
    bool evaluateCostJacobian(iDynTree::VectorDynSize& dCost_dx);
    
public:
    Loader();
   
    ~Loader();
    
    bool setModel(const iMpc::Model& model);
    
    bool setLTIModel(const iMpc::LTImodel& model);
    
    bool setFeedback(const double t, const iDynTree::VectorDynSize& x, const iDynTree::VectorDynSize& u, const iDynTree::VectorDynSize& parameters);
    
    bool setHorizon(double T, double dT);
    
    bool setDiscretizationMethod(const enum iMpc::iMpcDiscretizationMethods method);
    
    bool setParameters(const iDynTree::VectorDynSize& parameters);
    
    bool addConstraint(const iMpc::Constraint& constraint, const std::string& name);
    
    bool addLinearConstraint(const iMpc::LinearConstraint constraint, const std::string& name);
    
    bool removeConstraint(const std::string& name);
    
    bool addCost(const iMpc::Cost& cost, const std::string& name);
    
    bool addQuadraticCost(const iMpc::QuadraticCost& cost, const std::string& name);
    
    bool removeCost(const std::string& name);
    
    bool setBounds(const iMpc::LinearConstraint& bounds);

};

#endif
