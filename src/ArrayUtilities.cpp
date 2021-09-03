#include "WrapperBuild.h"

/* From Talleo API */
#include "BlockchainExplorerData.h"
#include "CryptoTypes.h"
#include "INode.h"
#include "ITransaction.h"
#include "ITransfersContainer.h"
#include "IWallet.h"
#include "Rpc/CoreRpcServerCommandsDefinitions.h"

#include "CBlockchainExplorerData.h"
#include "CNodeRpcProxy.h"

#include "ArrayUtilities.h"

/* Utility functions to make sure arrays allocated from heap get destroyed by correct memory manager */

void BlockDetailsArray_Destroy(CBlockDetails* array) {
   delete[] array;
}

void BlockDetailsResultsArray_Destroy(CBlockDetailsArray* array, uint64_t items) {
   for (int i = 0; i < items; i++) {
      BlockDetailsArray_Destroy(array[i].blockDetails);
   }
   delete[] array;
}

void BlockShortEntryArray_Destroy(CBlockShortEntry* array) {
   delete[] array;
}

void HashArray_Destroy(Crypto::Hash* array) {
   delete[] array;
}

void ITransactionReaderArray_Destroy(CryptoNote::ITransactionReader** array) {
   delete[] array;
}

void outs_for_amountArray_Destroy(CryptoNote::COMMAND_RPC_GET_RANDOM_OUTPUTS_FOR_AMOUNTS::outs_for_amount* array) {
   delete[] array;
}

void RawBlockArray_Destroy(CRawBlock* array) {
   delete[] array;
}

void String_Destroy(char* string) {
   free(string);
}

void TransactionDetailsArray_Destroy(CryptoNote::TransactionDetails* array) {
   delete[] array;
}

void TransactionOutputInformationArray_Destroy(CryptoNote::TransactionOutputInformation* array) {
   delete[] array;
}

void TransactionsInBlockInfo_Destroy(CryptoNote::TransactionsInBlockInfo* array) {
   delete[] array;
}

void UInt32Array_Destroy(uint32_t* array) {
   delete[] array;
}

void UInt64Array_Destroy(uint64_t* array) {
   delete[] array;
}
