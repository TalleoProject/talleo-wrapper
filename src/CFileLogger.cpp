#include "WrapperBuild.h"
#include "Logging/FileLogger.h"
#include "CFileLogger.h"
#include "boost/date_time/posix_time/conversion.hpp"

/* Constructor */
void* FileLogger_Create() {
   Logging::FileLogger* logger = new Logging::FileLogger();
   return logger;
}

void* FileLogger_CreateWithLevel(Logging::Level level) {
   Logging::FileLogger* logger = new Logging::FileLogger(level);
   return logger;
}

/* Destructor */
void FileLogger_Destroy(void* logger) {
   delete static_cast<Logging::FileLogger*>(logger);
}

/* Class methods */
void FileLogger_init(void* logger, const char* filename) {
   static_cast<Logging::FileLogger*>(logger)->init(filename);
}

void FileLogger_log(void* logger, const char* category, Logging::Level level, uint64_t time, const char* body) {
   static_cast<Logging::FileLogger*>(logger)->operator()(category, level, boost::posix_time::from_time_t(time), body);
}