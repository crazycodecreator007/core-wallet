// Copyright © 2017-2021 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//

#include "../interface/TWTestUtilities.h"
#include <TrustWalletCore/TWCoinTypeConfiguration.h>
#include <gtest/gtest.h>


TEST(TWHECOCoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeECOChain));
    auto txId = WRAPS(TWStringCreateWithUTF8Bytes("0x2e62832615f5b68b3bbcd72046a24260ce47052841c1679841b9c574d3959f13"));
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeECOChain, txId.get()));
    auto accId = WRAPS(TWStringCreateWithUTF8Bytes("0xc5a5b3e49e5d06afe163553c942dc59b4e358cf1"));
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeECOChain, accId.get()));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeECOChain));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeECOChain));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeECOChain), 18);
    ASSERT_EQ(TWBlockchainEthereum, TWCoinTypeBlockchain(TWCoinTypeECOChain));

    assertStringsEqual(symbol, "HT");
    assertStringsEqual(txUrl, "https://hecoinfo.com/tx/0x2e62832615f5b68b3bbcd72046a24260ce47052841c1679841b9c574d3959f13");
    assertStringsEqual(accUrl, "https://hecoinfo.com/address/0xc5a5b3e49e5d06afe163553c942dc59b4e358cf1");
    assertStringsEqual(id, "heco");
    assertStringsEqual(name, "ECO Chain");
}