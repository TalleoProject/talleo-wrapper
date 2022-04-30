#include "CCoreRpcServerCommandsDefinitions.h"
#include "CNode.h"

#ifdef __cplusplus
extern "C" {
#endif

   /* Constructor */
   void* NodeRpcProxy_Create(const char* nodeHost, unsigned short nodePort, const char* nodePath, const bool& useSSL, void* logger);

   /* Destructor */
   void NodeRpcProxy_Destroy(void* proxy);

   /* Class methods */
   bool NodeRpcProxy_addINodeObserver(void* proxy, void* observer);
   bool NodeRpcProxy_removeINodeObserver(void* proxy, void* observer);

   bool NodeRpcProxy_addINodeRpcProxyObserver(void* proxy, void* observer);
   bool NodeRpcProxy_removeINodeRpcProxyObserver(void* proxy, void* observer);

   void NodeRpcProxy_init(void* proxy, const CryptoNote::INode::Callback& callback);
   bool NodeRpcProxy_shutdown(void* proxy);

   uint64_t NodeRpcProxy_getPeerCount(void* proxy);
   uint32_t NodeRpcProxy_getLastLocalBlockHeight(void* proxy);
   uint32_t NodeRpcProxy_getLastKnownBlockHeight(void* proxy);
   uint32_t NodeRpcProxy_getLocalBlockCount(void* proxy);
   uint32_t NodeRpcProxy_getKnownBlockCount(void* proxy);
   uint64_t NodeRpcProxy_getLastLocalBlockTimestamp(void* proxy);
   const char* NodeRpcProxy_getLastFeeAddress(void* proxy);
   const char* NodeRpcProxy_getLastCollateralHash(void* proxy);

   void NodeRpcProxy_getBlockHashesByTimestamps(void* proxy, uint64_t timestampBegin, uint64_t secondsCount, Crypto::Hash* blockHashes, uint64_t& blockHashesCount, const CryptoNote::INode::Callback& callback);
   void NodeRpcProxy_getTransactionHashesByPaymentId(void* proxy, const Crypto::Hash& paymentId, Crypto::Hash* transactionHashes, uint64_t& transactionHashesCount, const CryptoNote::INode::Callback& callback);

   CryptoNote::BlockHeaderInfo NodeRpcProxy_getLastLocalBlockHeaderInfo(void* proxy);

   void NodeRpcProxy_relayTransaction(void* proxy, const CryptoNote::Transaction& transaction, const CryptoNote::INode::Callback& callback);
   void NodeRpcProxy_getRandomOutsByAmounts(void* proxy, uint64_t* amounts, uint64_t& amountsCount, uint16_t outsCount, CCOMMAND_RPC_GET_RANDOM_OUTPUTS_FOR_AMOUNTS_outs_for_amount* result, uint64_t& resultCount, const CryptoNote::INode::Callback& callback);
   void NodeRpcProxy_getNewBlocks(void* proxy, Crypto::Hash* knownBlockIds, uint64_t& knownBlockIdsCount, CRawBlock* newBlocks, uint64_t& newBlocksCount, uint32_t& startHeight, const CryptoNote::INode::Callback& callback);
   void NodeRpcProxy_getTransactionOutsGlobalIndices(void* proxy, const Crypto::Hash& transactionHash, uint32_t* outsGlobalIndices, uint64_t& outsGlobalIndicesCount, const CryptoNote::INode::Callback& callback);
   void NodeRpcProxy_queryBlocks(void* proxy, Crypto::Hash* knownBlockIds, uint64_t& knownBlockIdsCount, uint64_t timestamp, CBlockShortEntry* newBlocks, uint64_t& newBlocksCount, uint32_t& startHeight, const CryptoNote::INode::Callback& callback);
   void NodeRpcProxy_getPoolSymmetricDifference(void* proxy, Crypto::Hash* knownPoolTxIds, uint64_t& knownPoolTxIdsCount, Crypto::Hash knownBlockId, bool& isBcActual,
      CryptoNote::ITransactionReader** newTxs, uint64_t& newTxsCount, Crypto::Hash* deletedTxIds, uint64_t& deletedTxIdsCount, const CryptoNote::INode::Callback& callback);

   void NodeRpcProxy_getBlocksByHeights(void* proxy, uint32_t* blockHeights, uint64_t& blockHeightsCount, CBlockDetailsArray* results, uint64_t& resultsCount, const CryptoNote::INode::Callback& callback);
   void NodeRpcProxy_getBlocksByHashes(void* proxy, Crypto::Hash* blockHashes, uint64_t& blockHashesCount, CBlockDetails* blocks, uint64_t& blocksCount, const CryptoNote::INode::Callback& callback);
   void NodeRpcProxy_getBlock(void* proxy, const uint32_t blockHeight, CBlockDetails& block, const CryptoNote::INode::Callback& callback);
   void NodeRpcProxy_getTransactions(void* proxy, Crypto::Hash* transactionHashes, uint64_t& transactionHashesCount, CTransactionDetails* transactions, uint64_t& transactionsCount, const CryptoNote::INode::Callback& callback);
   void NodeRpcProxy_getFeeAddress(void* proxy, char* feeAddress, const CryptoNote::INode::Callback& callback);
   void NodeRpcProxy_getCollateralHash(void* proxy, char* collateralHash, const CryptoNote::INode::Callback& callback);
   void NodeRpcProxy_isSynchronized(void* proxy, bool& syncStatus, const CryptoNote::INode::Callback& callback);

   unsigned int NodeRpcProxy_getRpcTimeout(void* proxy);
   void NodeRpcProxy_setRpcTimeout(void* proxy, unsigned int val);

#ifdef __cplusplus
}
#endif