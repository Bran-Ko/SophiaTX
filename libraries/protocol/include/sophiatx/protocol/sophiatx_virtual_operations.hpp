#pragma once
#include <sophiatx/protocol/base.hpp>
#include <sophiatx/protocol/block_header.hpp>
#include <sophiatx/protocol/asset.hpp>

#include <fc/utf8.hpp>

namespace sophiatx { namespace protocol {

   struct interest_operation : public virtual_operation
   {
      interest_operation( const string& o = "", const asset& i = asset(0,SOPHIATX_SYMBOL) )
         :owner(o),interest(i){}

      account_name_type owner;
      asset             interest;
   };

   struct shutdown_witness_operation : public virtual_operation
   {
      shutdown_witness_operation(){}
      shutdown_witness_operation( const string& o ):owner(o) {}

      account_name_type owner;
   };

   struct hardfork_operation : public virtual_operation
   {
      hardfork_operation() {}
      hardfork_operation( uint32_t hf_id ) : hardfork_id( hf_id ) {}

      uint32_t         hardfork_id = 0;
   };

   struct producer_reward_operation : public virtual_operation
   {
      producer_reward_operation(){}
      producer_reward_operation( const string& p, const asset& v ) : producer( p ), vesting_shares( v ) {}

      account_name_type producer;
      asset             vesting_shares;

   };

   struct fill_vesting_withdraw_operation : public virtual_operation
   {
      fill_vesting_withdraw_operation(){}
      fill_vesting_withdraw_operation( const string& f, const string& t, const asset& w, const asset& d )
            :from_account(f), to_account(t), withdrawn(w), deposited(d) {}

      account_name_type from_account;
      account_name_type to_account;
      asset             withdrawn;
      asset             deposited;
   };

   struct promotion_pool_withdraw_operation : public virtual_operation
   {
      promotion_pool_withdraw_operation(){}
      promotion_pool_withdraw_operation( const string& t, const asset& w )
            :to_account(t), withdrawn(w) {}

      account_name_type to_account;
      asset             withdrawn;
   };

} } //sophiatx::protocol

FC_REFLECT( sophiatx::protocol::interest_operation, (owner)(interest) )
FC_REFLECT( sophiatx::protocol::shutdown_witness_operation, (owner) )
FC_REFLECT( sophiatx::protocol::hardfork_operation, (hardfork_id) )
FC_REFLECT( sophiatx::protocol::producer_reward_operation, (producer)(vesting_shares) )
FC_REFLECT( sophiatx::protocol::fill_vesting_withdraw_operation, (from_account)(to_account)(withdrawn)(deposited) )
FC_REFLECT( sophiatx::protocol::promotion_pool_withdraw_operation, (to_account)(withdrawn) )
