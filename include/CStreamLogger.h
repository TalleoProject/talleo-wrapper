#ifdef __cplusplus
extern "C" {
#endif

   /* Constructor */
   EXPORT void* StreamLogger_Create();
   EXPORT void* StreamLogger_CreateWithLevel(Logging::Level level);
   EXPORT void* StreamLogger_CreateWithStream(std::ostream* stream);
   EXPORT void* StreamLogger_CreateWithStreamLevel(std::ostream* stream, Logging::Level level);

   /* Destructor */
   EXPORT void StreamLogger_Destroy(void* logger);
   /* Class methods */
   EXPORT void StreamLogger_attachToStream(void* logger, std::ostream* stream);

#ifdef __cplusplus
}
#endif
