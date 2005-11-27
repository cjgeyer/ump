\name{fci.binom}
\alias{fci.binom}
\title{Abstract Randomized P-value for the Binomial Distribution}
\description{
  Calculate the abstract randomized P-value for the UMPU two-tailed test
  for the binomial distribution.
}
\usage{
fci.binom(x, n, alpha = 0.05, p = seq(0, 1, length = 10001), flat = 1 / 4)
}
\arguments{
  \item{x}{binomial observation.}
  \item{n}{number of observations.}
  \item{alpha}{the significance level, one minus the coverage probability.}
  \item{p}{the vector of parameter values at which (the membership function
      of) the fuzzy confidence interval is evaluated.}
  \item{flat}{the amount of flat parts of the membership function shown,
      expressed as a fraction of the curved parts.}
}
\details{
   prints the core and support of the fuzzy confidence interval
   and makes one or two plots (as appropriate) showing the edges of the
   fuzzy interval.
}
\value{
   none
}
\examples{
library(ump)
fci.binom(4, 10)
fci.binom(0, 10)
fci.binom(9, 10)
}
\keyword{htest}
