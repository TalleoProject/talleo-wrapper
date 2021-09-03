#include "WrapperBuild.h"
#include "CryptoTypes.h"
#include "ITransaction.h"
#include "ConvertVector.h"
#include "CITransactionReader.h"

/* No constructor or destructior as ITransactionReader is interface */

/* Class members */

Crypto::Hash ITransactionReader_getTransactionHash(void* reader) {
   return static_cast<CryptoNote::ITransactionReader*>(reader)->getTransactionHash();
}

Crypto::Hash ITransactionReader_getTransactionPrefixHash(void* reader) {
   return static_cast<CryptoNote::ITransactionReader*>(reader)->getTransactionPrefixHash();
}

Crypto::PublicKey ITransactionReader_getTransactionPublicKey(void* reader) {
   return static_cast<CryptoNote::ITransactionReader*>(reader)->getTransactionPublicKey();
}

bool ITransactionReader_getTransactionSecretKey(void* reader, Crypto::SecretKey& key) {
   return static_cast<CryptoNote::ITransactionReader*>(reader)->getTransactionSecretKey(key);
}

uint64_t ITransactionReader_getUnlockTime(void* reader) {
   return static_cast<CryptoNote::ITransactionReader*>(reader)->getUnlockTime();
}

// extra
bool ITransactionReader_getPaymentId(void* reader, Crypto::Hash& paymentId) {
   return static_cast<CryptoNote::ITransactionReader*>(reader)->getPaymentId(paymentId);
}

bool ITransactionReader_getExtraNonce(void* reader, CBinaryArray& nonce) {
   CryptoNote::BinaryArray _nonce;
   bool ret = static_cast<CryptoNote::ITransactionReader*>(reader)->getExtraNonce(_nonce);
   nonce = convertBinaryArray(_nonce);
   return ret;
}

void ITransactionReader_getExtra(void* reader, CBinaryArray& extra) {
   CryptoNote::BinaryArray _extra = static_cast<CryptoNote::ITransactionReader*>(reader)->getExtra();
   extra = convertBinaryArray(_extra);
}

// inputs
uint64_t ITransactionReader_getInputCount(void* reader) {
   return static_cast<CryptoNote::ITransactionReader*>(reader)->getInputCount();
}

uint64_t ITransactionReader_getInputTotalAmount(void* reader) {
   return static_cast<CryptoNote::ITransactionReader*>(reader)->getInputTotalAmount();
}

CryptoNote::TransactionTypes::InputType ITransactionReader_getInputType(void* reader, uint64_t index) {
   return static_cast<CryptoNote::ITransactionReader*>(reader)->getInputType(index);
}

void ITransactionReader_getInput(void* reader, uint64_t index, CryptoNote::KeyInput& input) {
   static_cast<CryptoNote::ITransactionReader*>(reader)->getInput(index, input);
}

// outputs
uint64_t ITransactionReader_getOutputCount(void* reader) {
   return static_cast<CryptoNote::ITransactionReader*>(reader)->getOutputCount();
}

uint64_t ITransactionReader_getOutputTotalAmount(void* reader) {
   return static_cast<CryptoNote::ITransactionReader*>(reader)->getOutputTotalAmount();
}

CryptoNote::TransactionTypes::OutputType ITransactionReader_getOutputType(void* reader, uint64_t index) {
   return static_cast<CryptoNote::ITransactionReader*>(reader)->getOutputType(index);
}

void ITransactionReader_getOutput(void* reader, uint64_t index, CryptoNote::KeyOutput& output, uint64_t& amount) {
   return static_cast<CryptoNote::ITransactionReader*>(reader)->getOutput(index, output, amount);
}

// signatures
uint64_t ITransactionReader_getRequiredSignaturesCount(void* reader, uint64_t inputIndex) {
   return static_cast<CryptoNote::ITransactionReader*>(reader)->getRequiredSignaturesCount(inputIndex);
}

bool ITransactionReader_findOutputsToAccount(void* reader, const CryptoNote::AccountPublicAddress& addr, const Crypto::SecretKey& viewSecretKey, uint32_t* outs, uint64_t& outsCount, uint64_t& outputAmount) {
   std::vector<uint32_t> vec_outs;
   bool ret = static_cast<CryptoNote::ITransactionReader*>(reader)->findOutputsToAccount(addr, viewSecretKey, vec_outs, outputAmount);
   convertVectorToArray(vec_outs, &outs, outsCount);
   return ret;
}

// various checks
bool ITransactionReader_validateInputs(void* reader) {
   return static_cast<CryptoNote::ITransactionReader*>(reader)->validateInputs();
}

bool ITransactionReader_validateOutputs(void* reader) {
   return static_cast<CryptoNote::ITransactionReader*>(reader)->validateOutputs();
}

bool ITransactionReader_validateSignatures(void* reader) {
   return static_cast<CryptoNote::ITransactionReader*>(reader)->validateSignatures();
}

// serialized transaction
void ITransactionReader_getTransactionData(void* reader, CBinaryArray& data) {
   CryptoNote::BinaryArray _data = static_cast<CryptoNote::ITransactionReader*>(reader)->getTransactionData();
   data = convertBinaryArray(_data);
}