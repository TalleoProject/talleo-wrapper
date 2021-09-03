#ifdef __cplusplus
extern "C" {
#endif

   /* Constructor */
   EXPORT void* WalletGreen_Create(void* dispatcher, void* currency, void* node, Logging::ILogger* logger);
   EXPORT void* WalletGreen_CreateWithSoftLockTime(void* dispatcher, void* currency, void* node, Logging::ILogger* logger, uint32_t transactionSoftLockTime);

   /* Destructor */
   EXPORT void WalletGreen_Destroy(void* wallet);

   /* Class methods */

   EXPORT void WalletGreen_initialize(void* wallet, const char* path, const char* password);
   EXPORT void WalletGreen_initializeWithViewKey(void* wallet, const char* path, const char* password, const Crypto::SecretKey& viewSecretKey);
   EXPORT void WalletGreen_load(void* wallet, const char* path, const char* password);
   EXPORT void WalletGreen_loadWithExtra(void* wallet, const char* path, const char* password, const char* extra);
   EXPORT void WalletGreen_shutdown(void* wallet);

   EXPORT void WalletGreen_changePassword(void* wallet, const char* oldPassword, const char* newPassword);
   EXPORT void WalletGreen_save(void* wallet);
   EXPORT void WalletGreen_saveWithLevel(void* wallet, CryptoNote::WalletSaveLevel saveLevel);
   EXPORT void WalletGreen_saveWithLevelExtra(void* wallet, CryptoNote::WalletSaveLevel saveLevel, const char* extra);
   EXPORT void WalletGreen_exportWallet(void* wallet, const char* path);
   EXPORT void WalletGreen_exportWalletWithEncrypt(void* wallet, const char* path, bool encrypt);
   EXPORT void WalletGreen_exportWalletWithEncryptLevel(void* wallet, const char* path, bool encrypt, CryptoNote::WalletSaveLevel saveLevel);
   EXPORT void WalletGreen_exportWalletWithEncryptLevelExtra(void* wallet, const char* path, bool encrypt, CryptoNote::WalletSaveLevel saveLevel, const char* extra);

   EXPORT uint64_t WalletGreen_getAddressCount(void* wallet);
   EXPORT const char* WalletGreen_getAddress(void* wallet, uint64_t index);
   EXPORT CryptoNote::KeyPair WalletGreen_getAddressSpendKeyWithIndex(void* wallet, uint64_t index);
   EXPORT CryptoNote::KeyPair WalletGreen_getAddressSpendKey(void* wallet, const char* address);
   EXPORT CryptoNote::KeyPair WalletGreen_getViewKey(void* wallet);
   EXPORT const char* WalletGreen_createAddress(void* wallet);
   EXPORT const char* WalletGreen_createAddressWithSecretKey(void* wallet, const Crypto::SecretKey& spendSecretKey);
   EXPORT const char* WalletGreen_createAddressWithPublicKey(void* wallet, const Crypto::PublicKey& spendPublicKey);
   EXPORT void WalletGreen_createAddressList(void* wallet, Crypto::SecretKey* spendSecretKeys, uint64_t keyCount, char** addresses, uint64_t& addressCount);
   EXPORT void WalletGreen_deleteAddress(void* wallet, const char* address);

   EXPORT uint64_t WalletGreen_getActualBalance(void* wallet);
   EXPORT uint64_t WalletGreen_getActualBalanceWithAddress(void* wallet, const char* address);
   EXPORT uint64_t WalletGreen_getPendingBalance(void* wallet);
   EXPORT uint64_t WalletGreen_getPendingBalanceWithAddress(void* wallet, const char* address);

   struct CWalletOuts {
      CryptoNote::WalletRecord* wallet;
      CryptoNote::TransactionOutputInformation* outs;
      uint64_t outsCount;
   };

   EXPORT CWalletOuts WalletGreen_getUnspentOutputs(void* wallet, const char* address);

   EXPORT uint64_t WalletGreen_getTransactionCount(void* wallet);
   EXPORT CWalletTransaction WalletGreen_getTransactionWithIndex(void* wallet, uint64_t transactionIndex);
   EXPORT uint64_t WalletGreen_getTransactionTransferCount(void* wallet, uint64_t transactionIndex);
   EXPORT CWalletTransfer WalletGreen_getTransactionTransfer(void* wallet, uint64_t transactionIndex, uint64_t transferIndex);

   EXPORT CWalletTransactionWithTransfers WalletGreen_getTransactionWithHash(void* wallet, const Crypto::Hash& transactionHash);
   EXPORT void WalletGreen_getTransactionsByHash(void* wallet, const Crypto::Hash& blockHash, uint64_t count, CryptoNote::TransactionsInBlockInfo* transactions, uint64_t& transactionCount);
   EXPORT void WalletGreen_getTransactionsByIndex(void* wallet, uint32_t blockIndex, uint64_t count, CryptoNote::TransactionsInBlockInfo* transactions, uint64_t& transactionCount);
   EXPORT void WalletGreen_getBlockHashes(void* wallet, uint32_t blockIndex, uint64_t count, Crypto::Hash* hashes, uint64_t& hashCount);
   EXPORT uint32_t WalletGreen_getBlockCount(void* wallet);
   EXPORT void WalletGreen_getUnconfirmedTransactions(void* wallet, CWalletTransactionWithTransfers* transactions, uint64_t& transactionCount);
   EXPORT void WalletGreen_getDelayedTransactionIds(void* wallet, uint64_t* ids, uint64_t& idCount);

   EXPORT uint64_t WalletGreen_transfer(void* wallet, const CryptoNote::TransactionParameters& sendingTransaction);

   EXPORT uint64_t WalletGreen_makeTransaction(void* wallet, const CryptoNote::TransactionParameters& sendingTransaction);
   EXPORT void WalletGreen_commitTransaction(void* wallet, uint64_t);
   EXPORT void WalletGreen_rollbackUncommitedTransaction(void* wallet, uint64_t);
   EXPORT bool WalletGreen_txIsTooLarge(void* wallet, const CryptoNote::TransactionParameters& sendingTransaction);
   EXPORT uint64_t WalletGreen_getTxSize(void* wallet, const CryptoNote::TransactionParameters& sendingTransaction);
   EXPORT void WalletGreen_updateInternalCache(void* wallet);
   EXPORT void WalletGreen_clearCaches(void* wallet, bool clearTransactions, bool clearCachedData);
   EXPORT void WalletGreen_clearCacheAndShutdown(void* wallet);
   EXPORT void WalletGreen_createViewWallet(void* wallet, const char* path, const char* password, const char* address, const Crypto::SecretKey& viewSecretKey);

   EXPORT void WalletGreen_start(void* wallet);
   EXPORT void WalletGreen_stop(void* wallet);
   EXPORT CryptoNote::WalletEvent WalletGreen_getEvent(void* wallet);

   EXPORT uint64_t WalletGreen_createFusionTransaction(void* wallet, uint64_t threshold, uint16_t mixin);
   EXPORT uint64_t WalletGreen_createFusionTransactionWithSources(void* wallet, uint64_t threshold, uint16_t mixin, const char** sourceAddresses, uint64_t addressCount);
   EXPORT uint64_t WalletGreen_createFusionTransactionWithSourcesDestination(void* wallet, uint64_t threshold, uint16_t mixin, const char** sourceAddresses, uint64_t addressCount, const char* destinationAddress);
   EXPORT bool WalletGreen_isFusionTransaction(void* wallet, uint64_t transactionId);
   EXPORT CryptoNote::IFusionManager::EstimateResult WalletGreen_estimate(void* wallet, uint64_t threshold);
   EXPORT CryptoNote::IFusionManager::EstimateResult WalletGreen_estimateWithSources(void* wallet, uint64_t threshold, const char** sourceAddresses, uint64_t addressCount);

   /* Utility functions */
   EXPORT void CWalletTransactionWithTransfers_Cleanup(CWalletTransactionWithTransfers& transaction);
   EXPORT void CWalletTransactionWithTransfersList_Destroy(void* list, uint64_t count);
   EXPORT void CTransactionsInBlockInfo_Cleanup(CTransactionsInBlockInfo& transactions);
   EXPORT void CTransactionsInBlockInfoList_Destroy(void* list, uint64_t count);
   EXPORT void AddressList_Destroy(char** list, uint64_t count);

#ifdef __cplusplus
}
#endif
