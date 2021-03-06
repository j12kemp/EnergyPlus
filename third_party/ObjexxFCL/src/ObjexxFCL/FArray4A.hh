#ifndef ObjexxFCL_FArray4A_hh_INCLUDED
#define ObjexxFCL_FArray4A_hh_INCLUDED

// FArray4A: Fortran-Compatible 4D Argument Array
//
// Project: Objexx Fortran Compatibility Library (ObjexxFCL)
//
// Version: 4.0.0
//
// Language: C++
//
// Copyright (c) 2000-2014 Objexx Engineering, Inc. All Rights Reserved.
// Use of this source code or any derivative of it is restricted by license.
// Licensing is available from Objexx Engineering, Inc.:  http://objexx.com

// ObjexxFCL Headers
#include <ObjexxFCL/FArray4A.fwd.hh>
#include <ObjexxFCL/FArray4P.hh>

namespace ObjexxFCL {

// FArray4A: Fortran-Compatible 4D Argument Array
template< typename T >
class FArray4A : public FArray4< T >
{

private: // Types

	typedef  FArray4< T >  Super;
	typedef  typename Super::real_FArray  real_FArray;
	typedef  typename Super::proxy_FArray  proxy_FArray;
	typedef  typename Super::arg_FArray  arg_FArray;
	typedef  internal::ProxySentinel  ProxySentinel;

public: // Types

	typedef  typename Super::Base  Base;
	typedef  typename Base::Tail  Tail;
	typedef  typename Super::IR  SIR;
	typedef  StaticIndexRange  IR;

	// STL Style
	typedef  typename Base::value_type  value_type;
	typedef  typename Base::reference  reference;
	typedef  typename Base::const_reference  const_reference;
	typedef  typename Base::pointer  pointer;
	typedef  typename Base::const_pointer  const_pointer;
	typedef  typename Base::size_type  size_type;
	typedef  typename Base::difference_type  difference_type;

	// C++ Style
	typedef  typename Base::Value  Value;
	typedef  typename Base::Reference  Reference;
	typedef  typename Base::ConstReference  ConstReference;
	typedef  typename Base::Pointer  Pointer;
	typedef  typename Base::ConstPointer  ConstPointer;
	typedef  typename Base::Size  Size;
	typedef  typename Base::Difference  Difference;

	using Super::conformable;
	using Super::npos;
	using Super::operator ();
	using Super::shift_set;
	using Super::size_of;
	using Super::size_set;
	using Super::data_;
	using Super::data_size_;
	using Super::sdata_;
	using Super::shift_;
	using Super::z1_;
	using Super::z2_;
	using Super::z3_;
#ifdef OBJEXXFCL_PROXY_CONST_CHECKS
	using Super::not_const_proxy;
#endif // OBJEXXFCL_PROXY_CONST_CHECKS

public: // Creation

	// Default Constructor
	inline
	FArray4A() :
	 Super( ProxySentinel() )
	{}

	// Copy Constructor
	inline
	FArray4A( FArray4A const & a ) :
	 Super( a, ProxySentinel() ),
	 I1_( a.I1_ ),
	 I2_( a.I2_ ),
	 I3_( a.I3_ ),
	 I4_( a.I4_ )
	{
		shift_set( a.shift_ );
		z1_ = a.z1_;
		z2_ = a.z2_;
		z3_ = a.z3_;
	}

	// Real Constructor
	inline
	FArray4A( real_FArray const & a ) :
	 Super( a, ProxySentinel() ),
	 I1_( a.I1_ ),
	 I2_( a.I2_ ),
	 I3_( a.I3_ ),
	 I4_( a.I4_ )
	{
		shift_set( a.shift_ );
		z1_ = a.z1_;
		z2_ = a.z2_;
		z3_ = a.z3_;
	}

	// Proxy Constructor
	inline
	FArray4A( proxy_FArray const & a ) :
	 Super( a, ProxySentinel() ),
	 I1_( a.I1_ ),
	 I2_( a.I2_ ),
	 I3_( a.I3_ ),
	 I4_( a.I4_ )
	{
		shift_set( a.shift_ );
		z1_ = a.z1_;
		z2_ = a.z2_;
		z3_ = a.z3_;
	}

	// Super Constructor
	inline
	FArray4A( Super const & a ) :
	 Super( a, ProxySentinel() ),
	 I1_( a.I1() ),
	 I2_( a.I2() ),
	 I3_( a.I3() ),
	 I4_( a.I4() )
	{
		shift_set( a.shift_ );
		z1_ = a.z1_;
		z2_ = a.z2_;
		z3_ = a.z3_;
	}

	// Base Constructor
	inline
	FArray4A( Base const & a ) :
	 Super( a, ProxySentinel() ),
	 I1_( 1 ),
	 I2_( 1 ),
	 I3_( 1 ),
	 I4_( a.isize() )
	{
		shift_set( 4 );
		z1_ = z2_ = z3_ = 1;
	}

	// Tail Constructor
	inline
	FArray4A( Tail const & s ) :
	 Super( s, ProxySentinel() ),
	 I1_( 1 ),
	 I2_( 1 ),
	 I3_( 1 ),
	 I4_( s.isize() )
	{
		shift_set( 4 );
		z1_ = z2_ = z3_ = 1;
	}

	// Value Constructor
	inline
	FArray4A( T const & t ) :
	 Super( t, ProxySentinel() ),
	 I1_( 1 ),
	 I2_( 1 ),
	 I3_( 1 ),
	 I4_( star ) // Unbounded
	{
		shift_set( 4 );
		z1_ = z2_ = z3_ = 1;
	}

	// Copy + IndexRange Constructor
	inline
	FArray4A( FArray4A const & a, IR const & I1, IR const & I2, IR const & I3, IR const & I4 ) :
	 Super( a, ProxySentinel() ),
	 I1_( I1 ),
	 I2_( I2 ),
	 I3_( I3 ),
	 I4_( I4 )
	{
		dimension_argument();
	}

	// Real + IndexRange Constructor
	inline
	FArray4A( real_FArray const & a, IR const & I1, IR const & I2, IR const & I3, IR const & I4 ) :
	 Super( a, ProxySentinel() ),
	 I1_( I1 ),
	 I2_( I2 ),
	 I3_( I3 ),
	 I4_( I4 )
	{
		dimension_argument();
	}

	// Proxy + IndexRange Constructor
	inline
	FArray4A( proxy_FArray const & a, IR const & I1, IR const & I2, IR const & I3, IR const & I4 ) :
	 Super( a, ProxySentinel() ),
	 I1_( I1 ),
	 I2_( I2 ),
	 I3_( I3 ),
	 I4_( I4 )
	{
		dimension_argument();
	}

	// Super + IndexRange Constructor
	inline
	FArray4A( Super const & a, IR const & I1, IR const & I2, IR const & I3, IR const & I4 ) :
	 Super( a, ProxySentinel() ),
	 I1_( I1 ),
	 I2_( I2 ),
	 I3_( I3 ),
	 I4_( I4 )
	{
		dimension_argument();
	}

	// Base + IndexRange Constructor
	inline
	FArray4A( Base const & a, IR const & I1, IR const & I2, IR const & I3, IR const & I4 ) :
	 Super( a, ProxySentinel() ),
	 I1_( I1 ),
	 I2_( I2 ),
	 I3_( I3 ),
	 I4_( I4 )
	{
		dimension_argument();
	}

	// Tail + IndexRange Constructor
	inline
	FArray4A( Tail const & s, IR const & I1, IR const & I2, IR const & I3, IR const & I4 ) :
	 Super( s, ProxySentinel() ),
	 I1_( I1 ),
	 I2_( I2 ),
	 I3_( I3 ),
	 I4_( I4 )
	{
		dimension_argument();
	}

	// Value + IndexRange Constructor
	inline
	FArray4A( T const & t, IR const & I1, IR const & I2, IR const & I3, IR const & I4 ) :
	 Super( t, ProxySentinel() ),
	 I1_( I1 ),
	 I2_( I2 ),
	 I3_( I3 ),
	 I4_( I4 )
	{
		dimension_argument();
	}

#ifdef OBJEXXFCL_PROXY_CONST_CHECKS

	// Non-Const Copy Constructor
	inline
	FArray4A( FArray4A & a ) :
	 Super( a, ProxySentinel() ),
	 I1_( a.I1_ ),
	 I2_( a.I2_ ),
	 I3_( a.I3_ ),
	 I4_( a.I4_ )
	{
		shift_set( a.shift_ );
		z1_ = a.z1_;
		z2_ = a.z2_;
		z3_ = a.z3_;
	}

	// Non-Const Real Constructor
	inline
	FArray4A( real_FArray & a ) :
	 Super( a, ProxySentinel() ),
	 I1_( a.I1_ ),
	 I2_( a.I2_ ),
	 I3_( a.I3_ ),
	 I4_( a.I4_ )
	{
		shift_set( a.shift_ );
		z1_ = a.z1_;
		z2_ = a.z2_;
		z3_ = a.z3_;
	}

	// Non-Const Proxy Constructor
	inline
	FArray4A( proxy_FArray & a ) :
	 Super( a, ProxySentinel() ),
	 I1_( a.I1_ ),
	 I2_( a.I2_ ),
	 I3_( a.I3_ ),
	 I4_( a.I4_ )
	{
		shift_set( a.shift_ );
		z1_ = a.z1_;
		z2_ = a.z2_;
		z3_ = a.z3_;
	}

	// Non-Const Super Constructor
	inline
	FArray4A( Super & a ) :
	 Super( a, ProxySentinel() ),
	 I1_( a.I1() ),
	 I2_( a.I2() ),
	 I3_( a.I3() ),
	 I4_( a.I4() )
	{
		shift_set( a.shift_ );
		z1_ = a.z1_;
		z2_ = a.z2_;
		z3_ = a.z3_;
	}

	// Non-Const Base Constructor
	inline
	FArray4A( Base & a ) :
	 Super( a, ProxySentinel() ),
	 I1_( 1 ),
	 I2_( 1 ),
	 I3_( 1 ),
	 I4_( a.isize() )
	{
		shift_set( 4 );
		z1_ = z2_ = z3_ = 1;
	}

	// Non-Const Tail Constructor
	inline
	FArray4A( Tail & s ) :
	 Super( s, ProxySentinel() ),
	 I1_( 1 ),
	 I2_( 1 ),
	 I3_( 1 ),
	 I4_( s.isize() )
	{
		shift_set( 4 );
		z1_ = z2_ = z3_ = 1;
	}

	// Non-Const Value Constructor
	inline
	FArray4A( T & t ) :
	 Super( t, ProxySentinel() ),
	 I1_( 1 ),
	 I2_( 1 ),
	 I3_( 1 ),
	 I4_( star ) // Unbounded
	{
		shift_set( 4 );
		z1_ = z2_ = z3_ = 1;
	}

	// Non-Const Copy + IndexRange Constructor
	inline
	FArray4A( FArray4A & a, IR const & I1, IR const & I2, IR const & I3, IR const & I4 ) :
	 Super( a, ProxySentinel() ),
	 I1_( I1 ),
	 I2_( I2 ),
	 I3_( I3 ),
	 I4_( I4 )
	{
		dimension_argument();
	}

	// Non-Const Real + IndexRange Constructor
	inline
	FArray4A( real_FArray & a, IR const & I1, IR const & I2, IR const & I3, IR const & I4 ) :
	 Super( a, ProxySentinel() ),
	 I1_( I1 ),
	 I2_( I2 ),
	 I3_( I3 ),
	 I4_( I4 )
	{
		dimension_argument();
	}

	// Non-Const Proxy + IndexRange Constructor
	inline
	FArray4A( proxy_FArray & a, IR const & I1, IR const & I2, IR const & I3, IR const & I4 ) :
	 Super( a, ProxySentinel() ),
	 I1_( I1 ),
	 I2_( I2 ),
	 I3_( I3 ),
	 I4_( I4 )
	{
		dimension_argument();
	}

	// Non-Const Super + IndexRange Constructor
	inline
	FArray4A( Super & a, IR const & I1, IR const & I2, IR const & I3, IR const & I4 ) :
	 Super( a, ProxySentinel() ),
	 I1_( I1 ),
	 I2_( I2 ),
	 I3_( I3 ),
	 I4_( I4 )
	{
		dimension_argument();
	}

	// Non-Const Base + IndexRange Constructor
	inline
	FArray4A( Base & a, IR const & I1, IR const & I2, IR const & I3, IR const & I4 ) :
	 Super( a, ProxySentinel() ),
	 I1_( I1 ),
	 I2_( I2 ),
	 I3_( I3 ),
	 I4_( I4 )
	{
		dimension_argument();
	}

	// Non-Const Tail + IndexRange Constructor
	inline
	FArray4A( Tail & s, IR const & I1, IR const & I2, IR const & I3, IR const & I4 ) :
	 Super( s, ProxySentinel() ),
	 I1_( I1 ),
	 I2_( I2 ),
	 I3_( I3 ),
	 I4_( I4 )
	{
		dimension_argument();
	}

	// Non-Const Value + IndexRange Constructor
	inline
	FArray4A( T & t, IR const & I1, IR const & I2, IR const & I3, IR const & I4 ) :
	 Super( t, ProxySentinel() ),
	 I1_( I1 ),
	 I2_( I2 ),
	 I3_( I3 ),
	 I4_( I4 )
	{
		dimension_argument();
	}

#endif // OBJEXXFCL_PROXY_CONST_CHECKS

	// Destructor
	inline
	virtual
	~FArray4A()
	{}

public: // Assignment: Array

	// Copy Assignment
	inline
	FArray4A &
	operator =( FArray4A const & a )
	{
		if ( this != &a ) {
			if ( ! conformable( a ) ) dimension( a );
			Base::operator =( a );
		}
		return *this;
	}

	// Super Assignment
	inline
	FArray4A &
	operator =( Super const & a )
	{
		if ( this != &a ) {
			if ( ! conformable( a ) ) dimension( a );
			Base::operator =( a );
		}
		return *this;
	}

	// Super Assignment Template
	template< typename U, class = typename std::enable_if< std::is_assignable< T&, U >::value >::type >
	inline
	FArray4A &
	operator =( FArray4< U > const & a )
	{
		if ( ! conformable( a ) ) dimension( a );
		Base::operator =( a );
		return *this;
	}

	// Slice Assignment Template
	template< typename U, class = typename std::enable_if< std::is_assignable< T&, U >::value >::type >
	inline
	FArray4A &
	operator =( FArray4S< U > const & a )
	{
		Super::operator =( a );
		return *this;
	}

	// MArray Assignment Template
	template< class A, typename M >
	inline
	FArray4A &
	operator =( MArray4< A, M > const & a )
	{
		Super::operator =( a );
		return *this;
	}

	// Initializer List Assignment Template
	template< typename U, class = typename std::enable_if< std::is_assignable< T&, U >::value >::type >
	inline
	FArray4A &
	operator =( std::initializer_list< U > const l )
	{
		Base::operator =( l );
		return *this;
	}

	// += Array Template
	template< typename U, class = typename std::enable_if< std::is_assignable< T&, U >::value >::type >
	inline
	FArray4A &
	operator +=( FArray4< U > const & a )
	{
		Super::operator +=( a );
		return *this;
	}

	// -= Array Template
	template< typename U, class = typename std::enable_if< std::is_assignable< T&, U >::value >::type >
	inline
	FArray4A &
	operator -=( FArray4< U > const & a )
	{
		Super::operator -=( a );
		return *this;
	}

	// *= Array Template
	template< typename U, class = typename std::enable_if< std::is_assignable< T&, U >::value >::type >
	inline
	FArray4A &
	operator *=( FArray4< U > const & a )
	{
		Super::operator *=( a );
		return *this;
	}

	// /= Array Template
	template< typename U, class = typename std::enable_if< std::is_assignable< T&, U >::value >::type >
	inline
	FArray4A &
	operator /=( FArray4< U > const & a )
	{
		Super::operator /=( a );
		return *this;
	}

	// += Slice Template
	template< typename U, class = typename std::enable_if< std::is_assignable< T&, U >::value >::type >
	inline
	FArray4A &
	operator +=( FArray4S< U > const & a )
	{
		Super::operator +=( a );
		return *this;
	}

	// -= Slice Template
	template< typename U, class = typename std::enable_if< std::is_assignable< T&, U >::value >::type >
	inline
	FArray4A &
	operator -=( FArray4S< U > const & a )
	{
		Super::operator -=( a );
		return *this;
	}

	// *= Slice Template
	template< typename U, class = typename std::enable_if< std::is_assignable< T&, U >::value >::type >
	inline
	FArray4A &
	operator *=( FArray4S< U > const & a )
	{
		Super::operator *=( a );
		return *this;
	}

	// /= Slice Template
	template< typename U, class = typename std::enable_if< std::is_assignable< T&, U >::value >::type >
	inline
	FArray4A &
	operator /=( FArray4S< U > const & a )
	{
		Super::operator /=( a );
		return *this;
	}

	// += MArray Template
	template< class A, typename M >
	inline
	FArray4A &
	operator +=( MArray4< A, M > const & a )
	{
		Super::operator +=( a );
		return *this;
	}

	// -= MArray Template
	template< class A, typename M >
	inline
	FArray4A &
	operator -=( MArray4< A, M > const & a )
	{
		Super::operator -=( a );
		return *this;
	}

	// *= MArray Template
	template< class A, typename M >
	inline
	FArray4A &
	operator *=( MArray4< A, M > const & a )
	{
		Super::operator *=( a );
		return *this;
	}

	// /= MArray Template
	template< class A, typename M >
	inline
	FArray4A &
	operator /=( MArray4< A, M > const & a )
	{
		Super::operator /=( a );
		return *this;
	}

public: // Assignment: Array: Logical

	// &&= Array Template
	template< typename U, class = typename std::enable_if< std::is_assignable< T&, U >::value >::type >
	inline
	FArray4A &
	and_equals( FArray4< U > const & a )
	{
		Super::and_equals( a );
		return *this;
	}

	// ||= Array Template
	template< typename U, class = typename std::enable_if< std::is_assignable< T&, U >::value >::type >
	inline
	FArray4A &
	or_equals( FArray4< U > const & a )
	{
		Super::or_equals( a );
		return *this;
	}

	// &&= Slice Template
	template< typename U, class = typename std::enable_if< std::is_assignable< T&, U >::value >::type >
	inline
	FArray4A &
	and_equals( FArray4S< U > const & a )
	{
		Super::and_equals( a );
		return *this;
	}

	// ||= Slice Template
	template< typename U, class = typename std::enable_if< std::is_assignable< T&, U >::value >::type >
	inline
	FArray4A &
	or_equals( FArray4S< U > const & a )
	{
		Super::or_equals( a );
		return *this;
	}

	// &&= MArray Template
	template< class A, typename M >
	inline
	FArray4A &
	and_equals( MArray4< A, M > const & a )
	{
		Super::and_equals( a );
		return *this;
	}

	// ||= MArray Template
	template< class A, typename M >
	inline
	FArray4A &
	or_equals( MArray4< A, M > const & a )
	{
		Super::or_equals( a );
		return *this;
	}

public: // Assignment: Value

	// = Value
	inline
	FArray4A &
	operator =( T const & t )
	{
		Base::operator =( t );
		return *this;
	}

	// += Value
	inline
	FArray4A &
	operator +=( T const & t )
	{
		Base::operator +=( t );
		return *this;
	}

	// -= Value
	inline
	FArray4A &
	operator -=( T const & t )
	{
		Base::operator -=( t );
		return *this;
	}

	// *= Value
	inline
	FArray4A &
	operator *=( T const & t )
	{
		Base::operator *=( t );
		return *this;
	}

	// /= Value
	inline
	FArray4A &
	operator /=( T const & t )
	{
		Base::operator /=( t );
		return *this;
	}

public: // Subscript

	// Const Tail Starting at array( i1, i2, i3, i4 )
	inline
	Tail const
	a( int const i1, int const i2, int const i3, int const i4 ) const
	{
		assert( ( I1_.contains( i1 ) ) && ( I2_.contains( i2 ) ) && ( I3_.contains( i3 ) ) && ( I4_.contains( i4 ) ) );
		size_type const offset( ( ( ( ( ( ( i4 * z3_ ) + i3 ) * z2_ ) + i2 ) * z1_ ) + i1 ) - shift_ );
		return Tail( static_cast< T const * >( data_ + offset ), ( data_size_ != npos ? data_size_ - offset : npos ) );
	}

	// Tail Starting at array( i1, i2, i3, i4 )
	inline
	Tail
	a( int const i1, int const i2, int const i3, int const i4 )
	{
		proxy_const_assert( not_const_proxy() );
		assert( ( I1_.contains( i1 ) ) && ( I2_.contains( i2 ) ) && ( I3_.contains( i3 ) ) && ( I4_.contains( i4 ) ) );
		size_type const offset( ( ( ( ( ( ( i4 * z3_ ) + i3 ) * z2_ ) + i2 ) * z1_ ) + i1 ) - shift_ );
		return Tail( data_ + offset, ( data_size_ != npos ? data_size_ - offset : npos ) );
	}

	// Linear Index
	inline
	size_type
	index( int const i1, int const i2, int const i3, int const i4 ) const
	{
		return ( ( ( ( ( ( ( i4 * z3_ ) + i3 ) * z2_ ) + i2 ) * z1_ ) + i1 ) - shift_ );
	}

public: // Predicate

	// Dimensions Initialized?
	inline
	bool
	dimensions_initialized() const
	{
		return true;
	}

	// Contains Indexed Element?
	inline
	bool
	contains( int const i1, int const i2, int const i3, int const i4 ) const
	{
		return ( ( I1_.contains( i1 ) ) && ( I2_.contains( i2 ) ) && ( I3_.contains( i3 ) ) && ( I4_.contains( i4 ) ) );
	}

	// Initializer Active?
	inline
	bool
	initializer_active() const
	{
		return false;
	}

public: // Inspector

	// IndexRange of Dimension 1
	inline
	IR const &
	I1() const
	{
		return I1_;
	}

	// Lower Index of Dimension 1
	inline
	int
	l1() const
	{
		return I1_.l();
	}

	// Upper Index of Dimension 1
	inline
	int
	u1() const
	{
		return I1_.u();
	}

	// IndexRange of Dimension 2
	inline
	IR const &
	I2() const
	{
		return I2_;
	}

	// Lower Index of Dimension 2
	inline
	int
	l2() const
	{
		return I2_.l();
	}

	// Upper Index of Dimension 2
	inline
	int
	u2() const
	{
		return I2_.u();
	}

	// IndexRange of Dimension 3
	inline
	IR const &
	I3() const
	{
		return I3_;
	}

	// Lower Index of Dimension 3
	inline
	int
	l3() const
	{
		return I3_.l();
	}

	// Upper Index of Dimension 3
	inline
	int
	u3() const
	{
		return I3_.u();
	}

	// IndexRange of Dimension 4
	inline
	IR const &
	I4() const
	{
		return I4_;
	}

	// Lower Index of Dimension 4
	inline
	int
	l4() const
	{
		return I4_.l();
	}

	// Upper Index of Dimension 4
	inline
	int
	u4() const
	{
		return I4_.u();
	}

	// Size of Dimension 4
	inline
	size_type
	size4() const
	{
		return I4_.size();
	}

	// Size of Dimension 4
	inline
	int
	isize4() const
	{
		return I4_.isize();
	}

public: // Modifier

	// Clear
	inline
	FArray4A &
	clear()
	{
		Super::clear();
		I1_.clear();
		I2_.clear();
		I3_.clear();
		I4_.clear();
		return *this;
	}

	// Dimension by IndexRange Even if Const
	inline
	FArray4A const &
	dim( IR const & I1, IR const & I2, IR const & I3, IR const & I4 ) const
	{
		const_cast< FArray4A & >( *this ).dimension( I1, I2, I3, I4 );
		return *this;
	}

	// Dimension by Array Even if Const
	template< typename U >
	inline
	FArray4A const &
	dim( FArray4< U > const & a ) const
	{
		const_cast< FArray4A & >( *this ).dimension( a );
		return *this;
	}

	// Dimension by IndexRange
	inline
	FArray4A &
	dimension( IR const & I1, IR const & I2, IR const & I3, IR const & I4 )
	{
		I1_.assign_value_of( I1 );
		I2_.assign_value_of( I2 );
		I3_.assign_value_of( I3 );
		I4_.assign_value_of( I4 );
		dimension_argument();
		return *this;
	}

	// Dimension by Array
	template< typename U >
	inline
	FArray4A &
	dimension( FArray4< U > const & a )
	{
		I1_.assign_value_of( a.I1() );
		I2_.assign_value_of( a.I2() );
		I3_.assign_value_of( a.I3() );
		I4_.assign_value_of( a.I4() );
		dimension_argument();
		return *this;
	}

	// Attach to Argument Array
	inline
	FArray4A &
	attach( FArray4A const & a )
	{
		Base::attach( a );
		z1_ = a.z1_;
		z2_ = a.z2_;
		z3_ = a.z3_;
		I1_.assign_value_of( a.I1_ );
		I2_.assign_value_of( a.I2_ );
		I3_.assign_value_of( a.I3_ );
		I4_.assign_value_of( a.I4_ );
		return *this;
	}

	// Attach to Non-Const Argument Array
	inline
	FArray4A &
	attach( FArray4A & a )
	{
		Base::attach( a );
		z1_ = a.z1_;
		z2_ = a.z2_;
		z3_ = a.z3_;
		I1_.assign_value_of( a.I1_ );
		I2_.assign_value_of( a.I2_ );
		I3_.assign_value_of( a.I3_ );
		I4_.assign_value_of( a.I4_ );
		return *this;
	}

	// Attach to Real Array
	inline
	FArray4A &
	attach( real_FArray const & a )
	{
		Base::attach( a );
		z1_ = a.z1_;
		z2_ = a.z2_;
		z3_ = a.z3_;
		I1_.assign_value_of( a.I1_ );
		I2_.assign_value_of( a.I2_ );
		I3_.assign_value_of( a.I3_ );
		I4_.assign_value_of( a.I4_ );
		return *this;
	}

	// Attach to Non-Const Real Array
	inline
	FArray4A &
	attach( real_FArray & a )
	{
		Base::attach( a );
		z1_ = a.z1_;
		z2_ = a.z2_;
		z3_ = a.z3_;
		I1_.assign_value_of( a.I1_ );
		I2_.assign_value_of( a.I2_ );
		I3_.assign_value_of( a.I3_ );
		I4_.assign_value_of( a.I4_ );
		return *this;
	}

	// Attach to Proxy Array
	inline
	FArray4A &
	attach( proxy_FArray const & a )
	{
		Base::attach( a );
		z1_ = a.z1_;
		z2_ = a.z2_;
		z3_ = a.z3_;
		I1_.assign_value_of( a.I1_ );
		I2_.assign_value_of( a.I2_ );
		I3_.assign_value_of( a.I3_ );
		I4_.assign_value_of( a.I4_ );
		return *this;
	}

	// Attach to Non-Const Proxy Array
	inline
	FArray4A &
	attach( proxy_FArray & a )
	{
		Base::attach( a );
		z1_ = a.z1_;
		z2_ = a.z2_;
		z3_ = a.z3_;
		I1_.assign_value_of( a.I1_ );
		I2_.assign_value_of( a.I2_ );
		I3_.assign_value_of( a.I3_ );
		I4_.assign_value_of( a.I4_ );
		return *this;
	}

	// Attach to Super Array
	inline
	FArray4A &
	attach( Super const & a )
	{
		Base::attach( a );
		z1_ = a.z1_;
		z2_ = a.z2_;
		z3_ = a.z3_;
		I1_.assign_value_of( a.I1() );
		I2_.assign_value_of( a.I2() );
		I3_.assign_value_of( a.I3() );
		I4_.assign_value_of( a.I4() );
		return *this;
	}

	// Attach to Non-Const Super Array
	inline
	FArray4A &
	attach( Super & a )
	{
		Base::attach( a );
		z1_ = a.z1_;
		z2_ = a.z2_;
		z3_ = a.z3_;
		I1_.assign_value_of( a.I1() );
		I2_.assign_value_of( a.I2() );
		I3_.assign_value_of( a.I3() );
		I4_.assign_value_of( a.I4() );
		return *this;
	}

	// Attach to Base Array
	inline
	FArray4A &
	attach( Base const & a )
	{
		Base::attach( a, 4 );
		z1_ = z2_ = z3_ = 1;
		I1_ = 1;
		I2_ = 1;
		I3_ = 1;
		I4_ = a.isize();
		return *this;
	}

	// Attach to Non-Const Base Array
	inline
	FArray4A &
	attach( Base & a )
	{
		Base::attach( a, 4 );
		z1_ = z2_ = z3_ = 1;
		I1_ = 1;
		I2_ = 1;
		I3_ = 1;
		I4_ = a.isize();
		return *this;
	}

	// Attach to Tail
	inline
	FArray4A &
	attach( Tail const & s )
	{
		Base::attach( s, 4 );
		z1_ = z2_ = z3_ = 1;
		I1_ = 1;
		I2_ = 1;
		I3_ = 1;
		I4_ = s.isize();
		return *this;
	}

	// Attach to Non-Const Tail
	inline
	FArray4A &
	attach( Tail & s )
	{
		Base::attach( s, 4 );
		z1_ = z2_ = z3_ = 1;
		I1_ = 1;
		I2_ = 1;
		I3_ = 1;
		I4_ = s.isize();
		return *this;
	}

	// Attach to Value
	inline
	FArray4A &
	attach( T const & t )
	{
		Base::attach( t, 4 );
		z1_ = z2_ = z3_ = 1;
		I1_ = 1;
		I2_ = 1;
		I3_ = 1;
		I4_ = star; // Unbounded
		return *this;
	}

	// Attach to Non-Const Value
	inline
	FArray4A &
	attach( T & t )
	{
		Base::attach( t, 4 );
		z1_ = z2_ = z3_ = 1;
		I1_ = 1;
		I2_ = 1;
		I3_ = 1;
		I4_ = star; // Unbounded
		return *this;
	}

	// Detach from Source Array
	inline
	FArray4A &
	detach()
	{
		Base::detach();
		z1_ = z2_ = z3_ = 0;
		I1_.clear();
		I2_.clear();
		I3_.clear();
		I4_.clear();
		return *this;
	}

protected: // Functions

	// Dimension by IndexRange
	inline
	void
	dimension_assign( SIR const & I1, SIR const & I2, SIR const & I3, SIR const & I4 )
	{
		I1_.assign_value_of( I1 );
		I2_.assign_value_of( I2 );
		I3_.assign_value_of( I3 );
		I4_.assign_value_of( I4 );
		dimension_argument();
	}

private: // Functions

	// Dimension by Current IndexRanges
	inline
	void
	dimension_argument()
	{
		assert( I1_.bounded() );
		assert( I2_.bounded() );
		assert( I3_.bounded() );
		z1_ = I1_.size();
		z2_ = I2_.size();
		z3_ = I3_.size();
		if ( I4_.bounded() ) { // Bounded
			size_set( size_of( z1_, z2_, z3_, I4_.size() ) );
		} else if ( data_size_ != npos ) { // Unbounded with bounded data array
			size_type const slice_size( size_of( z1_, z2_, z3_ ) );
			if ( slice_size > 0u ) { // Infer upper index and size
				I4_.u( I4_.lz() + static_cast< int >( data_size_ / slice_size ) - 1 );
				size_set( size_of( slice_size, I4_.size() ) );
			} else {
				size_set( data_size_ );
			}
		} else { // Unbounded with unbounded data array
			size_set( npos );
		}
		shift_set( ( ( ( ( ( I4_.lz() * z3_ ) + I3_.lz() ) * z2_ ) + I2_.lz() ) * z1_ ) + I1_.lz() );
	}

private: // Data

	IR I1_; // Index range of dim 1
	IR I2_; // Index range of dim 2
	IR I3_; // Index range of dim 3
	IR I4_; // Index range of dim 4

}; // FArray4A

} // ObjexxFCL

#endif // ObjexxFCL_FArray4A_hh_INCLUDED
