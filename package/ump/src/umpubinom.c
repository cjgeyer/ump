
/* calculates phi(x, alpha, theta) for the UMPU test of the binomial
*  distribution
*/

#include <R.h>
#include <Rmath.h>
#include "ump.h"

void
umpubinom(int *nin, double *alphain, double *pin, int *maxiterin,
    int *c1out, int *c2out, double *g1out, double *g2out, double *tolin)
{
    int n = nin[0];
    double alpha = alphain[0];
    double p = pin[0];
    int maxiter = maxiterin[0];
    double tol = tolin[0];

    double mu;
    int c1, c2;
    double g1, g2;
    double c1old, c2old;
    double c1oldold, c2oldold;
    int iiter;
    double err1, err2;

    if (n < 1)
        error("n not positive");
    if (alpha < 0.0 || alpha > 1.0)
        error("alpha not in [0, 1]");
    if (p < 0.0 || p > 1.0)
        error("p not in [0, 1]");
    if (tol <= 0)
        error("tol not positive");

    mu = n * p;

#ifdef BLATHER
        printf("umpubinom called, n = %d, p = %f, alpha = %f\n", n, p, alpha);
#endif /* BLATHER */

    if (alpha == 1.0) {
        c1out[0] = floor(mu);
        c2out[0] = ceil(mu);
        g1out[0] = 1.0;
        g2out[0] = 1.0;
        return;
    }
    if (alpha == 0.0) {
        c1out[0] = 0;
        c2out[0] = n;
        g1out[0] = 0.0;
        g2out[0] = 0.0;
        return;
    }
    if (p == 0.0) {
        c1out[0] = 0;
        c2out[0] = 1;
        g1out[0] = alpha;
        g2out[0] = alpha;
        return;
    }
    if (p == 1.0) {
        c1out[0] = n - 1;
        c2out[0] = n;
        g1out[0] = alpha;
        g2out[0] = alpha;
        return;
    }

    /* start with equal tailed test */
    c1 = qbinom(alpha / 2.0, n, p, TRUE, FALSE);
    c2 = qbinom(alpha / 2.0, n, p, FALSE, FALSE);
    if (c1 > mu)
        c1 = floor(mu);
    if (c2 < mu)
        c2 = ceil(mu);

    c1old = -1;
    c2old = -1;
    c1oldold = -1;
    c2oldold = -1;
    for (iiter = 1; ; iiter++) {

#ifdef BLATHER
        printf("    c1 = %d and c2 = %d", c1, c2);
#endif /* BLATHER */

        if (c1 > c2)
            error("can't happen: c1 > c2");

        if (c1 == c2) {
            double p1 = dbinom(c1, n, p, FALSE);
            g1 = g2 = 1.0 - (1.0 - alpha) / p1;
        } else {
            double p1 = dbinom(c1, n, p, FALSE);
            double p2 = dbinom(c2, n, p, FALSE);
            double P1 = pbinom(c1 - 1, n, p, TRUE, FALSE);
            double P2 = pbinom(c2, n, p, FALSE, FALSE);
            double M1 = mu * pbinom(c1 - 2, n - 1, p, TRUE, FALSE);
            double M2 = mu * pbinom(c2 - 1, n - 1, p, FALSE, FALSE);

            g1 = (alpha * (c2 - mu) + (M1 - c2 * P1) + (M2 - c2 * P2)) /
                (p1 * (c2 - c1));
            g2 = (alpha * (c1 - mu) + (M2 - c1 * P2) + (M1 - c1 * P1)) /
                (p2 * (c1 - c2));
        }

#ifdef BLATHER
        printf(", g1 = %f and g2 = %f", g1, g2);
#endif /* BLATHER */

        if (g1 < 0.0)
            err1 = 0.0 - g1;
        else if (g1 > 1.0)
            err1 = g1 - 1.0;
        else
            err1 = 0.0;
        if (g2 < 0.0)
            err2 = 0.0 - g2;
        else if (g2 > 1.0)
            err2 = g2 - 1.0;
        else
            err2 = 0.0;

#ifdef BLATHER
        printf(", err1 = %e and err2 = %e\n", err1, err2);
#endif /* BLATHER */

        if (iiter == maxiter)
            error("iteration limit exceeded");

        if (iiter > 2) {
            c1oldold = c1old;
            c2oldold = c2old;
        }
        if (iiter > 1) {
            c1old = c1;
            c2old = c2;
        }

        if (err1 < tol && err2 < tol)
            break;

        if (err1 > err2) {
            if (g1 < 0.0)
                c1--;
            else
                c1++;
        } else if (err1 < err2) {
            if (g2 < 0.0)
                c2++;
            else
                c2--;
        }

        /* hope the following is o. k.!  a kluge! */
        if (c1 < 0) {
            c1 = 0;
            break;
        }
        if (c2 > n) {
            c2 = n;
            break;
        }

        /* hope the following is o. k.!  a kluge! */
        if (iiter > 2 && c1 == c1oldold && c2 == c2oldold)
                break;

    }

    c1out[0] = c1;
    c2out[0] = c2;
    g1out[0] = g1;
    g2out[0] = g2;
}

void
umpubinomx(int *x, int *nxin, int *nin, double *alphain, double *pin,
    int *maxiterin, double *result, double *tolin)
{
    int c1, c2;
    double g1, g2;
    int i;

    int n = nin[0];
    int nx = nxin[0];
    if (nx < 1)
        error("nx not positive");
    umpubinom(nin, alphain, pin, maxiterin, &c1, &c2, &g1, &g2, tolin);
    for (i = 0; i < nx; i++) {
        int xi = x[i];
        if (xi < 0 || xi > n)
            error("x[i] not in 0, ..., n");
        if (xi < c1 || xi > c2)
            result[i] = 1.0;
        else if (xi > c1 && xi < c2)
            result[i] = 0.0;
        else if (xi == c1)
            result[i] = g1;
        else if (xi == c2)
            result[i] = g2;
    }
}

void
umpubinoma(int *xin, int *nin, double *alpha, int *nalphain, double *pin,
    int *maxiterin, double *result, double *tolin)
{
    int i;

    int nalpha = nalphain[0];
    if (nalpha < 1)
        error("nalpha not positive");

    for (i = 0; i < nalpha; i++) {
        double foo;
        int one = 1;
        umpubinomx(xin, &one, nin, &alpha[i], pin, maxiterin, &foo, tolin);
        result[i] = foo;
    }
}

void
umpubinomt(int *xin, int *nin, double *alphain, double *p, int *npin,
    int *maxiterin, double *result, double *tolin)
{
    int i;

    int np = npin[0];
    if (np < 1)
        error("np not positive");

    for (i = 0; i < np; i++) {
        double foo;
        int one = 1;
        umpubinomx(xin, &one, nin, alphain, &p[i], maxiterin, &foo, tolin);
        result[i] = foo;
    }
}

