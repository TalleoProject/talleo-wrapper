#include "WrapperBuild.h"

#include "NodeRpcProxy/NodeRpcProxy.h"

#include "CCryptoNote.h"
#include "CBlockchainExplorerData.h"
#include "CCoreRpcServerCommandsDefinitions.h"
#include "CNode.h"
#include "CNodeRpcProxy.h"
#include "ConvertVector.h"

#include <system_error>

/* Constructor */
void* NodeRpcProxy_Create(const char* nodeHost, unsigned short nodePort, const char* nodePath, const bool& useSSL, void* logger) {
   return new CryptoNote::NodeRpcProxy(nodeHost, nodePort, nodePath, useSSL, *static_cast<Logging::ILogger*>(logger));
}

/* Destructor */
void NodeRpcProxy_Destroy(void* proxy) {
   delete static_cast<CryptoNote::NodeRpcProxy*>(proxy);
}

/* Class methods */
bool NodeRpcProxy_addINodeObserver(void* proxy, void* observer) {
   return static_cast<CryptoNote::NodeRpcProxy*>(proxy)->addObserver(static_cast<CryptoNote::INodeObserver*>(observer));
}

bool NodeRpcProxy_removeINodeObserver(void* proxy, void* observer) {
   return static_cast<CryptoNote::NodeRpcProxy*>(proxy)->removeObserver(static_cast<CryptoNote::INodeObserver*>(observer));
}

bool NodeRpcProxy_addINodeRpcProxyObserver(void* proxy, void* observer) {
   return static_cast<CryptoNote::NodeRpcProxy*>(proxy)->addObserver(static_cast<CryptoNote::INodeRpcProxyObserver*>(observer));
}

bool NodeRpcProxy_removeINodeRpcProxyObserver(void* proxy, void* observer) {
   return static_cast<CryptoNote::NodeRpcProxy*>(proxy)->removeObserver(static_cast<CryptoNote::INodeRpcProxyObserver*>(observer));
}

void NodeRpcProxy_init(void* proxy, const CryptoNote::INode::Callback& callback) {
   return static_cast<CryptoNote::NodeRpcProxy*>(proxy)->init(callback);
}

bool NodeRpcProxy_shutdown(void* proxy) {
   return static_cast<CryptoNote::NodeRpcProxy*>(proxy)->shutdown();
}

uint64_t NodeRpcProxy_getPeerCount(void* proxy) {
   return static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getPeerCount();
}

uint32_t NodeRpcProxy_getLastLocalBlockHeight(void* proxy) {
   return static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getLastLocalBlockHeight();
}

uint32_t NodeRpcProxy_getLastKnownBlockHeight(void* proxy) {
   return static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getLastKnownBlockHeight();
}

uint32_t NodeRpcProxy_getLocalBlockCount(void* proxy) {
   return static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getLocalBlockCount();
}

uint32_t NodeRpcProxy_getKnownBlockCount(void* proxy) {
   return static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getKnownBlockCount();
}

uint64_t NodeRpcProxy_getLastLocalBlockTimestamp(void* proxy) {
   return static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getLastLocalBlockTimestamp();
}

const char* NodeRpcProxy_getLastFeeAddress(void* proxy) {
   return static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getLastFeeAddress().c_str();
}

const char* NodeRpcProxy_getLastCollateralHash(void* proxy) {
   return static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getLastCollateralHash().c_str();
}

void NodeRpcProxy_getBlockHashesByTimestamps(void* proxy, uint64_t timestampBegin, uint64_t secondsCount, Crypto::Hash* blockHashes, uint64_t& blockHashesCount, const CryptoNote::INode::Callback& callback) {
   std::vector<Crypto::Hash> vec_blockHashes;
   CryptoNote::INode::Callback convertCallback = [&](std::error_code ec) mutable {
      convertVectorToArray(vec_blockHashes, &blockHashes, blockHashesCount);
      callback(ec);
   };
   static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getBlockHashesByTimestamps(timestampBegin, secondsCount, vec_blockHashes, convertCallback);
}

void NodeRpcProxy_getTransactionHashesByPaymentId(void* proxy, const Crypto::Hash& paymentId, Crypto::Hash* transactionHashes, uint64_t& transactionHashesCount, const CryptoNote::INode::Callback& callback) {
   std::vector<Crypto::Hash> vec_transactionHashes;
   CryptoNote::INode::Callback convertCallback = [&](std::error_code ec) mutable {
      convertVectorToArray(vec_transactionHashes, &transactionHashes, transactionHashesCount);
      callback(ec);
   };
   static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getTransactionHashesByPaymentId(paymentId, vec_transactionHashes, convertCallback);
}

CryptoNote::BlockHeaderInfo NodeRpcProxy_getLastLocalBlockHeaderInfo(void* proxy) {
   return static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getLastLocalBlockHeaderInfo();
}

void NodeRpcProxy_relayTransaction(void* proxy, const CryptoNote::Transaction& transaction, const CryptoNote::INode::Callback& callback) {
   static_cast<CryptoNote::NodeRpcProxy*>(proxy)->relayTransaction(transaction, callback);
}

void NodeRpcProxy_getRandomOutsByAmounts(void* proxy, uint64_t* amounts, uint64_t& amountsCount, uint16_t outsCount, CCOMMAND_RPC_GET_RANDOM_OUTPUTS_FOR_AMOUNTS_outs_for_amount* result, uint64_t& resultCount, const CryptoNote::INode::Callback& callback) {
   std::vector<uint64_t> vec_amounts = convertArrayToVector(amounts, amountsCount);
   std::vector<CryptoNote::COMMAND_RPC_GET_RANDOM_OUTPUTS_FOR_AMOUNTS::outs_for_amount> vec_result;
   CryptoNote::INode::Callback convertCallback = [&](std::error_code ec) mutable {
      CryptoNote::COMMAND_RPC_GET_RANDOM_OUTPUTS_FOR_AMOUNTS::outs_for_amount* _result;
      convertVectorToArray(vec_result, &_result, resultCount);
      if (resultCount != 0) {
         result = new CCOMMAND_RPC_GET_RANDOM_OUTPUTS_FOR_AMOUNTS_outs_for_amount[resultCount];
         if (result) {
            for (int i = 0; i < resultCount; i++) {
               result[i].amount = _result[i].amount;
               convertVectorToArray(_result[i].outs, &(result[i].outs), result[i].outsCount);
            }
         }
         delete[] _result;
      }
      callback(ec);
   };
   static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getRandomOutsByAmounts(std::move(vec_amounts), outsCount, vec_result, convertCallback);
}

CryptoNote::RawBlock convertRawBlock(const CRawBlock& block) {
   CryptoNote::RawBlock _block;
   _block.block = convertBinaryArray(block.block);
   for (int i = 0; i < block.transactionCount; i++) {
      _block.transactions.push_back(convertBinaryArray(block.transactions[i]));
   }
   return _block;
}

void NodeRpcProxy_getNewBlocks(void* proxy, Crypto::Hash* knownBlockIds, uint64_t& knownBlockIdsCount, CRawBlock* newBlocks, uint64_t& newBlocksCount, uint32_t& startHeight, const CryptoNote::INode::Callback& callback) {
   std::vector<Crypto::Hash> vec_knownBlockIds = convertArrayToVector(knownBlockIds, knownBlockIdsCount);
   std::vector<CryptoNote::RawBlock> vec_newBlocks;
   CryptoNote::INode::Callback convertCallback = [&](std::error_code ec) mutable {
      for (int i = 0; i < newBlocksCount; i++) {
         vec_newBlocks.push_back(convertRawBlock(newBlocks[i]));
      }
      callback(ec);
   };
   static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getNewBlocks(std::move(vec_knownBlockIds), vec_newBlocks, startHeight, convertCallback);
}

void NodeRpcProxy_getTransactionOutsGlobalIndices(void* proxy, const Crypto::Hash& transactionHash, uint32_t* outsGlobalIndices, uint64_t& outsGlobalIndicesCount, const CryptoNote::INode::Callback& callback) {
   std::vector<uint32_t> vec_outsGlobalIndices;
   CryptoNote::INode::Callback convertCallback = [&](std::error_code ec) mutable {
      convertVectorToArray(vec_outsGlobalIndices, &outsGlobalIndices, outsGlobalIndicesCount);
      callback(ec);
   };
   static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getTransactionOutsGlobalIndices(transactionHash, vec_outsGlobalIndices, convertCallback);
}

void NodeRpcProxy_queryBlocks(void* proxy, Crypto::Hash* knownBlockIds, uint64_t& knownBlockIdsCount, uint64_t timestamp, CryptoNote::BlockShortEntry* newBlocks, uint64_t& newBlocksCount, uint32_t& startHeight, const CryptoNote::INode::Callback& callback) {
   std::vector<Crypto::Hash> vec_knownBlockIds = convertArrayToVector(knownBlockIds, knownBlockIdsCount);
   std::vector<CryptoNote::BlockShortEntry> vec_newBlocks;
   CryptoNote::INode::Callback convertCallback = [&](std::error_code ec) mutable {
      convertVectorToArray(vec_newBlocks, &newBlocks, newBlocksCount);
      callback(ec);
   };
   static_cast<CryptoNote::NodeRpcProxy*>(proxy)->queryBlocks(std::move(vec_knownBlockIds), timestamp, vec_newBlocks, startHeight, convertCallback);
}

void NodeRpcProxy_getPoolSymmetricDifference(void* proxy, Crypto::Hash* knownPoolTxIds, uint64_t& knownPoolTxIdsCount, Crypto::Hash knownBlockId, bool& isBcActual,
   CryptoNote::ITransactionReader** newTxs, uint64_t& newTxsCount, Crypto::Hash* deletedTxIds, uint64_t& deletedTxIdsCount, const CryptoNote::INode::Callback& callback) {
   std::vector<Crypto::Hash> vec_knownPoolTxIds = convertArrayToVector(knownPoolTxIds, knownPoolTxIdsCount);
   std::vector<std::unique_ptr<CryptoNote::ITransactionReader>> vec_newTxs;
   std::vector<Crypto::Hash> vec_deletedTxIds;
   CryptoNote::INode::Callback convertCallback = [&](std::error_code ec) mutable {
      convertVectorToArray(vec_newTxs, &newTxs, newTxsCount);
      convertVectorToArray(vec_deletedTxIds, &deletedTxIds, deletedTxIdsCount);
      callback(ec);
   };
   static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getPoolSymmetricDifference(std::move(vec_knownPoolTxIds), reinterpret_cast<Crypto::Hash&>(knownBlockId), isBcActual, vec_newTxs, vec_deletedTxIds, callback);
}

CTransactionExtraDetails convertTransactionExtraDetails(const CryptoNote::TransactionExtraDetails& details) {
   CTransactionExtraDetails _details;
   _details.publicKey = details.publicKey;
   _details.nonce = convertBinaryArray(details.nonce);
   _details.raw = convertBinaryArray(details.raw);
   return _details;
}

CKeyInputDetails convertKeyInputDetails(const CryptoNote::KeyInputDetails& details) {
   CKeyInputDetails _details;
   _details.input = convertKeyInput(details.input);
   _details.mixin = details.mixin;
   _details.output = details.output;
   return _details;
}

CTransactionInputDetails convertTransactionInputDetails(const CryptoNote::TransactionInputDetails& details) {
   CTransactionInputDetails _details;
   _details.isBase = (details.type() == typeid(CryptoNote::BaseInputDetails));
   if (_details.isBase) {
      _details.baseInputDetails = boost::get<CryptoNote::BaseInputDetails>(details);
   }
   else {
      _details.keyInputDetails = convertKeyInputDetails(boost::get<CryptoNote::KeyInputDetails>(details));
   }
   return _details;

}

void convertTransactionInputDetails(const std::vector<CryptoNote::TransactionInputDetails>& vec_inputs, CTransactionInputDetails* inputs, uint64_t& inputCount) {
   inputs = new CTransactionInputDetails[vec_inputs.size()];
   inputCount = 0;
   if (inputs) {
      for (int i = 0; i < vec_inputs.size(); i++) {
         inputs[i] = convertTransactionInputDetails(vec_inputs[i]);
      }
      inputCount = vec_inputs.size();
   }
}

CTransactionOutput convertTransactionOutput(const CryptoNote::TransactionOutput& output) {
   CTransactionOutput _output;
   _output.amount = output.amount;
   _output.hasKey = output.target.type() == typeid(CryptoNote::KeyOutput);
   if (_output.hasKey) {
      _output.keyOutput = boost::get<CryptoNote::KeyOutput>(output.target);
   }
   return _output;
}

void convertTransactionOutputDetails(const std::vector<CryptoNote::TransactionOutputDetails>& vec_outputs, CTransactionOutputDetails* outputs, uint64_t& outputCount) {
   outputs = new CTransactionOutputDetails[vec_outputs.size()];
   outputCount = 0;
   if (outputs) {
      for (int i = 0; i < vec_outputs.size(); i++) {
         outputs[i].output = convertTransactionOutput(vec_outputs[i].output);
         outputs[i].globalIndex = vec_outputs[i].globalIndex;
      }
      outputCount = vec_outputs.size();
   }
}

CTransactionDetails convertTransactionDetails(const CryptoNote::TransactionDetails& details) {
   CTransactionDetails _details;
   _details.hash = details.hash;
   _details.size = details.size;
   _details.fee = details.fee;
   _details.totalInputsAmount = details.totalInputsAmount;
   _details.totalOutputsAmount = details.totalOutputsAmount;
   _details.mixin = details.mixin;
   _details.unlockTime = details.unlockTime;
   _details.paymentId = details.paymentId;
   _details.hasPaymentId = details.hasPaymentId;
   _details.inBlockchain = details.inBlockchain;
   _details.blockHash = details.blockHash;
   _details.blockIndex = details.blockIndex;
   _details.extra = convertTransactionExtraDetails(details.extra);
   convertSignatures(details.signatures, _details.signatures, _details.signatureCount);
   convertTransactionInputDetails(details.inputs, _details.inputs, _details.inputCount);
   convertTransactionOutputDetails(details.outputs, _details.outputs, _details.outputCount);
   return _details;

}
CBlockDetails convertBlockDetails(const CryptoNote::BlockDetails& details) {
   CBlockDetails _details;
   _details.majorVersion = details.majorVersion;
   _details.minorVersion = details.minorVersion;
   _details.timestamp = details.timestamp;
   _details.prevBlockHash = details.prevBlockHash;
   _details.nonce = details.nonce;
   _details.isAlternative = details.isAlternative;
   _details.index = details.index;
   _details.hash = details.hash;
   _details.difficulty = details.difficulty;
   _details.reward = details.reward;
   _details.baseReward = details.baseReward;
   _details.blockSize = details.blockSize;
   _details.transactionsCumulativeSize = details.transactionsCumulativeSize;
   _details.alreadyGeneratedCoins = details.alreadyGeneratedCoins;
   _details.alreadyGeneratedTransactions = details.alreadyGeneratedTransactions;
   _details.sizeMedian = details.sizeMedian;
   _details.penalty = details.penalty;
   _details.totalFeeAmount = details.totalFeeAmount;
   _details.transactions = new CTransactionDetails[details.transactions.size()];
   _details.transactionCount = 0;
   if (_details.transactions) {
      for (int i = 0; i < details.transactions.size(); i++) {
         _details.transactions[i] = convertTransactionDetails(details.transactions[i]);
         _details.transactionCount++;
      }
   }
   return _details;

}
void NodeRpcProxy_getBlocksByHeights(void* proxy, uint32_t* blockHeights, uint64_t& blockHeightsCount, CBlockDetailsArray* results, uint64_t& resultsCount, const CryptoNote::INode::Callback& callback) {
   std::vector<uint32_t> vec_blockHeights = convertArrayToVector(blockHeights, blockHeightsCount);
   std::vector<std::vector<CryptoNote::BlockDetails>> vec_blockDetails;
   CryptoNote::INode::Callback convertCallback = [&](std::error_code ec) mutable {
      results = new CBlockDetailsArray[vec_blockDetails.size()];
      resultsCount = 0;
      if (results) {
         for (int i = 0; i < vec_blockDetails.size(); i++) {
            results[i].blockDetails = new CBlockDetails[vec_blockDetails[i].size()];
            if (results[i].blockDetails) {
               for (int j = 0; j < results[i].blockDetailsCount; j++) {
                  results[i].blockDetails[j] = convertBlockDetails(vec_blockDetails[i][j]);
                  results[i].blockDetailsCount++;
               }
               resultsCount++;
            }
         }
      }
      callback(ec);
   };
   static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getBlocks(vec_blockHeights, vec_blockDetails, convertCallback);
}

void NodeRpcProxy_getBlocksByHashes(void* proxy, Crypto::Hash* blockHashes, uint64_t& blockHashesCount, CBlockDetails* blocks, uint64_t& blocksCount, const CryptoNote::INode::Callback& callback) {
   std::vector<Crypto::Hash> vec_blockHashes = convertArrayToVector(blockHashes, blockHashesCount);
   std::vector<CryptoNote::BlockDetails> vec_blockDetails;
   CryptoNote::INode::Callback convertCallback = [&](std::error_code ec) mutable {
      blocks = new CBlockDetails[vec_blockDetails.size()];
      if (blocks) {
         for (int i = 0; i < vec_blockDetails.size(); i++) {
            blocks[i] = convertBlockDetails(vec_blockDetails[i]);
         }
         blocksCount = vec_blockDetails.size();
      }
      callback(ec);
   };
   static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getBlocks(vec_blockHashes, vec_blockDetails, convertCallback);
}

void NodeRpcProxy_getBlock(void* proxy, const uint32_t blockHeight, CBlockDetails& block, const CryptoNote::INode::Callback& callback) {
   CryptoNote::BlockDetails _block;
   CryptoNote::INode::Callback convertCallback = [&](std::error_code ec) mutable {
      block = convertBlockDetails(_block);
      callback(ec);
   };
   static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getBlock(blockHeight, _block, convertCallback);
}

void NodeRpcProxy_getTransactions(void* proxy, Crypto::Hash* transactionHashes, uint64_t& transactionHashesCount, CTransactionDetails* transactions, uint64_t& transactionsCount, const CryptoNote::INode::Callback& callback) {
   std::vector<Crypto::Hash> vec_transactionHashes = convertArrayToVector(transactionHashes, transactionHashesCount);
   std::vector<CryptoNote::TransactionDetails> vec_transactions;
   CryptoNote::INode::Callback convertCallback = [&](std::error_code ec) mutable {
      transactions = new CTransactionDetails[vec_transactions.size()];
      if (transactions) {
         for (int i = 0; i < vec_transactions.size(); i++) {
            transactions[i] = convertTransactionDetails(vec_transactions[i]);
         }
         transactionsCount = vec_transactions.size();
      }
      callback(ec);
   };
   static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getTransactions(vec_transactionHashes, vec_transactions, convertCallback);
}

void NodeRpcProxy_getFeeAddress(void* proxy, char* feeAddress, const CryptoNote::INode::Callback& callback) {
   std::string _feeAddress;
   CryptoNote::INode::Callback convertCallback = [&](std::error_code ec) mutable {
      feeAddress = strdup(_feeAddress.c_str());
      callback(ec);
   };
   static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getFeeAddress(_feeAddress, convertCallback);
}

void NodeRpcProxy_getCollateralHash(void* proxy, char* collateralHash, const CryptoNote::INode::Callback& callback) {
   std::string _collateralHash;
   CryptoNote::INode::Callback convertCallback = [&](std::error_code ec) mutable {
      collateralHash = strdup(_collateralHash.c_str());
      callback(ec);
   };
   static_cast<CryptoNote::NodeRpcProxy*>(proxy)->getCollateralHash(_collateralHash, convertCallback);
}

void NodeRpcProxy_isSynchronized(void* proxy, bool& syncStatus, const CryptoNote::INode::Callback& callback) {
   static_cast<CryptoNote::NodeRpcProxy*>(proxy)->isSynchronized(syncStatus, callback);
}

unsigned int NodeRpcProxy_getRpcTimeout(void* proxy) {
   return static_cast<CryptoNote::NodeRpcProxy*>(proxy)->rpcTimeout();
}

void NodeRpcProxy_setRpcTimeout(void* proxy, unsigned int val) {
   static_cast<CryptoNote::NodeRpcProxy*>(proxy)->rpcTimeout(val);
}
