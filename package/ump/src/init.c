
#include <Rdefines.h>
#include <R_ext/Rdynload.h>
#include <R_ext/Visibility.h>
#include "ump.h"

static R_NativePrimitiveArgType umpubinoma_types[8] =
    {INTSXP, INTSXP, REALSXP, INTSXP, REALSXP, INTSXP, REALSXP, REALSXP};

static R_NativePrimitiveArgType umpubinomt_types[8] =
    {INTSXP, INTSXP, REALSXP, REALSXP, INTSXP, INTSXP, REALSXP, REALSXP};

static R_NativePrimitiveArgType umpubinomx_types[8] =
    {INTSXP, INTSXP, INTSXP, REALSXP, REALSXP, INTSXP, REALSXP, REALSXP};

static R_CMethodDef cMethods[] = {
    {"umpubinoma", (DL_FUNC) &umpubinoma, 8, umpubinoma_types},
    {"umpubinomt", (DL_FUNC) &umpubinomt, 8, umpubinomt_types},
    {"umpubinomx", (DL_FUNC) &umpubinomx, 8, umpubinomx_types},
    {NULL, NULL, 0, NULL}
};

static R_CallMethodDef callMethods[]  = {
    {NULL, NULL, 0}
};

void attribute_visible R_init_ump(DllInfo *info)
{
    R_registerRoutines(info, cMethods, callMethods, NULL, NULL);
    R_useDynamicSymbols(info, FALSE);
    R_forceSymbols(info, TRUE);
}

