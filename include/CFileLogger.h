#ifdef __cplusplus
extern "C" {
#endif

   /* Constructor */
   EXPORT void* FileLogger_Create();
   EXPORT void* FileLogger_CreateWithLevel(Logging::Level level);

   /* Destructor */
   EXPORT void FileLogger_Destroy(void* logger);

   /* Class methods */
   EXPORT void FileLogger_init(void* logger, const char* filename);
   EXPORT void FileLogger_log(void* logger, const char* category, Logging::Level level, uint64_t time, const char* body);

#ifdef __cplusplus
}
#endif
