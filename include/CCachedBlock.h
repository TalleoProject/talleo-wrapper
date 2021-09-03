#ifdef __cplusplus
extern "C" {
#endif

   /* Constructor */
   EXPORT void* CachedBlock_Create(const CryptoNote::BlockTemplate& block);

   /* Destructor */
   EXPORT void CachedBlock_Destroy(void* block);
   /* Class methods */
   EXPORT const CryptoNote::BlockTemplate& CachedBlock_getBlock(void* block);
   EXPORT const Crypto::Hash& CachedBlock_getTransactionTreeHash(void* block);
   EXPORT const Crypto::Hash& CachedBlock_getBlockHash(void* block);
   EXPORT const Crypto::Hash& CachedBlock_getBlockLongHash(void* block);
   EXPORT const Crypto::Hash& CachedBlock_getAuxiliaryBlockHeaderHash(void* block);
   EXPORT const CBinaryArray& CachedBlock_getBlockHashingBinaryArray(void* block);
   EXPORT const CBinaryArray& CachedBlock_getParentBlockBinaryArray(void* block, bool headerOnly);
   EXPORT const CBinaryArray& CachedBlock_getParentBlockHashingBinaryArray(void* block, bool headerOnly);
   EXPORT uint32_t CachedBlock_getBlockIndex();

#ifdef __cplusplus
}
#endif
