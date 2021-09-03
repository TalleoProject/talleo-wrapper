#include "WrapperBuild.h"

#include <ostream>

#include <COutputStream.h>

/* Constructor */
void* OutputStream_Create(void* buffer) {
   return new std::ostream(static_cast<std::streambuf*>(buffer));
}

/* Destructor */
void OutputStream_Destroy(void* stream) {
   delete static_cast<std::ostream*>(stream);
}

/* Class methods */
