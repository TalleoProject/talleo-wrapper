#include "WrapperBuild.h"
#include "CSystemError.h"
#include <system_error>

const char* error_category_name(void* category) {
   return static_cast<std::error_category*>(category)->name();
}

const char* error_category_message(void* category, int condition) {
   return static_cast<std::error_category*>(category)->message(condition).c_str();
}
