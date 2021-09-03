
struct CWalletTransaction {
   CryptoNote::WalletTransactionState state;
   uint64_t timestamp;
   uint32_t blockHeight;
   Crypto::Hash hash;
   int64_t totalAmount;
   uint64_t fee;
   uint64_t creationTime;
   uint64_t unlockTime;
   const char* extra;
   bool isBase;
};

struct CWalletOrder {
   const char* address;
   uint64_t amount;
};

struct CWalletTransfer {
   CryptoNote::WalletTransferType type;
   const char* address;
   int64_t amount;
};

struct CDonationSettings {
   const char* address;
   uint64_t threshold = 0;
};

struct CTransactionParameters {
   const char** sourceAddresses;
   uint64_t sourceAddressCount;
   CWalletOrder* destinations;
   uint64_t destinationCount;
   uint64_t fee = 0;
   uint16_t mixIn = 0;
   std::string extra;
   uint64_t unlockTimestamp = 0;
   CDonationSettings donation;
   const char* changeDestination;
};

struct CWalletTransactionWithTransfers {
   CWalletTransaction transaction;
   CWalletTransfer* transfers;
   uint64_t transferCount;
};

struct CTransactionsInBlockInfo
{
   Crypto::Hash blockHash;
   CWalletTransactionWithTransfers* transactions;
   uint64_t transactionCount;
};
