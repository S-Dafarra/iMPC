#ifndef IMPC_MODEL_H
#define IMPC_MODEL_H

#include "iMpc/Constants.h"
#include <iDynTree/Core/VectorDynSize.h>

namespace iMpc {
    class Model;
}

class iMpc::Model{
    
public:
    Model();
    
    virtual ~Model();
    
    virtual bool getModelInfo(unsigned int& nX, unsigned int& mU, unsigned int& pY) = 0;
    
    virtual bool isLTI();
    
    virtual bool evaluateModel(const double t, const iDynTree::VectorDynSize& x,
                               const iDynTree::VectorDynSize& u, const iDynTree::VectorDynSize& parameters,
                               iDynTree::VectorDynSize& xDot, iDynTree::VectorDynSize& y) = 0;
};


#endif
