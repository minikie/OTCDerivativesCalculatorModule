/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2000, 2001, 2002, 2003 RiskMap srl
 Copyright (C) 2006 Ferdinando Ametrano
 Copyright (C) 2007, 2008 StatPro Italia srl

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

/*! \file swap.hpp
    \brief Interest rate swap
*/

#ifndef quantlib_currencyrateswap_hpp
#define quantlib_currencyrateswap_hpp

#include <ql/instrument.hpp>
#include <ql/cashflow.hpp>
#include <ql/instruments/swap.hpp>

namespace QuantLib {

    //! Interest rate swap
    /*! The cash flows belonging to the first leg are paid;
        the ones belonging to the second leg are received.

        \ingroup instruments
    */
    class CurrencyRateSwap : public Swap {
      public:
        class arguments;
        class results;
        class engine;
        //! \name Constructors
        //@{
        /*! The cash flows belonging to the first leg are paid;
            the ones belonging to the second leg are received.
        */

        Swap(const Leg& firstLeg,
             const Leg& secondLeg);
        /*! Multi leg constructor. */
        Swap(const std::vector<Leg>& legs,
             const std::vector<bool>& payer);
        //@}
        //! \name Instrument interface
        //@{
        bool isExpired() const;
        void setupArguments(PricingEngine::arguments*) const;
        void fetchResults(const PricingEngine::results*) const;
        //@}
        //! \name Additional interface
        //@{
        Date startDate() const;
        Date maturityDate() const;
        Real legBPS(Size j) const {
            QL_REQUIRE(j<legs_.size(), "leg# " << j << " doesn't exist!");
            calculate();
            return legBPS_[j];
        }
        Real legNPV(Size j) const {
            QL_REQUIRE(j<legs_.size(), "leg #" << j << " doesn't exist!");
            calculate();
            return legNPV_[j];
        }
        const Leg& leg(Size j) const {
            QL_REQUIRE(j<legs_.size(), "leg #" << j << " doesn't exist!");
            return legs_[j];
        }
        //@}
      protected:
        //! \name Constructors
        //@{
        /*! This constructor can be used by derived classes that will
            build their legs themselves.
        */
        Swap(Size legs);
        //@}
        //! \name Instrument interface
        //@{
        void setupExpired() const;
        //@}
        // data members
        std::vector<Leg> legs_;
        std::vector<Real> payer_;
        mutable std::vector<Real> legNPV_;
        mutable std::vector<Real> legBPS_;
    };


    class Swap::arguments : public virtual PricingEngine::arguments {
      public:
        std::vector<Leg> legs;
        std::vector<Real> payer;
        void validate() const;
    };

    class Swap::results : public Instrument::results {
      public:
        std::vector<Real> legNPV;
        std::vector<Real> legBPS;
        void reset();
    };

    class Swap::engine : public GenericEngine<Swap::arguments,
                                              Swap::results> {};

}

#endif
