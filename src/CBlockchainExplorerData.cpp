#include <stdint.h>
#include "CBlockchainExplorerData.h"
void TransactionExtraDetails_Cleanup(CTransactionExtraDetails& details) {
   BinaryArray_Cleanup(details.nonce);
   BinaryArray_Cleanup(details.raw);
}
void KeyInputDetails_Cleanup(CKeyInputDetails& details) {
   KeyInput_Cleanup(details.input);
}
void TransactionInputDetails_Cleanup(CTransactionInputDetails& details) {
   if (!details.isBase) {
      KeyInputDetails_Cleanup(details.keyInputDetails);
   }
}
void TransactionInputDetailsArray_Cleanup(CTransactionInputDetails* details, uint64_t detailsCount) {
   for (int i = 0; i < detailsCount; i++) {
      TransactionInputDetails_Cleanup(details[i]);
   }
}
void TransactionDetails_Cleanup(CTransactionDetails& transactionDetails) {
   TransactionExtraDetails_Cleanup(transactionDetails.extra);
   SignatureArrays_Cleanup(transactionDetails.signatures, transactionDetails.signatureCount);
   delete[] transactionDetails.signatures;
   transactionDetails.signatureCount = 0;
   TransactionInputDetailsArray_Cleanup(transactionDetails.inputs, transactionDetails.inputCount);
   delete[] transactionDetails.inputs;
   transactionDetails.inputCount = 0;
   delete[] transactionDetails.outputs;
   transactionDetails.outputCount = 0;
}
void BlockDetails_Cleanup(CBlockDetails& blockDetails) {
   for (int i = 0; i < blockDetails.transactionCount; i++) {
      TransactionDetails_Cleanup(blockDetails.transactions[i]);
   }
   delete[] blockDetails.transactions;
   blockDetails.transactionCount = 0;
}