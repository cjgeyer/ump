\name{arpv.plot}
\alias{arpv.plot}
\title{Plot Abstract Randomized P-value}
\description{
  Plot ether the distribution function or the probability density function
  of an abstract randomized P-value
}
\usage{
arpv.plot(alpha, phi, df = TRUE, verticals = TRUE)
}
\arguments{
  \item{alpha}{significance levels at which the density is discontinuous
      ("knots").}
  \item{phi}{values of the distribution function at these knots.}
  \item{df}{if \code{TRUE} plot the distribution function, otherwise the
      density.}
  \item{verticals}{if \code{TRUE} plot vertical lines at the jumps of the
      density.  Ignored if \code{df == TRUE}.}
}
\value{
  none.
}
\examples{
out <- arpv.binom(10, 10, 0.7)
arpv.plot(out$alpha, out$phi)
arpv.plot(out$alpha, out$phi, df = FALSE)
}
\keyword{htest}
