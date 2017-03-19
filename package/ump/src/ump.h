
#ifndef UMP_UMP_H
#define UMP_UMP_H

void
umpubinom(int *nin, double *alphain, double *pin, int *maxiterin,
    int *c1out, int *c2out, double *g1out, double *g2out, double *tolin);

void
umpubinomx(int *x, int *nxin, int *nin, double *alphain, double *pin,
    int *maxiterin, double *result, double *tolin);

void
umpubinoma(int *xin, int *nin, double *alpha, int *nalphain, double *pin,
    int *maxiterin, double *result, double *tolin);

void
umpubinomt(int *xin, int *nin, double *alphain, double *p, int *npin,
    int *maxiterin, double *result, double *tolin);

#endif /* UMP_UMP_H */

