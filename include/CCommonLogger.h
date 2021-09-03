#ifdef __cplusplus
extern "C" {
#endif

   /* Constructor */

   /* Destructor */
   EXPORT void CommonLogger_Destroy(void* logger);

   /* Class methods */

   EXPORT void CommonLogger_Log(void* logger, const char* category, Logging::Level level, time_t time, const char* body);
   EXPORT void CommonLogger_enableCategory(void* logger, const char* category);
   EXPORT void CommonLogger_disableCategory(void* logger, const char* category);
   EXPORT void CommonLogger_setMaxLevel(void* logger, Logging::Level level);

   EXPORT void CommonLogger_setPattern(void* logger, const char* pattern);
#ifdef __cplusplus
}
#endif
