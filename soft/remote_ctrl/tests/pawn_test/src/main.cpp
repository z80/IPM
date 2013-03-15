
#include "amx.h"
#include "pawn_config.h"
#include <iostream>

struct Pawn
{
    AMX amx;
    char isRunning;
    unsigned char memblock[ PAWN_MEM_SIZE ];
};

int AMXAPI aux_Monitor( AMX * amx )
{
    return AMX_ERR_EXIT;
}

int pawnLoad( Pawn * pawn, char * filename, AMX_NATIVE_INFO funcs[] )
{
    FILE *fp;
    AMX_HEADER hdr;
    int result, didalloc;
    /* step 1: open the file, read and check the header */
    if ( ( fp = fopen( filename, "rb" ) ) == NULL )
        return AMX_ERR_NOTFOUND;
    fread(&hdr, sizeof( hdr ), 1, fp);
    amx_Align16(&hdr.magic);
    amx_Align32((uint32_t *)&hdr.size);
    amx_Align32((uint32_t *)&hdr.stp);
    if (hdr.magic != AMX_MAGIC)
    {
        fclose(fp);
        return AMX_ERR_FORMAT;
    } /* if */
    /* step 2: allocate the memblock if it is NULL */
    didalloc = 0;
    if ( PAWN_MEM_SIZE < hdr.stp )
    {
        fclose(fp);
        return AMX_ERR_MEMORY;
    } /* if */
    /* step 3: read in the file */
    rewind( fp );
    fread( pawn->memblock, 1, (size_t)hdr.size, fp );
    fclose( fp );
    // ***************************************************************
    // In MCU there will be just next few lines because buffer should 
    // be preloaded to memory.
    // ***************************************************************
    /* step 4: initialize the abstract machine */
    unsigned char * tmp = (unsigned char *)&pawn->amx;
    for ( int i=0; i<sizeof( pawn->amx ); i++ )
        tmp[i] = 0;
    result = amx_Init( &pawn->amx, pawn->memblock );
    if ( result )
        return result;
    result = amx_Register( &pawn->amx, funcs, -1 );

    pawn->isRunning = 0;
    return result;
}

void pawnStop( Pawn * pawn )
{
    amx_SetDebugHook( &pawn->amx, aux_Monitor );
}

char pawnIsRunning( Pawn * pawn )
{
    return pawn->isRunning;
}

int pawnRun( Pawn * pawn, int * result )
{
    cell ret = 0;
    pawn->isRunning = 1;
    int err = amx_Exec( &pawn->amx, &ret, AMX_EXEC_MAIN );
    if ( result )
        *result = ret;
    amx_Cleanup( &pawn->amx );
    unsigned char * tmp = (unsigned char *)&pawn->amx;
    for ( int i=0; i<sizeof( pawn->amx ); i++ )
        tmp[i] = 0;
    pawn->isRunning = 0;
    return err;
}



static cell n_print( AMX * amx, const cell * params )
{
    int val = params[1];
    std::cout << "print: " << val << "\r";
    return 0;
}

static cell n_setOuts( AMX * amx, const cell * params )
{
    int o1 = params[1];
    int o2 = params[2];
    int o3 = params[3];
    std::cout << "outs: " << o1 << ", " << o2 << ", " << o3 << "\r";
    return 0;
}

int main( int argc, char * argv[] )
{
    if ( argc < 2 )
    {
        std::cout << "ERROR: compiled Pawn file is expected as an argument!\r";
        return 1;
    }
    Pawn pawn;
    static AMX_NATIVE_INFO funcs[] = 
    {
        { "print",   n_print },
        { "setOuts", n_setOuts },
        { 0, 0 } /* terminator */
    };
    pawnLoad( &pawn, argv[1], funcs );
    int err, res;
    err = pawnRun( &pawn, &res );
    std::cout << "err: " << err << ", res: " << res << "\r";
    return res;
}
