#include "WrapperBuild.h"
#include "System/Dispatcher.h"
#include "CDispatcher.h"

/* Constructor */
void* Dispatcher_Create() {
   return new System::Dispatcher();
}

/* Destructor */
void Dispatcher_Destroy(void* dispatcher) {
   delete static_cast<System::Dispatcher*>(dispatcher);
}

/* Class methods */
void Dispatcher_clear(void* dispatcher) {
   static_cast<System::Dispatcher*>(dispatcher)->clear();
}

void Dispatcher_dispatch(void* dispatcher) {
   static_cast<System::Dispatcher*>(dispatcher)->dispatch();
}

System::NativeContext* Dispatcher_getCurrentContext(void* dispatcher) {
   return static_cast<System::Dispatcher*>(dispatcher)->getCurrentContext();
}

void Dispatcher_interrupt(void* dispatcher) {
   static_cast<System::Dispatcher*>(dispatcher)->interrupt();
}

void Dispatcher_interrupt(void* dispatcher, System::NativeContext* context) {
   static_cast<System::Dispatcher*>(dispatcher)->interrupt(context);
}

bool Dispatcher_interrupted(void* dispatcher) {
   return static_cast<System::Dispatcher*>(dispatcher)->interrupted();
}

void Dispatcher_pushContext(void* dispatcher, System::NativeContext* context) {
   static_cast<System::Dispatcher*>(dispatcher)->pushContext(context);
}

void Dispatcher_remoteSpawn(void* dispatcher, void (*procedure)()) {
   static_cast<System::Dispatcher*>(dispatcher)->remoteSpawn(procedure);
}

void Dispatcher_yield(void* dispatcher) {
   static_cast<System::Dispatcher*>(dispatcher)->yield();
}

// Platform-specific
#ifdef WIN32
void Dispatcher_addTimer(void* dispatcher, uint64_t time, System::NativeContext* context) {
   static_cast<System::Dispatcher*>(dispatcher)->addTimer(time, context);
}

void* Dispatcher_getCompletionPort(void* dispatcher) {
   return static_cast<System::Dispatcher*>(dispatcher)->getCompletionPort();
}

void Dispatcher_interruptTimer(void* dispatcher, uint64_t time, System::NativeContext* context) {
   static_cast<System::Dispatcher*>(dispatcher)->interruptTimer(time, context);
}
#endif

#ifdef OSX
int Dispatcher_getKqueue(void* dispatcher) {
   return static_cast<System::Dispatcher*>(dispatcher)->getKqueue();
}
#endif

#if defined(LINUX) || defined(ANDROID)
int Dispatcher_getEpoll(void* dispatcher) {
   return static_cast<System::Dispatcher*>(dispatcher)->getEpoll();
}
#endif

#ifdef POSIX
int Dispatcher_getTimer(void* dispatcher) {
   return static_cast<System::Dispatcher*>(dispatcher)->getTimer();
}

void Dispatcher_pushTimer(void* dispatcher, int timer) {
   static_cast<System::Dispatcher*>(dispatcher)->pushTimer(timer);
}
#endif

void Dispatcher_getReusableContext(void* dispatcher, System::NativeContext* context) {
   context = &static_cast<System::Dispatcher*>(dispatcher)->getReusableContext();
}

void Dispatcher_pushReusableContext(void* dispatcher, System::NativeContext* context) {
   static_cast<System::Dispatcher*>(dispatcher)->pushReusableContext(*context);
}
