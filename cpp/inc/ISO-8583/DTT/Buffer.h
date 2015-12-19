/*
 * Buffer.h
 *
 *  Created on: 14 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef BUFFER_H_
#define BUFFER_H_
#include <stdexcept>
#include <string>
using std::out_of_range;
using std::invalid_argument;
using std::to_string;

#include "ISO-8583-DTT.h"

namespace ISO_8583 {
namespace DTT {

class DTT_API_SCOPE Buffer {
private:
	static const int OFFSET;

	// Invariants: mark <= position <= limit <= capacity
	nat2		position_;
	nat2		limit_;
	nat2		capacity_;
	nat2		mark_;
	char*		buffer_;
	bool		owned_;


	// Creates a new buffer with the given mark, position, limit, and capacity,
	// after checking invariants.
	//
	//	Buffer(int mark, int pos, int lim, int cap) {       // package-private
	//		if (cap < 0)
	//			throw new IllegalArgumentException("Negative capacity: " + cap);
	//		this.capacity_ = cap;
	//		limit(lim);
	//		position(pos);
	//		if (mark >= 0) {
	//			if (mark > pos)
	//				throw new IllegalArgumentException(
	//						"mark > position: (" + mark + " > " + pos + ")");
	//			this.mark_ = mark;
	//		}
	//	}
public:
	nat2& position() 						{ return position_;	}
	nat2& limit() 							{ return limit_;	}
//	nat2& mark() 							{ return mark_;	}
private:
	const nat2&		mark() const			{ return mark_; }

public:
	const nat2&		capacity() const		{ return capacity_; }
	const nat2&		position() const		{ return position_; }
	const nat2&		limit() const			{ return limit_; }

public:
	Buffer(int length);
	Buffer(char* buffer, int length);
	virtual ~Buffer();

	void use(char* buffer, int length);
	void take(char* buffer, int length);

	int		remaining() const		{ return limit_ - position_; }
	bool	hasRemaining() const	{ return position_ < limit_; }
	int		position(int position)	{ return position_ = position; }

private:
	Buffer& newPosition(int newPosition) {
		if ((newPosition > limit()) || (newPosition < 0))
			throw invalid_argument(to_string(newPosition));
		position_ = newPosition;
		if (mark() > position()) mark_ = -1;
		return *this;
	}

	Buffer& newLimit(int newLimit) {
		if ((newLimit > capacity()) || (newLimit < 0))
			throw invalid_argument(to_string(newLimit));
		limit_ = newLimit;
		if (position() > limit()) position_ = limit();
		if (mark() > limit()) mark_ = -1;
		return *this;
	}

public:
	Buffer& markit() {
		mark_ = position();
		return *this;
	}
	Buffer& reset() {
		int m = mark_;
		if (m < 0)
			throw invalid_argument("");
		position_ = m;
		return *this;
	}
	Buffer& clear() {
		position_ = 0;
		limit_ = capacity_;
		mark_ = -1;
		return *this;
	}
	Buffer& flip() {
		limit_ = position_;
		position_ = 0;
		mark_ = -1;
		return *this;
	}
	Buffer& rewind() {
		position_ = 0;
		mark_ = -1;
		return *this;
	}
	Buffer& shrink(int size) {
		if (size > remaining())
			throw invalid_argument(to_string(size));
		limit_ = position_ + size;
		return *this;
	}
	Buffer& skip(int size) {
		return newPosition(position_ + size);
	}

	
private:
	void truncate() { 
        mark_ = -1;
        position_ = 0;
        limit_ = 0;
        capacity_ = 0;
    }
public:
#if 0
	void* operator new(size_t size, unsigned short length) {
		return new char[size + length];
	}
	void operator delete(void* where, unsigned short length) {
		delete where;
	}
	void operator delete(void* where) {
		delete where;
	}

	inline char* data() const { return ((char*)this) + OFFSET + position(); }
	inline byte* here() const { return ((byte*)this) + OFFSET + position(); }
	inline byte* here(int position) const { return ((byte*)this) + OFFSET + position; }
#endif

	inline const char* data() const			{ return ((char*)buffer_) + position(); }
	inline byte at(int no) const			{ return *(buffer_ + position() + no); }
	inline byte operator[](int no) const	{ return *(buffer_ + position() + no); }
	string str(int length) const			{ return string(data(), length); }

	void			dump(Functor& functor) const;
	const string	toString() const;

private:
	Buffer();
	Buffer(const Buffer&);
	Buffer& operator = (const Buffer&);


protected:
	inline byte* buffer(int position = 0)		{ return ((byte*)buffer_) + position; }
	inline byte* here() 						{ return ((byte*)buffer_) + position(); }

	int checkByteIndex(nat2 index) {
		if (!(0 <= index && index <= limit() - sizeof(byte)))
			throw out_of_range(to_string(index));
		return index;
	}
	int checkShortIndex(nat2 index) {
		if (!(0 <= index && index <= limit() - sizeof(nat2)))
			throw out_of_range(to_string(index));
		return index;
	}
	int checkIntIndex(nat2 index) {
		if (!(0 <= index && index <= limit() - sizeof(nat4)))
			throw out_of_range(to_string(index));
		return index;
	}
	void discardMark() {
        mark_ = -1;
    }

};

}
}

#endif
