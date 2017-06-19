#ifndef IMPC_MODEL_H
#define IMPC_MODEL_H

#include "iMpc/Constants.h"
#include <iDynTree/Core/VectorDynSize.h>
#include <iDynTree/Core/MatrixDynSize.h>

namespace iMpc {
    class Model;
    class LTImodel;
}

class iMpc::Model{
    
public:
    Model();
    
    virtual ~Model();
    
    virtual bool getModelInfo(unsigned int& nX, unsigned int& mU, unsigned int& pY) = 0;
    
    virtual bool evaluateModel(const double t, const iDynTree::VectorDynSize& x,
                               const iDynTree::VectorDynSize& u, const iDynTree::VectorDynSize& parameters,
                               iDynTree::VectorDynSize& xDot, iDynTree::VectorDynSize& y) = 0;

    virtual bool evaluateModelJacobian(const double t, const iDynTree::VectorDynSize& x,
                                       const iDynTree::VectorDynSize& u, const iDynTree::VectorDynSize& parameters,
                                       iDynTree::VectorDynSize& df_dx, iDynTree::VectorDynSize& y) = 0;

};

class iMpc::LTImodel{
    
    LTImodel();
    
    virtual ~LTImodel();
    
    virtual bool getModelMatrices(const iDynTree::VectorDynSize& parameters, iDynTree::MatrixDynSize& A, iDynTree::MatrixDynSize& B) = 0;
};

#endif
