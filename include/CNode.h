#ifndef _CNODE_H_
#define _CNODE_H_
struct CTransactionShortInfo
{
   Crypto::Hash txId;
   CTransactionPrefix txPrefix;
};

struct CBlockShortEntry
{
   Crypto::Hash blockHash;
   bool hasBlock;
   CBlockTemplate block;
   void* txsShortInfo;
   uint64_t txsShortInfoCount;
};
#endif
