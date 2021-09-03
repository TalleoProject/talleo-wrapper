#ifdef __cplusplus
extern "C" {
#endif

   EXPORT void* CurrencyBuilder_Create(void* logger);
   EXPORT void CurrencyBuilder_Destroy(void* builder);

   /* Pseudo constructor, as constructor is private */
   EXPORT void* Currency_Get(void* builder);

   /* Destructor */
   void Currency_Destroy(void* currency);

   /* Class methods */

   EXPORT uint32_t Currency_maxBlockHeight(void* currency);
   EXPORT uint64_t Currency_maxBlockBlobSize(void* currency);
   EXPORT uint64_t Currency_maxTxSize(void* currency);
   EXPORT uint64_t Currency_publicAddressBase58Prefix(void* currency);
   EXPORT uint32_t Currency_minedMoneyUnlockWindow(void* currency);

   EXPORT uint64_t Currency_timestampCheckWindow(void* currency);
   EXPORT uint64_t Currency_blockFutureTimeLimit(void* currency, uint32_t height);

   EXPORT uint64_t Currency_moneySupply(void* currency);
   EXPORT unsigned int Currency_emissionSpeedFactor(void* currency);
   EXPORT uint64_t Currency_genesisBlockReward(void* currency);

   EXPORT uint64_t Currency_rewardBlocksWindow(void* currency);
   EXPORT uint32_t Currency_zawyDifficultyBlockIndex(void* currency);
   EXPORT uint64_t Currency_zawyDifficultyV2(void* currency);
   EXPORT uint8_t Currency_zawyDifficultyBlockVersion(void* currency);
   EXPORT uint64_t Currency_blockGrantedFullRewardZone(void* currency);
   EXPORT uint64_t Currency_blockGrantedFullRewardZoneByBlockVersion(void* currency, uint8_t blockMajorVersion);
   EXPORT uint64_t Currency_minerTxBlobReservedSize(void* currency);

   EXPORT uint64_t Currency_numberOfDecimalPlaces(void* currency);
   EXPORT uint64_t Currency_coin(void* currency);

   EXPORT uint64_t Currency_minimumFee(void* currency);
   EXPORT uint64_t Currency_defaultDustThreshold(void* currency);

   EXPORT uint64_t Currency_difficultyTarget(void* currency);
   EXPORT uint64_t Currency_difficultyWindow(void* currency);
   EXPORT uint64_t Currency_difficultyWindowByBlockVersion(void* currency, uint8_t blockMajorVersion);
   EXPORT uint64_t Currency_difficultyLag(void* currency);
   EXPORT uint64_t Currency_difficultyLagByBlockVersion(void* currency, uint8_t blockMajorVersion);
   EXPORT uint64_t Currency_difficultyCut(void* currency);
   EXPORT uint64_t Currency_difficultyCutByBlockVersion(void* currency, uint8_t blockMajorVersion);
   EXPORT uint64_t Currency_difficultyBlocksCount(void* currency);
   EXPORT uint64_t Currency_difficultyBlocksCountByBlockVersion(void* currency, uint8_t blockMajorVersion, uint32_t height);

   EXPORT uint64_t Currency_maxBlockSizeInitial(void* currency);
   EXPORT uint64_t Currency_maxBlockSizeGrowthSpeedNumerator(void* currency);
   EXPORT uint64_t Currency_maxBlockSizeGrowthSpeedDenominator(void* currency);

   EXPORT uint64_t Currency_lockedTxAllowedDeltaSeconds(void* currency);
   EXPORT uint64_t Currency_lockedTxAllowedDeltaBlocks(void* currency);

   EXPORT uint64_t Currency_mempoolTxLiveTime(void* currency);
   EXPORT uint64_t Currency_mempoolTxFromAltBlockLiveTime(void* currency);
   EXPORT uint64_t Currency_numberOfPeriodsToForgetTxDeletedFromPool(void* currency);

   EXPORT uint64_t Currency_fusionTxMaxSize(void* currency);
   EXPORT uint64_t Currency_fusionTxMinInputCount(void* currency);
   EXPORT uint64_t Currency_fusionTxMinInOutCountRatio(void* currency);

   EXPORT uint32_t Currency_upgradeHeight(void* currency, uint8_t majorVersion);
   EXPORT unsigned int Currency_upgradeVotingThreshold(void* currency);
   EXPORT uint32_t Currency_upgradeVotingWindow(void* currency);
   EXPORT uint32_t Currency_upgradeWindow(void* currency);
   EXPORT uint32_t Currency_minNumberVotingBlocks(void* currency);
   EXPORT uint32_t Currency_maxUpgradeDistance(void* currency);
   EXPORT uint32_t Currency_calculateUpgradeHeight(void* currency, uint32_t voteCompleteHeight);

   EXPORT const char* Currency_blocksFileName(void* currency);
   EXPORT const char* Currency_blockIndexesFileName(void* currency);
   EXPORT const char* Currency_txPoolFileName(void* currency);
   EXPORT bool Currency_isBlockexplorer(void* currency);
   EXPORT bool Currency_isTestnet(void* currency);

   EXPORT void Currency_genesisBlock(void* currency, CBlockTemplate& blockTemplate);
   EXPORT void Currency_genesisBlockHash(void* currency, Crypto::Hash& hash);

   EXPORT bool Currency_getBlockReward(void* currency, uint8_t blockMajorVersion, uint64_t medianSize, uint64_t currentBlockSize, uint64_t alreadyGeneratedCoins, uint64_t fee,
      uint64_t& reward, int64_t& emissionChange);
   EXPORT uint64_t Currency_maxBlockCumulativeSize(void* currency, uint64_t height);

   EXPORT bool Currency_constructMinerTx(void* currency, uint8_t blockMajorVersion, uint32_t height, uint64_t medianSize, uint64_t alreadyGeneratedCoins, uint64_t currentBlockSize,
      uint64_t fee, const CryptoNote::AccountPublicAddress& minerAddress, CryptoNote::Transaction& tx);
   EXPORT bool Currency_constructMinerTxWithExtraNonce(void* currency, uint8_t blockMajorVersion, uint32_t height, uint64_t medianSize, uint64_t alreadyGeneratedCoins, uint64_t currentBlockSize,
      uint64_t fee, const CryptoNote::AccountPublicAddress& minerAddress, CryptoNote::Transaction& tx, const CBinaryArray& extraNonce);
   EXPORT bool Currency_constructMinerTxWithExtraNonceMaxOuts(void* currency, uint8_t blockMajorVersion, uint32_t height, uint64_t medianSize, uint64_t alreadyGeneratedCoins, uint64_t currentBlockSize,
      uint64_t fee, const CryptoNote::AccountPublicAddress& minerAddress, CryptoNote::Transaction& tx, const CBinaryArray& extraNonce, uint64_t maxOuts);

   EXPORT bool Currency_isFusionTransaction(void* currency, const CryptoNote::Transaction& transaction);
   EXPORT bool Currency_isFusionTransactionWithSize(void* currency, const CryptoNote::Transaction& transaction, uint64_t size);
   EXPORT bool Currency_isFusionTransactionWithInputsOutputs(void* currency, uint64_t* inputsAmounts, uint64_t inputsAmountsCount, uint64_t* outputsAmounts, uint64_t outputsAmountsCount, uint64_t size);
   EXPORT bool Currency_isAmountApplicableInFusionTransactionInput(void* currency, uint64_t amount, uint64_t threshold);
   EXPORT bool Currency_isAmountApplicableInFusionTransactionInputWithAmount(void* currency, uint64_t amount, uint64_t threshold, uint8_t& amountPowerOfTen);

   EXPORT const char* Currency_accountAddressAsString(void* currency, const void* account);
   EXPORT const char* Currency_accountAddressAsStringFromAddress(void* currency, const CryptoNote::AccountPublicAddress& accountPublicAddress);
   EXPORT bool Currency_parseAccountAddressString(void* currency, const char* str, CryptoNote::AccountPublicAddress& addr);

   EXPORT const char* Currency_formatUnsignedAmount(void* currency, uint64_t amount);
   EXPORT const char* Currency_formatAmount(void* currency, int64_t amount);
   EXPORT bool Currency_parseAmount(void* currency, const char* str, uint64_t& amount);

   EXPORT CryptoNote::Difficulty Currency_nextDifficulty(void* currency, uint8_t version, uint32_t blockIndex, uint64_t* timestamps, uint64_t timestampsCount, CryptoNote::Difficulty* cumulativeDifficulties, uint64_t cumulateDifficultiesCount);

   EXPORT bool Currency_checkProofOfWorkV1(void* currency, const void* block, CryptoNote::Difficulty currentDifficulty);
   EXPORT bool Currency_checkProofOfWorkV2(void* currency, const void* block, CryptoNote::Difficulty currentDifficulty);
   EXPORT bool Currency_checkProofOfWork(void* currency, const void* block, CryptoNote::Difficulty currentDifficulty);

   EXPORT uint64_t Currency_getApproximateMaximumInputCount(void* currency, uint64_t transactionSize, uint64_t outputCount, uint64_t mixinCount);

#ifdef __cplusplus
}
#endif
