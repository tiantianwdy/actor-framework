/******************************************************************************
 *                       ____    _    _____                                   *
 *                      / ___|  / \  |  ___|    C++                           *
 *                     | |     / _ \ | |_       Actor                         *
 *                     | |___ / ___ \|  _|      Framework                     *
 *                      \____/_/   \_|_|                                      *
 *                                                                            *
 * Copyright (C) 2011 - 2014                                                  *
 * Dominik Charousset <dominik.charousset (at) haw-hamburg.de>                *
 *                                                                            *
 * Distributed under the terms and conditions of the BSD 3-Clause License or  *
 * (at your option) under the terms and conditions of the Boost Software      *
 * License 1.0. See accompanying files LICENSE and LICENCE_ALTERNATIVE.       *
 *                                                                            *
 * If you did not receive a copy of the license files, see                    *
 * http://opensource.org/licenses/BSD-3-Clause and                            *
 * http://www.boost.org/LICENSE_1_0.txt.                                      *
 ******************************************************************************/

#ifndef CAF_PRIORITY_POLICY_HPP
#define CAF_PRIORITY_POLICY_HPP

namespace caf {
class mailbox_element;
} // namespace caf

namespace caf {
namespace policy {

/**
 * @brief The priority_policy <b>concept</b> class. Please note that this
 *    class is <b>not</b> implemented. It only explains the all
 *    required member function and their behavior for any priority policy.
 */
class priority_policy {

 public:

  /**
   * @brief Returns the next message from the mailbox or @p nullptr
   *    if it's empty.
   */
  template <class Actor>
  unique_mailbox_element_pointer next_message(Actor* self);

  /**
   * @brief Queries whether the mailbox is not empty.
   */
  template <class Actor>
  bool has_next_message(Actor* self);

  void push_to_cache(unique_mailbox_element_pointer ptr);

  using cache_type = std::vector<unique_mailbox_element_pointer>;

  using cache_iterator = cache_type::iterator;

  cache_iterator cache_begin();

  cache_iterator cache_end();

  void cache_erase(cache_iterator iter);

};

} // namespace policy
} // namespace caf

#endif // CAF_PRIORITY_POLICY_HPP
