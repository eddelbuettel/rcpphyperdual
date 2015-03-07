// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
#include <hyperdual.h>

#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::NumericVector addHD(Rcpp::NumericVector x, Rcpp::NumericVector y) {

    if (x.size() != 4) Rcpp::stop("First argument must be of length four.\n");
    if (y.size() != 4) Rcpp::stop("First argument must be of length four.\n");

    hyperdual l(y[0], y[1], y[2], y[3]);
    hyperdual r(x[0], x[1], x[2], x[3]);

    hyperdual z = l + r;

    Rcpp::Rcout << z << std::endl;
 
    Rcpp::NumericVector v(4);
    v[0] = z.real();
    v[1] = z.eps1();
    v[2] = z.eps2(); 
    v[3] = z.eps1eps2();

    return v;
}

