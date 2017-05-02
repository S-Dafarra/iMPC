#ifndef IMPC_CONSTANTS_H
#define IMPC_CONSTANTS_H


namespace iMpc {
    enum iMpcDiscretizationMethods{
        ForwardEuler,
        BacwardEuler,
        Trapezoid,
    };
    
    enum ConstraintType{
        Equality = 0,
        LowerBounded = 1,
        UpperBounded = 1 << 1,
        Bounded = LowerBounded | UpperBounded,
    };
    
    enum CostType{
        Integral,
        Terminal,
    };
}

#endif