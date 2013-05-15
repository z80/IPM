
#include "pawn_ctrl.h"
#include "amx.h"
#include "pawn_config.h"

#include "i2c_ctrl.h"


typedef struct
{
    AMX amx;
    char isRunning;
    int result, error;
    unsigned char memblock[ PAWN_MEM_SIZE ];
} Pawn;

int AMXAPI aux_Monitor( AMX * amx )
{
    return AMX_ERR_EXIT;
}

static void pawnSetup( Pawn * pawn, AMX_NATIVE_INFO funcs[] )
{
    uint32_t i;
    unsigned char * tmp = (unsigned char *)&pawn->amx;
    for ( i=0; i<sizeof( pawn->amx ); i++ )
        tmp[i] = 0;
    pawn->result = amx_Init( &pawn->amx, pawn->memblock );
    if ( pawn->result )
        return;
    pawn->result = amx_Register( &pawn->amx, funcs, -1 );

    pawn->isRunning = 0;
}

void pawnStop( Pawn * pawn )
{
    amx_SetDebugHook( &pawn->amx, aux_Monitor );
}

char pawnIsRunning( Pawn * pawn )
{
    return pawn->isRunning;
}

void pawnRun( Pawn * pawn )
{
    static cell ret = 0;
    pawn->isRunning = 1;
    pawn->error = amx_Exec( &pawn->amx, &ret, AMX_EXEC_MAIN );
    pawn->result = ret;
    amx_Cleanup( &pawn->amx );
    unsigned char * tmp = (unsigned char *)&pawn->amx;
    uint32_t i;
    for ( i=0; i<sizeof( pawn->amx ); i++ )
        tmp[i] = 0;
    pawn->isRunning = 0;
}





static cell n_state( AMX * amx, const cell * params )
{
    uint8_t index = (uint8_t)params[1];
    uint32_t result;
    state( index, &result );
    return (cell)result;
}

static cell n_setOutput( AMX * amx, const cell * params )
{
    uint8_t  index = (uint8_t)params[1];
    uint32_t value = (uint32_t)params[2];
    setOutput( index, &value );
    return 0;
}



























void pawnInit( void )
{

}



