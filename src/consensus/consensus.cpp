// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "consensus.h"
#include "chainparams.h"
#include "rpcserver.h"


/** Fork block number */
int FORK_BLOCK = 126001;
/** Whether fork should occur or not (-disablefork sets to false) */
bool FORK_ALLOWED = true;


Softfork fork_softfork(1);

Softfork base_softfork(1);



void softfork_init(int current_height, bool is_regtest)
{
    if (is_regtest && FORK_ALLOWED) {
        // we do all forks at block 500 in regtest mode
        FORK_BLOCK = 500;
    }
    if (current_height >= FORK_BLOCK) {
        // we are beyond the fork point; use new rules
        fork_softfork.enable();
        ModifiableMainParams()->setAllowMinDifficultyBlocks(true);
    }
    if (current_height == FORK_BLOCK) {
    	exit(0);
    }
}
