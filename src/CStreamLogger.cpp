#include "WrapperBuild.h"

#include "Logging/StreamLogger.h"

#include "CStreamLogger.h"


/* Constructor */
void* StreamLogger_Create() {
   return new Logging::StreamLogger();
}
void* StreamLogger_CreateWithLevel(Logging::Level level) {
   return new Logging::StreamLogger(level);
}
void* StreamLogger_CreateWithStream(std::ostream* stream) {
   return new Logging::StreamLogger(*stream);
}
void* StreamLogger_CreateWithStreamLevel(std::ostream* stream, Logging::Level level) {
   return new Logging::StreamLogger(*stream, level);
}

/* Destructor */
void StreamLogger_Destroy(void* logger) {
   delete static_cast<Logging::StreamLogger*>(logger);
}
/* Class methods */
void StreamLogger_attachToStream(void* logger, std::ostream* stream) {
   static_cast<Logging::StreamLogger*>(logger)->attachToStream(*stream);
}
