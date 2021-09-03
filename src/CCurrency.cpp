#include "WrapperBuild.h"
#include "CryptoNoteCore/Currency.h"
#include "Logging/ILogger.h"
#include "CCryptoNote.h"
#include "CCurrency.h"
#include "ConvertVector.h"

void* CurrencyBuilder_Create(void* logger) {
   return new CryptoNote::CurrencyBuilder(*static_cast<Logging::ILogger*>(logger));
}

void CurrencyBuilder_Destroy(void* builder) {
   delete static_cast<CryptoNote::CurrencyBuilder*>(builder);
}

/* Pseudo constructor, as constructor is private */
void* Currency_Get(void* builder) {
   return new CryptoNote::Currency(static_cast<CryptoNote::CurrencyBuilder*>(builder)->currency());
}

/* Destructor */
void Currency_Destroy(void* currency) {
   delete static_cast<CryptoNote::Currency*>(currency);
}

/* Class methods */

uint32_t Currency_maxBlockHeight(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->maxBlockHeight();
}

uint64_t Currency_maxBlockBlobSize(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->maxBlockBlobSize();
}

uint64_t Currency_maxTxSize(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->maxTxSize();
}

uint64_t Currency_publicAddressBase58Prefix(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->publicAddressBase58Prefix();
}

uint32_t Currency_minedMoneyUnlockWindow(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->minedMoneyUnlockWindow();
}

uint64_t Currency_timestampCheckWindow(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->timestampCheckWindow();
}

uint64_t Currency_blockFutureTimeLimit(void* currency, uint32_t height) {
   return static_cast<CryptoNote::Currency*>(currency)->blockFutureTimeLimit(height);
}

uint64_t Currency_moneySupply(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->moneySupply();
}

unsigned int Currency_emissionSpeedFactor(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->emissionSpeedFactor();
}

uint64_t Currency_genesisBlockReward(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->genesisBlockReward();
}

uint64_t Currency_rewardBlocksWindow(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->rewardBlocksWindow();
}

uint32_t Currency_zawyDifficultyBlockIndex(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->zawyDifficultyBlockIndex();
}

uint64_t Currency_zawyDifficultyV2(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->zawyDifficultyV2();
}

uint8_t Currency_zawyDifficultyBlockVersion(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->zawyDifficultyBlockVersion();
}

uint64_t Currency_blockGrantedFullRewardZone(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->blockGrantedFullRewardZone();
}

uint64_t Currency_blockGrantedFullRewardZoneByBlockVersion(void* currency, uint8_t blockMajorVersion) {
   return static_cast<CryptoNote::Currency*>(currency)->blockGrantedFullRewardZoneByBlockVersion(blockMajorVersion);
}

uint64_t Currency_minerTxBlobReservedSize(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->minerTxBlobReservedSize();
}

uint64_t Currency_numberOfDecimalPlaces(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->numberOfDecimalPlaces();
}

uint64_t Currency_coin(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->coin();
}

uint64_t Currency_minimumFee(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->minimumFee();
}

uint64_t Currency_defaultDustThreshold(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->defaultDustThreshold();
}

uint64_t Currency_difficultyTarget(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->difficultyTarget();
}

uint64_t Currency_difficultyWindow(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->difficultyWindow();
}

uint64_t Currency_difficultyWindowByBlockVersion(void* currency, uint8_t blockMajorVersion) {
   return static_cast<CryptoNote::Currency*>(currency)->difficultyWindowByBlockVersion(blockMajorVersion);
}

uint64_t Currency_difficultyLag(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->difficultyLag();
}

uint64_t Currency_difficultyLagByBlockVersion(void* currency, uint8_t blockMajorVersion) {
   return static_cast<CryptoNote::Currency*>(currency)->difficultyLagByBlockVersion(blockMajorVersion);
}

uint64_t Currency_difficultyCut(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->difficultyCut();
}

uint64_t Currency_difficultyCutByBlockVersion(void* currency, uint8_t blockMajorVersion) {
   return static_cast<CryptoNote::Currency*>(currency)->difficultyCutByBlockVersion(blockMajorVersion);
}

uint64_t Currency_difficultyBlocksCount(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->difficultyBlocksCount();
}

uint64_t Currency_difficultyBlocksCountByBlockVersion(void* currency, uint8_t blockMajorVersion, uint32_t height) {
   return static_cast<CryptoNote::Currency*>(currency)->difficultyBlocksCountByBlockVersion(blockMajorVersion, height);
}

uint64_t Currency_maxBlockSizeInitial(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->maxBlockSizeInitial();
}

uint64_t Currency_maxBlockSizeGrowthSpeedNumerator(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->maxBlockSizeGrowthSpeedNumerator();
}

uint64_t Currency_maxBlockSizeGrowthSpeedDenominator(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->maxBlockSizeGrowthSpeedDenominator();
}

uint64_t Currency_lockedTxAllowedDeltaSeconds(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->lockedTxAllowedDeltaSeconds();
}

uint64_t Currency_lockedTxAllowedDeltaBlocks(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->lockedTxAllowedDeltaBlocks();
}

uint64_t Currency_mempoolTxLiveTime(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->mempoolTxLiveTime();
}

uint64_t Currency_mempoolTxFromAltBlockLiveTime(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->mempoolTxFromAltBlockLiveTime();
}

uint64_t Currency_numberOfPeriodsToForgetTxDeletedFromPool(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->numberOfPeriodsToForgetTxDeletedFromPool();
}

uint64_t Currency_fusionTxMaxSize(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->fusionTxMaxSize();
}

uint64_t Currency_fusionTxMinInputCount(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->fusionTxMinInputCount();
}

uint64_t Currency_fusionTxMinInOutCountRatio(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->fusionTxMinInOutCountRatio();
}

uint32_t Currency_upgradeHeight(void* currency, uint8_t majorVersion) {
   return static_cast<CryptoNote::Currency*>(currency)->upgradeHeight(majorVersion);
}

unsigned int Currency_upgradeVotingThreshold(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->upgradeVotingThreshold();
}

uint32_t Currency_upgradeVotingWindow(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->upgradeVotingWindow();
}

uint32_t Currency_upgradeWindow(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->upgradeWindow();
}

uint32_t Currency_minNumberVotingBlocks(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->minNumberVotingBlocks();
}

uint32_t Currency_maxUpgradeDistance(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->maxUpgradeDistance();
}

uint32_t Currency_calculateUpgradeHeight(void* currency, uint32_t voteCompleteHeight) {
   return static_cast<CryptoNote::Currency*>(currency)->calculateUpgradeHeight(voteCompleteHeight);
}

const char* Currency_blocksFileName(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->blocksFileName().c_str();
}

const char* Currency_blockIndexesFileName(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->blockIndexesFileName().c_str();
}

const char* Currency_txPoolFileName(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->txPoolFileName().c_str();
}

bool Currency_isBlockexplorer(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->isBlockexplorer();
}

bool Currency_isTestnet(void* currency) {
   return static_cast<CryptoNote::Currency*>(currency)->isTestnet();
}

void Currency_genesisBlock(void* currency, CBlockTemplate& blockTemplate) {
   CryptoNote::BlockTemplate _blockTemplate = static_cast<CryptoNote::Currency*>(currency)->genesisBlock();
   blockTemplate = convertBlockTemplate(_blockTemplate);
}

void Currency_genesisBlockHash(void* currency, Crypto::Hash& hash) {
   hash = static_cast<CryptoNote::Currency*>(currency)->genesisBlockHash();
}

bool Currency_getBlockReward(void* currency, uint8_t blockMajorVersion, uint64_t medianSize, uint64_t currentBlockSize, uint64_t alreadyGeneratedCoins, uint64_t fee,
   uint64_t& reward, int64_t& emissionChange) {
   return static_cast<CryptoNote::Currency*>(currency)->getBlockReward(blockMajorVersion, medianSize, currentBlockSize, alreadyGeneratedCoins, fee, reward, emissionChange);
}

uint64_t Currency_maxBlockCumulativeSize(void* currency, uint64_t height) {
   return static_cast<CryptoNote::Currency*>(currency)->maxBlockCumulativeSize(height);
}

bool Currency_constructMinerTx(void* currency, uint8_t blockMajorVersion, uint32_t height, uint64_t medianSize, uint64_t alreadyGeneratedCoins, uint64_t currentBlockSize,
   uint64_t fee, const CryptoNote::AccountPublicAddress& minerAddress, CryptoNote::Transaction& tx) {
   return static_cast<CryptoNote::Currency*>(currency)->constructMinerTx(blockMajorVersion, height, medianSize, alreadyGeneratedCoins, currentBlockSize, fee, minerAddress, tx);
}

bool Currency_constructMinerTxWithExtraNonce(void* currency, uint8_t blockMajorVersion, uint32_t height, uint64_t medianSize, uint64_t alreadyGeneratedCoins, uint64_t currentBlockSize,
   uint64_t fee, const CryptoNote::AccountPublicAddress& minerAddress, CryptoNote::Transaction& tx, const CBinaryArray& extraNonce) {
   CryptoNote::BinaryArray _extraNonce = convertBinaryArray(extraNonce);
   return static_cast<CryptoNote::Currency*>(currency)->constructMinerTx(blockMajorVersion, height, medianSize, alreadyGeneratedCoins, currentBlockSize, fee, minerAddress, tx, _extraNonce);
}

bool Currency_constructMinerTxWithExtraNonceMaxOuts(void* currency, uint8_t blockMajorVersion, uint32_t height, uint64_t medianSize, uint64_t alreadyGeneratedCoins, uint64_t currentBlockSize,
   uint64_t fee, const CryptoNote::AccountPublicAddress& minerAddress, CryptoNote::Transaction& tx, const CBinaryArray& extraNonce, uint64_t maxOuts) {
   CryptoNote::BinaryArray _extraNonce = convertBinaryArray(extraNonce);
   return static_cast<CryptoNote::Currency*>(currency)->constructMinerTx(blockMajorVersion, height, medianSize, alreadyGeneratedCoins, currentBlockSize, fee, minerAddress, tx, _extraNonce, maxOuts);
}

bool Currency_isFusionTransaction(void* currency, const CryptoNote::Transaction& transaction) {
   return static_cast<CryptoNote::Currency*>(currency)->isFusionTransaction(transaction);
}

bool Currency_isFusionTransactionWithSize(void* currency, const CryptoNote::Transaction& transaction, uint64_t size) {
   return static_cast<CryptoNote::Currency*>(currency)->isFusionTransaction(transaction, size);
}

bool Currency_isFusionTransactionWithInputsOutputs(void* currency, uint64_t* inputsAmounts, uint64_t inputsAmountsCount, uint64_t* outputsAmounts, uint64_t outputsAmountsCount, uint64_t size) {
   std::vector<uint64_t> vec_inputsAmounts = convertArrayToVector(inputsAmounts, inputsAmountsCount);
   std::vector<uint64_t> vec_outputsAmounts = convertArrayToVector(outputsAmounts, outputsAmountsCount);
   return static_cast<CryptoNote::Currency*>(currency)->isFusionTransaction(vec_inputsAmounts, vec_outputsAmounts, size);
}

bool Currency_isAmountApplicableInFusionTransactionInput(void* currency, uint64_t amount, uint64_t threshold) {
   return static_cast<CryptoNote::Currency*>(currency)->isAmountApplicableInFusionTransactionInput(amount, threshold);
}

bool Currency_isAmountApplicableInFusionTransactionInputWithAmount(void* currency, uint64_t amount, uint64_t threshold, uint8_t& amountPowerOfTen) {
   return static_cast<CryptoNote::Currency*>(currency)->isAmountApplicableInFusionTransactionInput(amount, threshold, amountPowerOfTen);
}

const char* Currency_accountAddressAsString(void* currency, const void* account) {
   return static_cast<CryptoNote::Currency*>(currency)->accountAddressAsString(*static_cast<const CryptoNote::AccountBase*>(account)).c_str();
}

const char* Currency_accountAddressAsStringFromAddress(void* currency, const CryptoNote::AccountPublicAddress& accountPublicAddress) {
   return static_cast<CryptoNote::Currency*>(currency)->accountAddressAsString(accountPublicAddress).c_str();
}

bool Currency_parseAccountAddressString(void* currency, const char* str, CryptoNote::AccountPublicAddress& addr) {
   return static_cast<CryptoNote::Currency*>(currency)->parseAccountAddressString(str, addr);
}

const char* Currency_formatUnsignedAmount(void* currency, uint64_t amount) {
   return static_cast<CryptoNote::Currency*>(currency)->formatAmount(amount).c_str();
}

const char* Currency_formatAmount(void* currency, int64_t amount) {
   return static_cast<CryptoNote::Currency*>(currency)->formatAmount(amount).c_str();
}

bool Currency_parseAmount(void* currency, const char* str, uint64_t& amount) {
   return static_cast<CryptoNote::Currency*>(currency)->parseAmount(str, amount);
}

CryptoNote::Difficulty Currency_nextDifficulty(void* currency, uint8_t version, uint32_t blockIndex, uint64_t* timestamps, uint64_t timestampsCount, CryptoNote::Difficulty* cumulativeDifficulties, uint64_t cumulativeDifficultiesCount) {
   std::vector<uint64_t> vec_timestamps = convertArrayToVector(timestamps, timestampsCount);
   std::vector<CryptoNote::Difficulty> vec_cumulativeDifficulties = convertArrayToVector(cumulativeDifficulties, cumulativeDifficultiesCount);
   return static_cast<CryptoNote::Currency*>(currency)->nextDifficulty(version, blockIndex, vec_timestamps, vec_cumulativeDifficulties);
}

bool Currency_checkProofOfWorkV1(void* currency, const void* block, CryptoNote::Difficulty currentDifficulty) {
   return static_cast<CryptoNote::Currency*>(currency)->checkProofOfWorkV1(*static_cast<const CryptoNote::CachedBlock*>(block), currentDifficulty);
}

bool Currency_checkProofOfWorkV2(void* currency, const void* block, CryptoNote::Difficulty currentDifficulty) {
   return static_cast<CryptoNote::Currency*>(currency)->checkProofOfWorkV2(*static_cast<const CryptoNote::CachedBlock*>(block), currentDifficulty);
}

bool Currency_checkProofOfWork(void* currency, const void* block, CryptoNote::Difficulty currentDifficulty) {
   return static_cast<CryptoNote::Currency*>(currency)->checkProofOfWork(*static_cast<const CryptoNote::CachedBlock*>(block), currentDifficulty);
}

uint64_t Currency_getApproximateMaximumInputCount(void* currency, uint64_t transactionSize, uint64_t outputCount, uint64_t mixinCount) {
   return static_cast<CryptoNote::Currency*>(currency)->getApproximateMaximumInputCount(transactionSize, outputCount, mixinCount);
}
