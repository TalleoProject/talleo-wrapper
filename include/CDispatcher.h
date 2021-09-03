#ifdef __cplusplus
extern "C" {
#endif

   /* Constructor */
   EXPORT void* Dispatcher_Create();

   /* Destructor */
   EXPORT void Dispatcher_Destroy(void* dispatcher);

   /* Class methods */
   EXPORT void Dispatcher_clear(void* dispatcher);
   EXPORT void Dispatcher_dispatch(void* dispatcher);
   EXPORT System::NativeContext* Dispatcher_getCurrentContext(void* dispatcher);
   EXPORT void Dispatcher_interrupt(void* dispatcher);
   EXPORT void Dispatcher_interruptWithContext(void* dispatcher, System::NativeContext* context);
   EXPORT bool Dispatcher_interrupted(void* dispatcher);
   EXPORT void Dispatcher_pushContext(void* dispatcher, System::NativeContext* context);
   EXPORT void Dispatcher_remoteSpawn(void* dispatcher, void (*procedure)());
   EXPORT void Dispatcher_yield(void* dispatcher);

   // Platform-specific

#ifdef WIN32
   EXPORT void Dispatcher_addTimer(void* dispatcher, uint64_t time, System::NativeContext* context);
   EXPORT void* Dispatcher_getCompletionPort(void* dispatcher);
   EXPORT void Dispatcher_interruptTimer(void* dispatcher, uint64_t time, System::NativeContext* context);
#endif

#ifdef OSX
   EXPORT int Dispatcher_getKqueue(void* dispatcher);
#endif

#if defined(LINUX) || defined(ANDROID)
   EXPORT int Dispatcher_getEpoll(void* dispatcher);
#endif

#ifdef POSIX
   EXPORT int Dispatcher_getTimer(void* dispatcher);
   EXPORT void Dispatcher_pushTimer(void* dispatcher, int timer);
#endif

   // Common
   EXPORT void Dispatcher_getReusableContext(void* dispatcher, System::NativeContext*);
   EXPORT void Dispatcher_pushReusableContext(void* dispatcher, System::NativeContext*);

#ifdef __cplusplus
}
#endif
