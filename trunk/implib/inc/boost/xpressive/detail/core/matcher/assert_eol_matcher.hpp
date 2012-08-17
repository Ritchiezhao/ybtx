///////////////////////////////////////////////////////////////////////////////
// assert_eol_matcher.hpp
//
//  Copyright 2007 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_XPRESSIVE_DETAIL_CORE_MATCHER_ASSERT_EOL_MATCHER_HPP_EAN_10_04_2005
#define BOOST_XPRESSIVE_DETAIL_CORE_MATCHER_ASSERT_EOL_MATCHER_HPP_EAN_10_04_2005

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <boost/xpressive/detail/detail_fwd.hpp>
#include <boost/xpressive/detail/core/quant_style.hpp>
#include <boost/xpressive/detail/core/state.hpp>
#include <boost/xpressive/detail/core/matcher/assert_line_base.hpp>

namespace boost { namespace xpressive { namespace detail
{

    ///////////////////////////////////////////////////////////////////////////////
    // assert_eol_matcher
    //
    template<typename Traits>
    struct assert_eol_matcher
      : assert_line_base<Traits>
    {
        assert_eol_matcher(Traits const &traits)
          : assert_line_base<Traits>(traits)
        {
        }

        template<typename BidiIter, typename Next>
        bool match(match_state<BidiIter> &state, Next const &next) const
        {
            if(state.eos())
            {
                if(!state.flags_.match_eol_)
                {
                    return false;
                }
            }
            else if((state.bos() && !state.flags_.match_prev_avail_) || !this->is_line_break(state))
            {
                return false;
            }

            return next.match(state);
        }
    };

}}}

#endif