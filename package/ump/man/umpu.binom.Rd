\name{umpu.binom}
\alias{umpu.binom}
\title{UMPU Test for the Binomial Distribution}
\description{
  Calculate the uniformly most powerful unbiased (UMPU) two-tailed test
  for the binomial distribution.
}
\usage{
umpu.binom(x, n, p, alpha, maxiter = 10, tol = 1e-9)
}
\arguments{
  \item{x}{binomial observations.}
  \item{n}{number of observations.}
  \item{p}{the success probability under the null hypothesis.}
  \item{alpha}{the significance level.}
  \item{maxiter}{the maximum number of iterations allowed.}
  \item{tol}{tolerance used in testing floating point numbers.}
}
\details{
  At most one of \code{x}, \code{p}, and \code{alpha} is allowed to be
  a vector.  Evaluates the critical function for the UMPU two-tailed
  test for the binomial distribution, which satisfies the following
  \preformatted{
    x <- seq(0, n)
    phix <- umpu.binom(x, n, p, alpha)
    px <- dbinom(x, n, p)
    sum(phix * px) == alpha
    sum(x * phix * px) == n * p * alpha
  }
  when \code{p} is strictly between zero and one.
}
\value{
  a vector of values of the critical function.
}
\examples{
library(ump)
umpu.binom(0:10, 10, 0.6, 0.1)
}
\keyword{htest}
