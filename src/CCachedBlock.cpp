#include "WrapperBuild.h"

#include "CryptoNoteCore/CachedBlock.h"

#include "CCryptoNote.h"
#include "CCachedBlock.h"

/* Constructor */
void* CachedBlock_Create(const CryptoNote::BlockTemplate& block) {
   return new CryptoNote::CachedBlock(block);
}

/* Destructor */
void CachedBlock_Destroy(void* block) {
   delete static_cast<CryptoNote::CachedBlock*>(block);
}

/* Class methods */
const CryptoNote::BlockTemplate& CachedBlock_getBlock(void* block) {
   return static_cast<CryptoNote::CachedBlock*>(block)->getBlock();
}
const Crypto::Hash& CachedBlock_getTransactionTreeHash(void* block) {
   return static_cast<CryptoNote::CachedBlock*>(block)->getTransactionTreeHash();
}
const Crypto::Hash& CachedBlock_getBlockHash(void* block) {
   return static_cast<CryptoNote::CachedBlock*>(block)->getBlockHash();
}
const Crypto::Hash& CachedBlock_getBlockLongHash(void* block) {
   return static_cast<CryptoNote::CachedBlock*>(block)->getBlockLongHash();
}
const Crypto::Hash& CachedBlock_getAuxiliaryBlockHeaderHash(void* block) {
   return static_cast<CryptoNote::CachedBlock*>(block)->getAuxiliaryBlockHeaderHash();
}
void CachedBlock_getBlockHashingBinaryArray(void* block, CBinaryArray& array) {
   const CryptoNote::BinaryArray& arr = static_cast<CryptoNote::CachedBlock*>(block)->getBlockHashingBinaryArray();
   array.data = new uint8_t[arr.size()];
   std::copy(arr.begin(), arr.end(), array.data);
   array.dataLength = arr.size();
}
void CachedBlock_getParentBlockBinaryArray(void* block, bool headerOnly, CBinaryArray& array) {
   const CryptoNote::BinaryArray& arr = static_cast<CryptoNote::CachedBlock*>(block)->getParentBlockBinaryArray(headerOnly);
   array.data = new uint8_t[arr.size()];
   std::copy(arr.begin(), arr.end(), array.data);
   array.dataLength = arr.size();
}
void CachedBlock_getParentBlockHashingBinaryArray(void* block, bool headerOnly, CBinaryArray& array) {
   const CryptoNote::BinaryArray& arr = static_cast<CryptoNote::CachedBlock*>(block)->getParentBlockHashingBinaryArray(headerOnly);
   array.data = new uint8_t[arr.size()];
   std::copy(arr.begin(), arr.end(), array.data);
   array.dataLength = arr.size();
}
uint32_t CachedBlock_getBlockIndex(void* block) {
   return static_cast<CryptoNote::CachedBlock*>(block)->getBlockIndex();
}
