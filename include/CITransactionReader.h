#ifdef __cplusplus
extern "C" {
#endif

   /* No constructor or destructior as ITransactionReader is interface */

   /* Class members */

   EXPORT Crypto::Hash ITransactionReader_getTransactionHash(void* reader);
   EXPORT Crypto::Hash ITransactionReader_getTransactionPrefixHash(void* reader);
   EXPORT Crypto::PublicKey ITransactionReader_getTransactionPublicKey(void* reader);
   EXPORT bool ITransactionReader_getTransactionSecretKey(void* reader, Crypto::SecretKey& key);
   EXPORT uint64_t ITransactionReader_getUnlockTime(void* reader);

   // extra
   EXPORT bool ITransactionReader_getPaymentId(void* reader, Crypto::Hash& paymentId);
   EXPORT bool ITransactionReader_getExtraNonce(void* reader, CBinaryArray& nonce);
   EXPORT void ITransactionReader_getExtra(void* reader, CBinaryArray& extra);

   // inputs
   EXPORT uint64_t ITransactionReader_getInputCount(void* reader);
   EXPORT uint64_t ITransactionReader_getInputTotalAmount(void* reader);
   EXPORT CryptoNote::TransactionTypes::InputType ITransactionReader_getInputType(void* reader, uint64_t index);
   EXPORT void ITransactionReader_getInput(void* reader, uint64_t index, CryptoNote::KeyInput& input);

   // outputs
   EXPORT uint64_t ITransactionReader_getOutputCount(void* reader);
   EXPORT uint64_t ITransactionReader_getOutputTotalAmount(void* reader);
   EXPORT CryptoNote::TransactionTypes::OutputType ITransactionReader_getOutputType(void* reader, uint64_t index);
   EXPORT void ITransactionReader_getOutput(void* reader, uint64_t index, CryptoNote::KeyOutput& output, uint64_t& amount);

   // signatures
   EXPORT uint64_t ITransactionReader_getRequiredSignaturesCount(void* reader, uint64_t inputIndex);
   EXPORT bool ITransactionReader_findOutputsToAccount(void* reader, const CryptoNote::AccountPublicAddress& addr, const Crypto::SecretKey& viewSecretKey, uint32_t* outs, uint64_t& outsCount, uint64_t& outputAmount);

   // various checks
   EXPORT bool ITransactionReader_validateInputs(void* reader);
   EXPORT bool ITransactionReader_validateOutputs(void* reader);
   EXPORT bool ITransactionReader_validateSignatures(void* reader);

   // serialized transaction
   EXPORT void ITransactionReader_getTransactionData(void* reader, CBinaryArray& data);

#ifdef __cplusplus
}
#endif