#include "WrapperBuild.h"
#include "Wallet/WalletGreen.h"
#include "CWallet.h"
#include "CWalletGreen.h"
#include "ConvertVector.h"

/* Constructor */
void* WalletGreen_Create(void* dispatcher, void* currency, void* node, Logging::ILogger* logger) {
   CryptoNote::WalletGreen* wallet = new CryptoNote::WalletGreen(*static_cast<System::Dispatcher*>(dispatcher), *static_cast<CryptoNote::Currency*>(currency), *static_cast<CryptoNote::INode*>(node), *static_cast<Logging::ILogger*>(logger));
   return wallet;
}

void* WalletGreen_CreateWithSoftLockTime(void* dispatcher, void* currency, void* node, Logging::ILogger* logger, uint32_t transactionSoftLockTime) {
   CryptoNote::WalletGreen* wallet = new CryptoNote::WalletGreen(*static_cast<System::Dispatcher*>(dispatcher), *static_cast<CryptoNote::Currency*>(currency), *static_cast<CryptoNote::INode*>(node), *static_cast<Logging::ILogger*>(logger), transactionSoftLockTime);
   return wallet;
}

/* Destructor */
void WalletGreen_Destroy(void* wallet) {
   delete static_cast<CryptoNote::WalletGreen*>(wallet);
}

void WalletGreen_initialize(void* wallet, const char* path, const char* password) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->initialize(path, password);
}

void WalletGreen_initializeWithViewKey(void* wallet, const char* path, const char* password, const Crypto::SecretKey& viewSecretKey) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->initializeWithViewKey(path, password, viewSecretKey);
}

void WalletGreen_loadWithExtra(void* wallet, const char* path, const char* password, const char* extra) {
   std::string _extra;
   static_cast<CryptoNote::WalletGreen*>(wallet)->load(path, password, _extra);
   extra = _extra.c_str();
}

void WalletGreen_load(void* wallet, const char* path, const char* password) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->load(path, password);
}

void WalletGreen_repair(void* wallet) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->repair();
}

void WalletGreen_shutdown(void* wallet) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->shutdown();
}

void WalletGreen_changePassword(void* wallet, const char* oldPassword, const char* newPassword) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->changePassword(oldPassword, newPassword);
}

void WalletGreen_save(void* wallet) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->save();
}

void WalletGreen_saveWithLevel(void* wallet, CryptoNote::WalletSaveLevel saveLevel) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->save(saveLevel);
}

void WalletGreen_saveWithLevelExtra(void* wallet, CryptoNote::WalletSaveLevel saveLevel, const char* extra) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->save(saveLevel, extra);
}

void WalletGreen_exportWallet(void* wallet, const char* path) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->exportWallet(path);
}

void WalletGreen_exportWalletWithEncrypt(void* wallet, const char* path, bool encrypt) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->exportWallet(path, encrypt);
}

void WalletGreen_exportWalletWithEncryptLevel(void* wallet, const char* path, bool encrypt, CryptoNote::WalletSaveLevel saveLevel) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->exportWallet(path, encrypt, saveLevel);
}

void WalletGreen_exportWalletWithEncryptLevelExtra(void* wallet, const char* path, bool encrypt, CryptoNote::WalletSaveLevel saveLevel, const char* extra) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->exportWallet(path, encrypt, saveLevel, extra);
}

uint64_t WalletGreen_getAddressCount(void* wallet) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->getAddressCount();
}

const char* WalletGreen_getAddress(void* wallet, uint64_t index) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->getAddress(index).c_str();
}

CryptoNote::KeyPair WalletGreen_getAddressSpendKeyWithIndex(void* wallet, uint64_t index) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->getAddressSpendKey(index);
}

CryptoNote::KeyPair WalletGreen_getAddressSpendKey(void* wallet, const char* address) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->getAddressSpendKey(address);
}

CryptoNote::KeyPair WalletGreen_getViewKey(void* wallet) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->getViewKey();
}

const char* WalletGreen_createAddress(void* wallet) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->createAddress().c_str();
}

const char* WalletGreen_createAddressWithSecretKey(void* wallet, const Crypto::SecretKey& spendSecretKey) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->createAddress(spendSecretKey).c_str();
}

const char* WalletGreen_createAddressWithPublicKey(void* wallet, const Crypto::PublicKey& spendPublicKey) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->createAddress(spendPublicKey).c_str();
}

void WalletGreen_createAddressList(void* wallet, Crypto::SecretKey* spendSecretKeys, uint64_t keyCount, char** addresses, uint64_t& addressCount) {
   std::vector<Crypto::SecretKey> keys = convertArrayToVector(spendSecretKeys, keyCount);
   std::vector<std::string> vec_addresses = static_cast<CryptoNote::WalletGreen*>(wallet)->createAddressList(keys);
   addresses = new char* [vec_addresses.size()];
   addressCount = 0;
   if (addresses) {
      for (int i = 0; i < vec_addresses.size(); i++) {
         addresses[i] = strdup(vec_addresses[i].c_str());
         if (addresses[i] == NULL) break;
         addressCount++;
      }
   }
}

void WalletGreen_deleteAddress(void* wallet, const char* address) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->deleteAddress(address);
}

uint64_t WalletGreen_getActualBalance(void* wallet) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->getActualBalance();
}

uint64_t WalletGreen_getActualBalanceWithAddress(void* wallet, const char* address) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->getActualBalance(address);
}

uint64_t WalletGreen_getPendingBalance(void* wallet) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->getPendingBalance();
}

uint64_t WalletGreen_getPendingBalanceWithAddress(void* wallet, const char* address) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->getPendingBalance(address);
}

CWalletOuts WalletGreen_getUnspentOutputs(void* wallet, const char* address) {
   CryptoNote::WalletGreen::WalletOuts outs = static_cast<CryptoNote::WalletGreen*>(wallet)->getUnspentOutputs(address);
   CWalletOuts couts;
   couts.wallet = outs.wallet;
   CryptoNote::TransactionOutputInformation* _outs = NULL;
   uint64_t _outsCount;
   convertVectorToArray(outs.outs, &_outs, _outsCount);
   couts.outs = _outs;
   couts.outsCount = _outsCount;
   return couts;
}

uint64_t WalletGreen_getTransactionCount(void* wallet) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->getTransactionCount();
}

CWalletTransaction convertWalletTransaction(CryptoNote::WalletTransaction tx) {
   CWalletTransaction ctx;
   ctx.state = tx.state;
   ctx.timestamp = tx.timestamp;
   ctx.blockHeight = tx.blockHeight;
   ctx.hash = tx.hash;
   ctx.totalAmount = tx.totalAmount;
   ctx.fee = tx.fee;
   ctx.creationTime = tx.creationTime;
   ctx.unlockTime = tx.unlockTime;
   ctx.extra = tx.extra.c_str();
   ctx.isBase = tx.isBase;
   return ctx;
}

CWalletTransfer convertWalletTransfer(CryptoNote::WalletTransfer wt) {
   CWalletTransfer cwt;
   cwt.type = wt.type;
   cwt.address = wt.address.c_str();
   cwt.amount = wt.amount;
   return cwt;
}

CWalletTransactionWithTransfers convertWalletTransactionWithTransfers(CryptoNote::WalletTransactionWithTransfers wtwt) {
   CWalletTransactionWithTransfers cwtwt;
   cwtwt.transaction = convertWalletTransaction(wtwt.transaction);
   cwtwt.transfers = new CWalletTransfer[wtwt.transfers.size()];
   cwtwt.transferCount = 0;
   if (cwtwt.transfers) {
      for (int i = 0; i < wtwt.transfers.size(); i++) {
         cwtwt.transfers[i] = convertWalletTransfer(wtwt.transfers[i]);
         cwtwt.transferCount++;
      }
   }
   return cwtwt;
}

CTransactionsInBlockInfo convertTransactionsInBlockInfo(CryptoNote::TransactionsInBlockInfo tibi) {
   CTransactionsInBlockInfo ctibi;
   ctibi.blockHash = tibi.blockHash;
   ctibi.transactions = new CWalletTransactionWithTransfers[tibi.transactions.size()];
   ctibi.transactionCount = 0;
   if (ctibi.transactions) {
      for (int i = 0; i < tibi.transactions.size(); i++) {
         ctibi.transactions[i] = convertWalletTransactionWithTransfers(tibi.transactions[i]);
         ctibi.transactionCount++;
      }
   }
   return ctibi;
}

CWalletTransaction WalletGreen_getTransactionWithIndex(void* wallet, uint64_t transactionIndex) {
   CryptoNote::WalletTransaction tx = static_cast<CryptoNote::WalletGreen*>(wallet)->getTransaction(transactionIndex);
   return convertWalletTransaction(tx);
}

uint64_t WalletGreen_getTransactionTransferCount(void* wallet, uint64_t transactionIndex) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->getTransactionTransferCount(transactionIndex);
}

CWalletTransfer WalletGreen_getTransactionTransfer(void* wallet, uint64_t transactionIndex, uint64_t transferIndex) {
   CryptoNote::WalletTransfer wt = static_cast<CryptoNote::WalletGreen*>(wallet)->getTransactionTransfer(transactionIndex, transferIndex);
   return convertWalletTransfer(wt);
}

CWalletTransactionWithTransfers WalletGreen_getTransactionWithHash(void* wallet, const Crypto::Hash& transactionHash) {
   CryptoNote::WalletTransactionWithTransfers wtwt = static_cast<CryptoNote::WalletGreen*>(wallet)->getTransaction(transactionHash);
   return convertWalletTransactionWithTransfers(wtwt);
}

void WalletGreen_getTransactionsByHash(void* wallet, const Crypto::Hash& blockHash, uint64_t count, CTransactionsInBlockInfo* transactions, uint64_t& transactionCount) {
   std::vector<CryptoNote::TransactionsInBlockInfo> vec_transactions = static_cast<CryptoNote::WalletGreen*>(wallet)->getTransactions(blockHash, count);
   CryptoNote::TransactionsInBlockInfo* _transactions;
   convertVectorToArray(vec_transactions, &_transactions, transactionCount);
   transactions = new CTransactionsInBlockInfo[transactionCount];
   for (int i = 0; i < transactionCount; i++) {
      transactions[i] = convertTransactionsInBlockInfo(_transactions[i]);
   }
   delete[] _transactions;
}

void WalletGreen_getTransactionsByIndex(void* wallet, uint32_t blockIndex, uint64_t count, CryptoNote::TransactionsInBlockInfo* transactions, uint64_t& transactionCount) {
   std::vector<CryptoNote::TransactionsInBlockInfo> vec_transactions = static_cast<CryptoNote::WalletGreen*>(wallet)->getTransactions(blockIndex, count);
   convertVectorToArray(vec_transactions, &transactions, transactionCount);
}

void WalletGreen_getBlockHashes(void* wallet, uint32_t blockIndex, uint64_t count, Crypto::Hash* hashes, uint64_t& hashCount) {
   std::vector<Crypto::Hash> vec_hashes = static_cast<CryptoNote::WalletGreen*>(wallet)->getBlockHashes(blockIndex, count);
   convertVectorToArray(vec_hashes, &hashes, hashCount);
}

uint32_t WalletGreen_getBlockCount(void* wallet) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->getBlockCount();
}

void WalletGreen_getUnconfirmedTransactions(void* wallet, CWalletTransactionWithTransfers* transactions, uint64_t& transactionCount) {
   std::vector<CryptoNote::WalletTransactionWithTransfers> vec_transactions = static_cast<CryptoNote::WalletGreen*>(wallet)->getUnconfirmedTransactions();
   transactions = new CWalletTransactionWithTransfers[vec_transactions.size()];
   transactionCount = 0;
   if (transactions) {
      for (int i = 0; i < vec_transactions.size(); i++) {
         transactions[i] = convertWalletTransactionWithTransfers(vec_transactions[i]);
         transactionCount++;
      }
   }
}

void WalletGreen_getDelayedTransactionIds(void* wallet, uint64_t* ids, uint64_t& idCount) {
   std::vector<size_t> vec_ids = static_cast<CryptoNote::WalletGreen*>(wallet)->getDelayedTransactionIds();
   convertVectorToArray(vec_ids, &ids, idCount);
}

CryptoNote::WalletOrder convertWalletOrder(const CWalletOrder& order) {
   CryptoNote::WalletOrder _order;
   _order.address = order.address;
   _order.amount = order.amount;
   return _order;
}

CryptoNote::TransactionParameters convertTransactionParameters(const CTransactionParameters& transaction) {
   CryptoNote::TransactionParameters _transaction;
   for (int i = 0; i < transaction.sourceAddressCount; i++) {
      _transaction.sourceAddresses.push_back(transaction.sourceAddresses[i]);
   }
   for (int i = 0; i < transaction.destinationCount; i++) {
      _transaction.destinations.push_back(convertWalletOrder(transaction.destinations[i]));
   }
   _transaction.fee = transaction.fee;
   _transaction.mixIn = transaction.mixIn;
   _transaction.extra = transaction.extra;
   _transaction.unlockTimestamp = transaction.unlockTimestamp;
   _transaction.donation.address = transaction.donation.address;
   _transaction.donation.threshold = transaction.donation.threshold;
   _transaction.changeDestination = transaction.changeDestination;
   return _transaction;
}

uint64_t WalletGreen_transfer(void* wallet, const CTransactionParameters& sendingTransaction) {
   CryptoNote::TransactionParameters _sendingTransaction = convertTransactionParameters(sendingTransaction);
   return static_cast<CryptoNote::WalletGreen*>(wallet)->transfer(_sendingTransaction);
}

uint64_t WalletGreen_makeTransaction(void* wallet, const CTransactionParameters& sendingTransaction) {
   CryptoNote::TransactionParameters _sendingTransaction = convertTransactionParameters(sendingTransaction);
   return static_cast<CryptoNote::WalletGreen*>(wallet)->makeTransaction(_sendingTransaction);
}

void WalletGreen_commitTransaction(void* wallet, uint64_t txid) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->commitTransaction(txid);
}

void WalletGreen_rollbackUncommitedTransaction(void* wallet, uint64_t txid) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->rollbackUncommitedTransaction(txid);
}

bool WalletGreen_txIsTooLarge(void* wallet, const CTransactionParameters& sendingTransaction) {
   CryptoNote::TransactionParameters _sendingTransaction = convertTransactionParameters(sendingTransaction);
   return static_cast<CryptoNote::WalletGreen*>(wallet)->txIsTooLarge(_sendingTransaction);
}

uint64_t WalletGreen_getTxSize(void* wallet, const CTransactionParameters& sendingTransaction) {
   CryptoNote::TransactionParameters _sendingTransaction = convertTransactionParameters(sendingTransaction);
   return static_cast<CryptoNote::WalletGreen*>(wallet)->getTxSize(_sendingTransaction);
}

void WalletGreen_updateInternalCache(void* wallet) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->updateInternalCache();
}

void WalletGreen_clearCaches(void* wallet, bool clearTransactions, bool clearCachedData) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->clearCaches(clearTransactions, clearCachedData);
}

void WalletGreen_clearCacheAndShutdown(void* wallet) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->clearCacheAndShutdown();
}

void WalletGreen_createViewWallet(void* wallet, const char* path, const char* password, const char* address, const Crypto::SecretKey& viewSecretKey) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->createViewWallet(path, password, address, viewSecretKey);
}

void WalletGreen_start(void* wallet) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->start();
}

void WalletGreen_stop(void* wallet) {
   static_cast<CryptoNote::WalletGreen*>(wallet)->stop();
}

CryptoNote::WalletEvent WalletGreen_getEvent(void* wallet) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->getEvent();
}

uint64_t WalletGreen_createFusionTransaction(void* wallet, uint64_t threshold, uint16_t mixin) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->createFusionTransaction(threshold, mixin);
}

uint64_t WalletGreen_createFusionTransactionWithSources(void* wallet, uint64_t threshold, uint16_t mixin, const char** sourceAddresses, uint64_t addressCount) {
   std::vector<std::string> vec_sources = convertArrayToVector(sourceAddresses, addressCount);
   return static_cast<CryptoNote::WalletGreen*>(wallet)->createFusionTransaction(threshold, mixin, vec_sources);
}

uint64_t WalletGreen_createFusionTransactionWithSourcesDestination(void* wallet, uint64_t threshold, uint16_t mixin, const char** sourceAddresses, uint64_t addressCount, const char* destinationAddress) {
   std::vector<std::string> vec_sources = convertArrayToVector(sourceAddresses, addressCount);
   return static_cast<CryptoNote::WalletGreen*>(wallet)->createFusionTransaction(threshold, mixin, vec_sources, destinationAddress);
}

bool WalletGreen_isFusionTransaction(void* wallet, uint64_t transactionId) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->isFusionTransaction(transactionId);
}

CryptoNote::IFusionManager::EstimateResult WalletGreen_estimate(void* wallet, uint64_t threshold) {
   return static_cast<CryptoNote::WalletGreen*>(wallet)->estimate(threshold);
}

CryptoNote::IFusionManager::EstimateResult WalletGreen_estimateWithSources(void* wallet, uint64_t threshold, const char** sourceAddresses, uint64_t addressCount) {
   std::vector<std::string> vec_sources = convertArrayToVector(sourceAddresses, addressCount);
   return static_cast<CryptoNote::WalletGreen*>(wallet)->estimate(threshold, vec_sources);
}

void CWalletTransactionWithTransfers_Cleanup(CWalletTransactionWithTransfers& transaction) {
   delete[] transaction.transfers;
   transaction.transferCount = 0;
}

void CWalletTransactionWithTransfersList_Destroy(void* list, uint64_t count) {
   CWalletTransactionWithTransfers* cwtwt = static_cast<CWalletTransactionWithTransfers*>(list);
   for (int i = 0; i < count; i++) {
      CWalletTransactionWithTransfers_Cleanup(cwtwt[i]);
   }
   delete[] cwtwt;
}

void CTransactionsInBlockInfo_Cleanup(CTransactionsInBlockInfo& transactions) {
   CWalletTransactionWithTransfersList_Destroy(transactions.transactions, transactions.transactionCount);
   transactions.transactionCount = 0;
}

void CTransactionsInBlockInfoList_Destroy(void* list, uint64_t count) {
   CTransactionsInBlockInfo* ctibi = static_cast<CTransactionsInBlockInfo*>(list);
   for (int i = 0; i < count; i++) {
      CTransactionsInBlockInfo_Cleanup(ctibi[i]);
   }
   delete[] ctibi;
}

void AddressList_Destroy(char** list, uint64_t count) {
   for (int i = 0; i < count; i++) {
      free(list[i]);
   }
   delete[] list;
}
