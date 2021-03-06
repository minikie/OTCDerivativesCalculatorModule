/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
Copyright (C) 2009 Ralph Schreyer

This file is part of QuantLib, a free-software/open-source library
for financial quantitative analysts and developers - http://quantlib.org/

QuantLib is free software: you can redistribute it and/or modify it
under the terms of the QuantLib license.  You should have received a
copy of the license along with this program; if not, please email
<quantlib-dev@lists.sf.net>. The license is also available online at
<http://quantlib.org/license.shtml>.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file sparseilupreconditioner.hpp
    \brief Preconditioner using the Incomplete LU algorithm and sparse matrices
*/

#ifndef quantlib_sparse_ilu_preconditioner_hpp
#define quantlib_sparse_ilu_preconditioner_hpp

#include <ql/qldefines.hpp>

#if !defined(QL_NO_UBLAS_SUPPORT)

#include <ql/math/array.hpp>

#if defined(QL_PATCH_MSVC)
#pragma warning(push)
#pragma warning(disable:4180)
#endif

#include <boost/numeric/ublas/matrix_sparse.hpp>

#if defined(QL_PATCH_MSVC)
#pragma warning(pop)
#endif

namespace QuantLib {

    /*! References:

        Saad, Yousef. 1996, Iterative methods for sparse linear systems,
        http://www-users.cs.umn.edu/~saad/books.html
    */
    class SparseILUPreconditioner  {
      public:
        SparseILUPreconditioner(
                      const boost::numeric::ublas::compressed_matrix<Real>& A,
                      Integer lfil = 1);

        const boost::numeric::ublas::compressed_matrix<Real>& L() const;
        const boost::numeric::ublas::compressed_matrix<Real>& U() const;

        Disposable<Array> apply(const Array& b) const;

      private:
        boost::numeric::ublas::compressed_matrix<Real> L_, U_;
        std::vector<Size> lBands_, uBands_;

        Disposable<Array> forwardSolve(const Array& b) const;
        Disposable<Array> backwardSolve(const Array& y) const;
    };

}

#endif
#endif
