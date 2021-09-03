#include "CWallet.h"

#ifdef __cplusplus
extern "C" {
#endif

   /* Utility functions to make sure arrays allocated from heap get destroyed by correct memory manager */

   EXPORT void BlockDetailsArray_Destroy(CBlockDetails* array);
   EXPORT void BlockDetailsResultsArray_Destroy(CBlockDetailsArray* array, uint64_t items);
   EXPORT void BlockShortEntryArray_Destroy(CBlockShortEntry* array);
   EXPORT void HashArray_Destroy(Crypto::Hash* array);
   EXPORT void ITransactionReaderArray_Destroy(CryptoNote::ITransactionReader** array);
   EXPORT void outs_for_amountArray_Destroy(CCOMMAND_RPC_GET_RANDOM_OUTPUTS_FOR_AMOUNTS_outs_for_amount* array);
   EXPORT void RawBlockArray_Destroy(CRawBlock* array);
   EXPORT void String_Destroy(char* string); /* allocated using strdup() etc. */
   EXPORT void TransactionDetailsArray_Destroy(CTransactionDetails* array);
   EXPORT void TransactionOutputInformationArray_Destroy(CryptoNote::TransactionOutputInformation* array);
   EXPORT void TransactionsInBlockInfo_Destroy(CTransactionsInBlockInfo* array);
   EXPORT void UInt32Array_Destroy(uint32_t* array);
   EXPORT void UInt64Array_Destroy(uint64_t* array);

#ifdef __cplusplus
}
#endif
