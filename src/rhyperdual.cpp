// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
#include <hyperdual.h>

#include <Rcpp.h>

//' This function adds two hyper-dual numbers
//' 
//' @title Add two hyper-dual numbers
//' @param x A vector of length four containg a hyper-dual number
//' @param y A vector of length four containg a hyper-dual number
//' @param verbose A boolean variable with default \sQuote{false} 
//' indicating if verbose operation is desired.
//' @return A vector of length four containing the resulting
//' hyper-dual number.
//' @author Dirk Eddelbuettel
//' @examples
//'
//' addHL( c(1,0,0,1), c(2,1,0,-1) )
// [[Rcpp::export]]
Rcpp::NumericVector addHL(Rcpp::NumericVector x, Rcpp::NumericVector y, bool verbose=false) {

    if (x.size() != 4) Rcpp::stop("First argument must be of length four.\n");
    if (y.size() != 4) Rcpp::stop("First argument must be of length four.\n");

    hyperdual l(y[0], y[1], y[2], y[3]);
    hyperdual r(x[0], x[1], x[2], x[3]);

    hyperdual z = l + r;

    if (verbose) Rcpp::Rcout << z << std::endl;
 
    Rcpp::NumericVector v(4);
    v[0] = z.real();
    v[1] = z.eps1();
    v[2] = z.eps2(); 
    v[3] = z.eps1eps2();
    return v;
}

