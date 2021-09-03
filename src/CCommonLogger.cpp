#include "WrapperBuild.h"

#include "Logging/CommonLogger.h"

#include "CCommonLogger.h"

/* Constructor */

/* Destructor */
void CommonLogger_Destroy(void* logger) {
   delete static_cast<Logging::CommonLogger*>(logger);
}

/* Class methods */

void CommonLogger_Log(void* logger, const char* category, Logging::Level level, time_t time, const char* body) {
   static_cast<Logging::CommonLogger*>(logger)->operator()(category, level, boost::posix_time::from_time_t(time), body);
}
void CommonLogger_enableCategory(void* logger, const char* category) {
   static_cast<Logging::CommonLogger*>(logger)->enableCategory(category);
}
void CommonLogger_disableCategory(void* logger, const char* category) {
   static_cast<Logging::CommonLogger*>(logger)->disableCategory(category);
}
void CommonLogger_setMaxLevel(void* logger, Logging::Level level) {
   static_cast<Logging::CommonLogger*>(logger)->setMaxLevel(level);
}

void CommonLogger_setPattern(void* logger, const char* pattern) {
   static_cast<Logging::CommonLogger*>(logger)->setPattern(pattern);
}
