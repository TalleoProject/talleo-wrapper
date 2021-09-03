#ifndef _CCRYPTONOTE_H_
#define _CCRYPTONOTE_H_

#include "CryptoNote.h"
#include "CryptoTypes.h"
#include "WrapperBuild.h"

struct CBinaryArray {
   uint8_t* data;
   uint64_t dataLength;
};

struct CSignatureArray {
   Crypto::Signature* signatures;
   uint64_t signatureCount;
};

struct CKeyInput {
   uint64_t amount;
   uint32_t* outputIndexes;
   uint64_t outputIndexCount;
   Crypto::KeyImage keyImage;
};

struct CTransactionInput {
   bool isBase;
   union {
      CryptoNote::BaseInput baseInput;
      CKeyInput keyInput;
   };
};

struct CTransactionOutput {
   uint64_t amount;
   CryptoNote::KeyOutput keyOutput;
   bool hasKey;
};

struct CTransactionPrefix {
   uint8_t version;
   uint64_t unlockTime;
   CTransactionInput* inputs;
   uint64_t inputCount;
   CTransactionOutput* outputs;
   uint64_t outputCount;
   CBinaryArray extra;
};

struct CTransaction : public CTransactionPrefix {
   CSignatureArray* signatures;
   uint64_t signatureCount;
};

struct CBaseTransaction : public CTransactionPrefix {
};

struct CParentBlock {
   uint8_t majorVersion;
   uint8_t minorVersion;
   Crypto::Hash previousBlockHash;
   uint16_t transactionCount;
   Crypto::Hash* baseTransactionBranch;
   uint64_t baseTransactionBranchCount;
   CBaseTransaction baseTransaction;
   Crypto::Hash* blockchainBranch;
   uint64_t blockchainBranchCount;
};

struct CBlockTemplate : public CryptoNote::BlockHeader {
   CParentBlock parentBlock;
   CTransaction baseTransaction;
   Crypto::Hash* transactionHashes;
   uint64_t transactionHashCount;
};

struct CRawBlock
{
   CBinaryArray block; //BlockTemplate
   CBinaryArray* transactions;
   uint64_t transactionCount;
};

inline CBinaryArray convertBinaryArray(const CryptoNote::BinaryArray& ba) {
   CBinaryArray cba;
   cba.data = (ba.size() != 0) ? new uint8_t[ba.size()] : NULL;
   if (cba.data) {
      memcpy(cba.data, ba.data(), ba.size());
      cba.dataLength = ba.size();
   }
   else {
      cba.dataLength = 0;
   }
   return cba;
}

inline CryptoNote::BinaryArray convertBinaryArray(const CBinaryArray& cba) {
   CryptoNote::BinaryArray ba;
   ba.reserve(cba.dataLength);
   ba.insert(ba.end(), cba.data[0], cba.data[cba.dataLength]);
   return ba;
}

CKeyInput convertKeyInput(const CryptoNote::KeyInput& keyInput);

void convertTransactionInputs(const std::vector<CryptoNote::TransactionInput>& inputVector, CTransactionInput* inputs, uint64_t& inputCount);
void convertTransactionOutputs(const std::vector<CryptoNote::TransactionOutput>& outputVector, CTransactionOutput* outputs, uint64_t& outputCount);
void convertSignatures(const std::vector<std::vector<Crypto::Signature>>& signatureVector, CSignatureArray* signatureArray, uint64_t& signatureCount);

CBaseTransaction convertBaseTransaction(const CryptoNote::BaseTransaction& baseTransaction);
CTransaction convertTransaction(const CryptoNote::Transaction& transaction);
CParentBlock convertParentBlock(const CryptoNote::ParentBlock& parentBlock);
CBlockTemplate convertBlockTemplate(const CryptoNote::BlockTemplate& blockTemplate);

EXPORT void BinaryArray_Cleanup(CBinaryArray& binaryArray);
EXPORT void SignatureArray_Cleanup(CSignatureArray& signatureArray);
EXPORT void SignatureArrays_Cleanup(CSignatureArray* signatureArrays, uint64_t signatureArraysCount);
EXPORT void BaseTransaction_Cleanup(CBaseTransaction& baseTransaction);
EXPORT void Transaction_Cleanup(CTransaction& transaction);
EXPORT void ParentBlock_Cleanup(CParentBlock& parentBlock);
EXPORT void BlockTemplate_Cleanup(CBlockTemplate& blockTemplate);
EXPORT void KeyInput_Cleanup(CKeyInput& keyInput);
#endif
