/*
 * Range.h
 *
 *  Created on: 8 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef RANGE_H_
#define RANGE_H_

namespace ISO_8583 {
	namespace DTT {

		template <long long int T_begin, long long  int T_end>
		class StaticRange {
		public:
			class iterator {
				friend class StaticRange;
			public:
				long long  int operator *() const { return _begin; }
				const iterator &operator ++() { ++_begin; return *this; }
				iterator operator ++(int) { iterator copy(*this); ++_begin; return copy; }

				bool operator ==(const iterator &other) const { return _begin == other._begin; }
				bool operator !=(const iterator &other) const { return _begin != other._begin; }
				bool operator <=(const iterator &other) const { return _begin <= other._begin; }


			protected:
				iterator(long int start) { _begin = start; }

			private:
				long long  _begin = T_begin;
			};

			iterator begin() const { return iterator(T_begin); }
			iterator end() const { return iterator(T_end + 1); }

			bool in(long long int value) const { return begin() <= iterator(value) && iterator(value) <= end(); }
			bool out(long long int value) const { return !in(value); }
		};
		class DynamicRange {
		public:
			class iterator {
				friend class DynamicRange;
			public:
				long long  int operator *() const { return i_; }
				const iterator &operator ++() { ++i_; return *this; }
				iterator operator ++(int) { iterator copy(*this); ++i_; return copy; }

				bool operator ==(const iterator &other) const { return i_ == other.i_; }
				bool operator !=(const iterator &other) const { return i_ != other.i_; }

			protected:
				iterator(long int start) : i_(start) { }

			private:
				long long  i_;
			};

			iterator begin() const { return begin_; }
			iterator end() const { return end_; }
			DynamicRange(long int  begin, long int end) : begin_(begin), end_(end + 1) {}
		private:
			iterator begin_;
			iterator end_;
		};
	}
}

#endif
/*

*/
