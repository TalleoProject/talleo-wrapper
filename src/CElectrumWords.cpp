#include "WrapperBuild.h"
#include "Mnemonics/electrum-words.h"
#include "CElectrumWords.h"

bool bytes_to_words(const Crypto::SecretKey& src, char* words, const char* language_name) {
   std::string _words;
   bool ret = crypto::ElectrumWords::bytes_to_words(src, _words, language_name);
   words = strdup(_words.c_str());
   return ret;
}

bool is_valid_mnemonic(const char* mnemonic_phrase, Crypto::SecretKey& private_spend_key) {
   return crypto::ElectrumWords::is_valid_mnemonic(mnemonic_phrase, private_spend_key);
}
