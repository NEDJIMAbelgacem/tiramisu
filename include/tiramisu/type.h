#ifndef _H_TIRAMISU_TYPE_
#define _H_TIRAMISU_TYPE_

#include <string.h>
#include <stdint.h>

namespace tiramisu
{

/**
  * The possible types of an expression.
  * "e_" stands for expression.
  */
enum expr_t
{
    e_val,          // literal value, like 1, 2.4, 10, ...
    e_var,          // a variable of a primitive type (i.e., an identifier holding one value),
    e_sync,         // syncs parallel computations. Currently used in the context of GPUs.
    e_op,           // an operation: add, mul, div, ...
    e_none          // undefined expression. The existence of an expression of e_none type means an error.
};

/**
  * tiramisu data types.
  * "p_" stands for primitive.
  */
enum primitive_t
{
    p_uint8,
    p_uint16,
    p_uint32,
    p_uint64,
    p_int8,
    p_int16,
    p_int32,
    p_int64,
    p_float32,
    p_float64,
    p_boolean,
    p_async,
    p_wait_ptr,
    p_void_ptr,  // Used for raw buffers in cuda_ast
    p_none
};


/**
  * Types of tiramisu operators.
  * If the expression is of type e_op then it should
  * have an operator type. This is the operator type.
  *
  * "o_" stands for operator.
  */
enum op_t
{
    // Unary operators
    // The argument of the following operators is a tiramisu::expr.
    o_minus, // 0
    o_floor, // 1
    o_sin,   // 2
    o_cos,   // 3
    o_tan,   // 4
    o_asin,  // 5
    o_acos,  // 6
    o_atan,  // 7
    o_sinh,  // 8
    o_cosh,  // 9
    o_tanh,  // 10
    o_asinh, // 11
    o_acosh, // 12
    o_atanh, // 13
    o_abs,   // 14
    o_sqrt,  // 15
    o_expo, // exponential // 16
    o_log, // 17
    o_ceil, // 18
    o_round, // 19
    o_trunc, // 20
    // The argument of the following operators is a string representing
    // the name of the buffer to allocate.
    o_allocate, // 21
    o_free, // 22
    // Other arguments
    o_cast, // The argument is an expression and a type. // 23
    o_address, // The argument is a tiramisu::var() that represents a buffer. // 24


    // Binary operator
    // The arguments are tiramisu::expr.
    o_add, // 25
    o_sub, // 26
    o_mul, // 27
    o_div,
    o_mod,
    o_logical_and,
    o_logical_or,
    o_logical_not,
    o_eq,
    o_ne,
    o_le,
    o_lt,
    o_ge,
    o_gt,
    o_max,
    o_min,
    o_right_shift,
    o_left_shift,
    o_memcpy,


    // Ternary operators
    // The arguments are tiramisu::expr.
    o_select,
    o_cond,
    o_lerp,

    // Operators taking a name and a vector of expressions.
    o_call,
    o_access,
    o_address_of,
    o_lin_index,
    o_type,
    o_dummy,
    // just pass in the buffer
    o_buffer,

    o_none,
};

/**
  * Types of function arguments.
  * "a_" stands for argument.
  */
enum argument_t
{
    a_input,
    a_output,
    a_temporary
};

/**
  * Types of ranks in a distributed communication
  * "r_" stands for rank.
  */
enum class rank_t
{
    r_sender,
    r_receiver
};

/**
  * Types of hardware architectures to generate code for
  * "arch_" stands for architecture.
  * the numbers are used to give the possibility to the user
  * to combine flags (use different devices of different
  * architectures in the same code)
  * TODO:FLEXNLP take off values
  */
enum class hardware_architecture_t
{
    arch_cpu,
    arch_nvidia_gpu,
    arch_flexnlp
};

/**
  * Convert a Tiramisu type into the equivalent Halide type (if it exists),
  * otherwise show an error message (no automatic type conversion is performed).
  */
Halide::Type halide_type_from_tiramisu_type(tiramisu::primitive_t type);

/**
  * Convert a Halide type into the equivalent Tiramisu type (if it exists),
  * otherwise show an error message (no automatic type conversion is performed).
  */
tiramisu::primitive_t halide_type_to_tiramisu_type(Halide::Type type);
}

#endif
