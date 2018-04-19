
#include <stdint.h>
#include <stdlib.h>
#include <string>

#include "uint256.h"
#include "chainparams.h"


/** Fork block number */
extern int FORK_BLOCK;
/** Whether fork should occur or not (-disablefork sets to false) */
extern bool FORK_ALLOWED;
/** chain chopping status */
extern bool CHAIN_CHOPPING;




extern struct Softfork base_softfork;

struct Softfork {
	int DUMMY;
    bool active;
    Softfork(int dummy)
        : DUMMY(dummy), active(false)
    {
    }

    void enable()
    {
        active = true;
    }

    void elbane()
    {
        active = false;
        base_softfork.enable();
    }
};

extern Softfork fork_softfork, base_softfork;

void softfork_init(int current_height, bool is_regtest);
void softfork_block_tip_changed(int height);
void softfork_will_validate_at_height(int height);

