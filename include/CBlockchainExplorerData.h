#include "CCryptoNote.h"
#include "BlockchainExplorerData.h"

struct CKeyInputDetails
{
   CKeyInput input;
   uint64_t mixin;
   CryptoNote::TransactionOutputReferenceDetails output;
};

struct CTransactionInputDetails
{
   bool isBase;
   union {
      CryptoNote::BaseInputDetails baseInputDetails;
      CKeyInputDetails keyInputDetails;
   };
};
struct CTransactionOutputDetails
{
   CTransactionOutput output;
   uint64_t globalIndex;
};

struct CTransactionExtraDetails
{
   Crypto::PublicKey publicKey;
   CBinaryArray nonce;
   CBinaryArray raw;
};

struct CTransactionDetails
{
   Crypto::Hash hash;
   uint64_t size;
   uint64_t fee;
   uint64_t totalInputsAmount;
   uint64_t totalOutputsAmount;
   uint64_t mixin;
   uint64_t unlockTime;
   uint64_t timestamp;
   Crypto::Hash paymentId;
   bool hasPaymentId;
   bool inBlockchain;
   Crypto::Hash blockHash;
   uint32_t blockIndex;
   CTransactionExtraDetails extra;
   CSignatureArray* signatures;
   uint64_t signatureCount;
   CTransactionInputDetails* inputs;
   uint64_t inputCount;
   CTransactionOutputDetails* outputs;
   uint64_t outputCount;
};

struct CBlockDetails
{
   uint8_t majorVersion;
   uint8_t minorVersion;
   uint64_t timestamp;
   Crypto::Hash prevBlockHash;
   uint32_t nonce;
   bool isAlternative;
   uint32_t index;
   Crypto::Hash hash;
   uint64_t difficulty;
   uint64_t reward;
   uint64_t baseReward;
   uint64_t blockSize;
   uint64_t transactionsCumulativeSize;
   uint64_t alreadyGeneratedCoins;
   uint64_t alreadyGeneratedTransactions;
   uint64_t sizeMedian;
   double penalty;
   uint64_t totalFeeAmount;
   CTransactionDetails* transactions;
   uint64_t transactionCount;
};

struct CBlockDetailsArray
{
   CBlockDetails* blockDetails;
   uint64_t blockDetailsCount;
};

EXPORT void TransactionDetails_Cleanup(CTransactionDetails& transactionDetails);
EXPORT void BlockDetails_Cleanup(CBlockDetails& blockDetails);
