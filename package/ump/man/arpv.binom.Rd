\name{arpv.binom}
\alias{arpv.binom}
\title{Abstract Randomized P-value for the Binomial Distribution}
\description{
  Calculate the abstract randomized P-value for the UMPU two-tailed test
  for the binomial distribution.
}
\usage{
arpv.binom(x, n, p, plot = TRUE, \dots)
}
\arguments{
  \item{x}{binomial observations.}
  \item{n}{number of observations.}
  \item{p}{the success probability under the null hypothesis.}
  \item{plot}{if \code{TRUE} make a plot.}
  \item{\dots}{additional arguments passed to \code{arpv.plot}.}
}
\details{
  The first three arguments must be scalar.
  Evaluates the distribution function of the abstract randomized P-value
  for the UMPU two-tailed test for the binomial distribution, which
  is a continuous, piecewise linear function.  Gives the knots.
}
\value{
  a list containing two components:
  \item{alpha}{significance level values at the knots.}
  \item{phi}{distribution function values at the knots.}
}
\examples{
library(ump)
print(arpv.binom(10, 10, 0.7, plot = FALSE))
arpv.binom(10, 10, 0.7)
arpv.binom(10, 10, 0.7, df = FALSE)
}
\keyword{htest}
