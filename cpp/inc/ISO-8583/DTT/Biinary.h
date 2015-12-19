#ifndef BINARY_H_
#define BINARY_H_

#include "ISO-8583-DTT.h"
#include "ISO-8583/DTT/Bytes.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		class DTT_API_SCOPE Binary : public Bytes < sizeb, 0 > {
		public:
			explicit Binary() {
			}
			virtual ~Binary() {}
		};
	}
}

#endif // !BINARY_H_
