#ifdef __cplusplus
extern "C" {
#endif

   EXPORT void generateViewKeysFromSpend(Crypto::SecretKey&, Crypto::SecretKey&, Crypto::PublicKey&);
   EXPORT void generateViewKeyFromSpend(Crypto::SecretKey&, Crypto::SecretKey&);

   // Constructor
   EXPORT void* AccountBase_Create();

   // Destructor
   EXPORT void AccountBase_Destroy(void*);

   // Class methods
   EXPORT void AccountBase_generate(void*);

   EXPORT const CryptoNote::AccountKeys& AccountBase_getAccountKeys(void*);
   EXPORT void setAccountKeys(void*, const CryptoNote::AccountKeys& keys);
   EXPORT uint64_t AccountBase_get_createtime(void*);
   EXPORT void AccountBase_set_createtime(void*, uint64_t val);

#ifdef __cplusplus
}
#endif
