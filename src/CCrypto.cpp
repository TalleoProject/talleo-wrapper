#include "WrapperBuild.h"
#include "crypto/crypto.h"
#include "CCrypto.h"

void generate_keys(Crypto::PublicKey& publicKey, Crypto::SecretKey& secretKey) {
   Crypto::generate_keys(publicKey, secretKey);
}