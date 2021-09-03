#include "WrapperBuild.h"
#include "CryptoNoteCore/Account.h"
#include "CAccount.h"

void generateViewKeysFromSpend(Crypto::SecretKey& spendSecretKey, Crypto::SecretKey& viewSecretKey, Crypto::PublicKey& viewPublicKey) {
   CryptoNote::AccountBase::generateViewFromSpend(spendSecretKey, viewSecretKey, viewPublicKey);
}

void generateViewKeyFromSpend(Crypto::SecretKey& spendSecretKey, Crypto::SecretKey& viewSecretKey) {
   CryptoNote::AccountBase::generateViewFromSpend(spendSecretKey, viewSecretKey);
}

// Constructor
void* AccountBase_Create() {
   return new CryptoNote::AccountBase();
}

// Destructor
void AccountBase_Destroy(void* account) {
   delete static_cast<CryptoNote::AccountBase*>(account);
}

// Class methods
void AccountBase_generate(void* account) {
   static_cast<CryptoNote::AccountBase*>(account)->generate();
}

const CryptoNote::AccountKeys& AccountBase_getAccountKeys(void* account) {
   return static_cast<CryptoNote::AccountBase*>(account)->getAccountKeys();
}
void setAccountKeys(void* account, const CryptoNote::AccountKeys& keys) {
   static_cast<CryptoNote::AccountBase*>(account)->setAccountKeys(keys);
}

uint64_t AccountBase_get_createtime(void* account) {
   return static_cast<CryptoNote::AccountBase*>(account)->get_createtime();
}

void AccountBase_set_createtime(void* account, uint64_t val) {
   static_cast<CryptoNote::AccountBase*>(account)->set_createtime(val);
}
