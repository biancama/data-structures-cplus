//
// Created by Massimo Biancalani on 16/05/16.
//

#ifndef DATASTRUCTURED_INDEXOUTOFBOUNDSEXCEPTION_H
#define DATASTRUCTURED_INDEXOUTOFBOUNDSEXCEPTION_H
#include <stdexcept>
using std::runtime_error;
class IndexOutOfBoundsException: public runtime_error{
public:
    IndexOutOfBoundsException(): runtime_error( "attempted to access to index out of bound" ) {}
};


#endif //DATASTRUCTURED_INDEXOUTOFBOUNDSEXCEPTION_H
