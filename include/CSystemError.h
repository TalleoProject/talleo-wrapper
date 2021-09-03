#ifdef __cplusplus
extern "C" {
#endif

   EXPORT const char* error_category_name(void* category);
   EXPORT const char* error_category_message(void* category, int condition);

#ifdef __cplusplus
}
#endif