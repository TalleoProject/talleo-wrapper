#ifdef __cplusplus
extern "C" {
#endif

   EXPORT bool bytes_to_words(const Crypto::SecretKey& src, char* words, const char* language_name);
   EXPORT bool is_valid_mnemonic(const char* mnemonic_phrase, Crypto::SecretKey& private_spend_key);

#ifdef __cplusplus
}
#endif
