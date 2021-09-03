#include "WrapperBuild.h"

#include "CryptoNote.h"

#include "CCryptoNote.h"
#include "ConvertVector.h"

CKeyInput convertKeyInput(const CryptoNote::KeyInput& keyInput) {
   CKeyInput _keyInput;
   _keyInput.amount = keyInput.amount;
   _keyInput.outputIndexes = new uint32_t[keyInput.outputIndexes.size()];
   if (_keyInput.outputIndexes) {
      _keyInput.outputIndexCount = keyInput.outputIndexes.size();
      for (int i = 0; i < _keyInput.outputIndexCount; i++) {
         _keyInput.outputIndexes[i] = _keyInput.outputIndexes[i];
      }
   }
   else {
      _keyInput.outputIndexCount = 0;
   }
   _keyInput.keyImage = keyInput.keyImage;
   return _keyInput;
}

void convertTransactionInputs(const std::vector<CryptoNote::TransactionInput>& inputVector, CTransactionInput* inputs, uint64_t& inputCount)
{
   inputs = new CTransactionInput[inputVector.size()];
   if (inputs) {
      inputCount = inputVector.size();
      for (int i = 0; i < inputCount; i++) {
         CTransactionInput _input;
         _input.isBase = (inputVector[i].type() == typeid(CryptoNote::BaseInput));
         if (_input.isBase) {
            _input.baseInput = boost::get<CryptoNote::BaseInput>(inputVector[i]);
         }
         else {
            _input.keyInput = convertKeyInput(boost::get<CryptoNote::KeyInput>(inputVector[i]));
         }
         inputs[i] = _input;
      }
   }
   else {
      inputCount = 0;
   }
}

void convertTransactionOutputs(const std::vector<CryptoNote::TransactionOutput>& outputVector, CTransactionOutput* outputs, uint64_t& outputCount)
{
   outputs = new CTransactionOutput[outputVector.size()];
   if (outputs) {
      outputCount = outputVector.size();
      for (int i = 0; i < outputCount; i++) {
         CTransactionOutput _output;
         _output.amount = outputVector[i].amount;
         _output.hasKey = (outputVector[i].target.type() == typeid(CryptoNote::KeyOutput));
         if (_output.hasKey) {
            _output.keyOutput = boost::get<CryptoNote::KeyOutput>(outputVector[i].target);
         }
         outputs[i] = _output;
      }
   }
   else {
      outputCount = 0;
   }
}

void convertSignatures(const std::vector<std::vector<Crypto::Signature>>& signatureVector, CSignatureArray* signatureArray, uint64_t& signatureCount) {
   signatureArray = NULL;
   signatureCount = 0;
   if (signatureVector.size() > 0) {
      signatureArray = new CSignatureArray[signatureVector.size()];
      if (signatureArray) {
         for (size_t i = 0; i < signatureVector.size(); i++) {
            convertVectorToArray(signatureVector[i], &(signatureArray[i].signatures), signatureArray[i].signatureCount);
            if (signatureArray[i].signatures == NULL) break;
            signatureCount++;
         }
      }
   }
}

CBaseTransaction convertBaseTransaction(const CryptoNote::BaseTransaction& baseTransaction) {
   CBaseTransaction ret;
   ret.version = baseTransaction.version;
   ret.unlockTime = baseTransaction.unlockTime;
   convertTransactionInputs(baseTransaction.inputs, ret.inputs, ret.inputCount);
   convertTransactionOutputs(baseTransaction.outputs, ret.outputs, ret.outputCount);
   return ret;
}

CTransaction convertTransaction(const CryptoNote::Transaction& transaction) {
   CTransaction ret;
   ret.version = transaction.version;
   ret.unlockTime = transaction.unlockTime;
   convertTransactionInputs(transaction.inputs, ret.inputs, ret.inputCount);
   convertTransactionOutputs(transaction.outputs, ret.outputs, ret.outputCount);
   convertSignatures(transaction.signatures, ret.signatures, ret.signatureCount);
   return ret;
}

CParentBlock convertParentBlock(const CryptoNote::ParentBlock& parentBlock) {
   CParentBlock ret;
   ret.majorVersion = parentBlock.majorVersion;
   ret.minorVersion = parentBlock.minorVersion;
   ret.previousBlockHash = parentBlock.previousBlockHash;
   ret.transactionCount = parentBlock.transactionCount;
   convertVectorToArray(parentBlock.baseTransactionBranch, &(ret.baseTransactionBranch), ret.baseTransactionBranchCount);
   ret.baseTransaction = convertBaseTransaction(parentBlock.baseTransaction);
   convertVectorToArray(parentBlock.blockchainBranch, &(ret.blockchainBranch), ret.blockchainBranchCount);
   return ret;
}

CBlockTemplate convertBlockTemplate(const CryptoNote::BlockTemplate& blockTemplate) {
   CBlockTemplate ret;
   ret.majorVersion = blockTemplate.majorVersion;
   ret.minorVersion = blockTemplate.minorVersion;
   ret.nonce = blockTemplate.nonce;
   ret.timestamp = blockTemplate.timestamp;
   ret.previousBlockHash = blockTemplate.previousBlockHash;
   ret.parentBlock = convertParentBlock(blockTemplate.parentBlock);
   ret.baseTransaction = convertTransaction(blockTemplate.baseTransaction);
   convertVectorToArray(blockTemplate.transactionHashes, &(ret.transactionHashes), ret.transactionHashCount);
   return ret;
}

void BinaryArray_Cleanup(CBinaryArray& binaryArray) {
   delete[] binaryArray.data;
   binaryArray.dataLength = 0;
}

void SignatureArray_Cleanup(CSignatureArray& signatureArray) {
   delete[] signatureArray.signatures;
   signatureArray.signatureCount = 0;
}

void SignatureArrays_Cleanup(CSignatureArray* signatureArrays, uint64_t signatureArraysCount) {
   for (int i = 0; i < signatureArraysCount; i++) {
      SignatureArray_Cleanup(signatureArrays[i]);
   }
   delete[] signatureArrays;
}

void TransactionInputList_Cleanup(CTransactionInput* inputs, uint64_t inputCount) {
   for (int i = 0; i < inputCount; i++) {
      CTransactionInput input = inputs[i];
      if (!input.isBase) {
         delete[] input.keyInput.outputIndexes;
      }
   }
}

void BaseTransaction_Cleanup(CBaseTransaction& baseTransaction) {
   TransactionInputList_Cleanup(baseTransaction.inputs, baseTransaction.inputCount);
   delete[] baseTransaction.inputs;
   baseTransaction.inputCount = 0;
   delete[] baseTransaction.outputs;
   baseTransaction.outputCount = 0;
   BinaryArray_Cleanup(baseTransaction.extra);
}

void Transaction_Cleanup(CTransaction& transaction) {
   TransactionInputList_Cleanup(transaction.inputs, transaction.inputCount);
   delete[] transaction.inputs;
   transaction.inputCount = 0;
   delete[] transaction.outputs;
   transaction.outputCount = 0;
   BinaryArray_Cleanup(transaction.extra);
   for (int i = 0; i < transaction.signatureCount; i++) {
      SignatureArray_Cleanup(transaction.signatures[i]);
   }
   delete[] transaction.signatures;
   transaction.signatureCount = 0;
}

void ParentBlock_Cleanup(CParentBlock& parentBlock) {
   delete[] parentBlock.baseTransactionBranch;
   parentBlock.baseTransactionBranchCount = 0;
   BaseTransaction_Cleanup(parentBlock.baseTransaction);
   delete[] parentBlock.blockchainBranch;
   parentBlock.blockchainBranchCount = 0;
}

void BlockTemplate_Cleanup(CBlockTemplate& blockTemplate) {
   ParentBlock_Cleanup(blockTemplate.parentBlock);
   Transaction_Cleanup(blockTemplate.baseTransaction);
   delete[] blockTemplate.transactionHashes;
   blockTemplate.transactionHashCount = 0;
}

void KeyInput_Cleanup(CKeyInput& keyInput) {
   if (keyInput.outputIndexCount) {
      delete[] keyInput.outputIndexes;
      keyInput.outputIndexCount = 0;
   }
}